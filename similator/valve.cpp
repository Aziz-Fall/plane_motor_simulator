#include "valve.h"

using namespace std;

Valve::Valve()
{

}

Valve::Valve(std::shared_ptr<Tank> tank1, std::shared_ptr<Tank> tank2, bool state, QString name): _state(state)
{
    setName(name);
    _tank1 = tank1;
    _tank2 = tank2;
    _valve_button = new QPushButton(_name);
    connect(_valve_button, SIGNAL(clicked()), this, SLOT(enable_disable()));
}

Valve::~Valve()
{
    _tank1 = nullptr;
    _tank2 = nullptr;
   cout << "Destructor Valve" << endl;
}

void Valve::setName(const QString name)
{
    if( name.length() < 1 || name.isEmpty() )
    {
        cout << "The name must not be null or empty :(" << endl;
        _name = "unknow";
    }
    else
        _name = name;
}
void Valve::setValveState(const QString valve_state)
{
    _valve_state.append(valve_state);
}
void Valve::setState(const bool state) { _state = state; }
void Valve::setTank1(std::shared_ptr<Tank> tank1){ _tank1 = move(tank1);}
void Valve::setTank2(std::shared_ptr<Tank> tank2){ _tank2 = move(tank2);}
bool Valve::getState() const {return _state;}
QString Valve::getName() const {return _name;}
QString Valve::getValveState() const { return _valve_state;}
Tank *Valve::getTank1() const { return _tank1.get();}
Tank *Valve::getTank2() const { return _tank2.get();}
QPushButton *Valve::getValveButton() const{return _valve_button;}

std::ostream &operator<<(std::ostream & os, const Valve & valve)
{
    return os << "***************Valve************" << endl
              << "--*Name: " << valve.getName().toStdString() << endl
              << "--*State: " << valve.getState() << endl
              << *(valve.getTank1()) << endl
              << *(valve.getTank2());
}

//Slots
void Valve::draining(QTextEdit & system_state)
{
    int field1(_tank1->getQuantityField()),
        field2(_tank2->getQuantityField());
    if ( _valve_button->text().contains('T') and _tank1->getPump()->getPumpButton()->isEnabled() and _tank2->getPump()->getPumpButton()->isEnabled() )
    {    
        system_state.append( ">>> Opening valve " +  _name + " to equilibre field between " + _tank1->getTankName() + " and " + _tank2->getTankName());

        cout << "In vt" << endl;
        if(field1 > field2)
        {
            for(int i(field2); i <= field1; i++)
            {
                _tank2->getFieldProgressBar()->setValue(i);
                _tank1->getFieldProgressBar()->setValue(field1--);
                QThread::sleep(1);
            }
            system_state.append(">>> Closing valve " + _name);
        }
        else if( field1 < field2)
        {
            for(int i(field1); i <= field2; i++)
            {
                _tank1->getFieldProgressBar()->setValue(i);
                _tank2->getFieldProgressBar()->setValue(field2--);
                QThread::sleep(1);
            }
            system_state.append(">>> Closing valve " + _name);
        }
    }
    else
    {
        cout << "In V" << endl;
        //if pump1 is operative and running
        if( _tank1->getPump()->getOperative() and _tank1->getPump()->getState() and !_tank2->getPump()->getPumpButton()->isEnabled() and _state)
        {
            cout << "draining tank 2" << endl;
            system_state.append(">>> Opening valve " +  _name + " draining field between " + _tank2->getTankName() + " and " + _tank1->getTankName());
           //draining tank2 to tank1
           while( field2 >= 0 and field1 <= 100)
           {
                _tank1->getFieldProgressBar()->setValue(field1++);
                _tank2->getFieldProgressBar()->setValue(field2--);
                QThread::sleep(1);
           }
           _tank1->getPump()->setState(false);
           system_state.append(">>> " + _tank1->getPump()->getName() + " stoppes");
           system_state.append(">>> Closing valve " + _name);
           cout << "V no break down" << endl;
           //valve_state += "closing valve " + _name.toStdString();
        }
        else if ( _tank2->getPump()->getOperative() and _tank2->getPump()->getState() and !_tank1->getPump()->getPumpButton()->isEnabled() and _state)
        {
            cout << "draining tank 1" << endl;
            system_state.append(">>> Opening valve " +  _name + " draining field between " + _tank1->getTankName() + " and " + _tank2->getTankName());
            //draining tank1 to tank2
            while( field1 >= 0 and field2 <= 100 )
            {
                 _tank2->getFieldProgressBar()->setValue(field2++);
                 _tank1->getFieldProgressBar()->setValue(field1--);
                 QThread::sleep(1);
            }
           _tank2->getPump()->setState(false);
           system_state.append(">>> " + _tank1->getPump()->getName() + " stoppes");
           system_state.append(">>> Closing valve " + _name);
        }
    }
}

void Valve::enable_disable()
{
    if( _state )
    {
        _state = false;
        cout << "valve " << _name.toStdString() << " is actived " << endl;
    }
    else
    {
        _state = true;
        cout << "valve " << _name.toStdString() << " is actived " << endl;
    }
}
