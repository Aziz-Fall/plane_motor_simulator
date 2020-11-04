#include "pump.h"

using namespace std;

Pump::Pump(): _num_tank(0), _state(false), _operative(true), _name("Unknown"), _break_down_button(nullptr)
{

}

Pump::Pump(int num_tank, bool state, bool operative, QString name): _num_tank(num_tank), _state(state), _operative(operative), _name(name)
{
    _break_down_button = make_unique<QPushButton>("B_" + _name);
    _pump_button = make_unique<QPushButton>(_name);
}

void Pump::setState(bool state)
{
    _state = state;
}

bool Pump::getState() const
{
    return _state;
}

void Pump::setNumTank(int num_tank)
{
    _num_tank = num_tank;
}

int Pump::getNumTank() const
{
    return _num_tank;
}

bool Pump::getOperative() const
{
    return _operative;
}

void Pump::setName(QString name)
{
    if (name.length() <= 1 || name.isEmpty())
        cout << "The length must not be empty." << endl;
    else
        _name = name;
}

QString Pump::getName() const
{
    return _name;
}

void Pump::setOperative(bool operative)
{
    _operative = operative;
}

QPushButton *Pump::getBreakDownButton()
{
    return _break_down_button.get();
}

QPushButton *Pump::getPumpButton() {return _pump_button.get(); }

Pump::~Pump()
{
    cout << "Destructor Pump" << endl;
}

ostream &operator<<(ostream & os, const Pump & pump)
{
    return os << "-*Pump: " << endl
              << "--*Name: " << pump.getName().toStdString() << endl
              << "--*State: " << pump.getState() << endl
              << "--*Operative: " << pump.getOperative() << endl
              << "--*Num tank: " << pump.getNumTank();
}


//Slots

void Pump::disable_break_down_button(QTextEdit & system_state)
{
    _pump_button->setEnabled(false);
    _operative = false;
    _state = false;
    system_state.append(">>> Pump " +_name + " is not operative.");
}

void Pump::start_pump(QTextEdit & system_state)
{
    system_state.append(">>> " + _name + " starting");
    cout << ">>> Pump up" << endl;
    _operative = true;
    _state = true;
    cout << ">>> Pump " << _name.toStdString() << " is actived" << endl;
}





