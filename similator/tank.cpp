#include "tank.h"

using namespace std;

Tank::Tank()
{

}

Tank::Tank(bool state, QString tank_name, int quantity_field, unique_ptr<Pump> pump): _state(state), _quantity_field(quantity_field)
{
    setTankName((tank_name));
    _pump = move(pump);
    _field_progress_bar = make_unique<QProgressBar>();
    _field_progress_bar->setMaximum(100);
    _field_progress_bar->setValue(_quantity_field);
    _field_progress_bar->setTextDirection(QProgressBar::BottomToTop);
    _drainage_button = new QPushButton("Draining");
}

bool Tank::getState() const { return _state; }

void Tank::setState(int state) { _state = state; }

int Tank::getQuantityField() const
{
    return _field_progress_bar->value();
}

void Tank::setQuantityField(int quantity_field)
{
   if( quantity_field > 100 )
       _quantity_field =  100;
   else if (quantity_field < 0 )
       _quantity_field = 0;
   else
       _quantity_field = quantity_field;
}

Pump *Tank::getPump() const {return _pump.get();}

QProgressBar *Tank::getFieldProgressBar() { return _field_progress_bar.get();}

QPushButton *Tank::getDrainageButton() {return _drainage_button ;}

QString Tank::getTankName() const{ return _tank_name;}

void Tank::setTankName(QString tank_name)
{
    if ( tank_name.isEmpty() or tank_name.length() < 1 )
    {
        cout << "Tank name must not be empty !" << endl;
        _tank_name = "unknow";
    }
    else
        _tank_name = tank_name;
}

Tank::~Tank()
{
    delete _drainage_button;
    cout << "Destructor Tank" << endl;
}
ostream &operator<<(ostream & os, const Tank & tank)
{
    return os << "-*Tank: " << endl
              << "--*Name: " << tank.getTankName().toStdString() << endl
              << "--*State: " << tank.getState() << endl
              << "--*Quantity field: " << tank.getQuantityField() << endl
              << *(tank.getPump());
}

//slot

void Tank::emptyTheTank(QTextEdit & system_state)
{
    system_state.append(">>> " + _tank_name + " draining");
    _drainage_button->setEnabled(false);
    while( _quantity_field > 0 )
    {
            _field_progress_bar->setValue(_quantity_field--);
            QThread::sleep(1);
    }
    _quantity_field = 0;
}

