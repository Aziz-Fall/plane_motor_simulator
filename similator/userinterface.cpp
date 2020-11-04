#include "userinterface.h"

using namespace std;

UserInterface::UserInterface(): QWidget()
{
    setFixedSize(800, 400);
    QHBoxLayout *main_layout = new QHBoxLayout(this);
    QVBoxLayout *command_layout = new QVBoxLayout(this);
    QHBoxLayout *state_layout = new QHBoxLayout();

    _init_properties();
    _init_interface_one();
    _init_interface_two();

    command_layout->addLayout(_layout1);
    command_layout->addLayout(_layout2);

    state_layout->addWidget(system_state);

    main_layout->addLayout(command_layout);
    main_layout->addLayout(state_layout);

    setLayout(main_layout);

    QObject::connect(_vt12->getValveButton(), SIGNAL(clicked()), this, SLOT(update_vt12_state()));
    QObject::connect(_vt23->getValveButton(), SIGNAL(clicked()), this, SLOT(update_vt23_state()));
    QObject::connect(_v12->getValveButton(), SIGNAL(clicked()), this, SLOT(update_v12_state()));
    QObject::connect(_v13->getValveButton(), SIGNAL(clicked()), this, SLOT(update_v13_state()));
    QObject::connect(_v23->getValveButton(), SIGNAL(clicked()), this, SLOT(update_v23_state()));
    QObject::connect(_tank1->getPump()->getBreakDownButton(), SIGNAL(clicked()), this, SLOT(break_pump_tank1()));
    QObject::connect(_tank2->getPump()->getBreakDownButton(), SIGNAL(clicked()), this, SLOT(break_pump_tank2()));
    QObject::connect(_tank3->getPump()->getBreakDownButton(), SIGNAL(clicked()), this, SLOT(break_pump_tank3()));
    QObject::connect(_tank1->getDrainageButton(), SIGNAL(clicked()), this, SLOT(draining_tank1()));
    QObject::connect(_tank2->getDrainageButton(), SIGNAL(clicked()), this, SLOT(draining_tank2()));
    QObject::connect(_tank3->getDrainageButton(), SIGNAL(clicked()), this, SLOT(draining_tank3()));
    QObject::connect(_tank1->getPump()->getPumpButton(), SIGNAL(clicked()), this, SLOT(pump1_starting()));
    QObject::connect(_tank2->getPump()->getPumpButton(), SIGNAL(clicked()), this, SLOT(pump2_starting()));
    QObject::connect(_tank3->getPump()->getPumpButton(), SIGNAL(clicked()), this, SLOT(pump3_starting()));
}
void UserInterface::_init_properties()
{
    _tank1 = make_shared<Tank>(true, "Tank1", 20, make_unique<Pump>(1, false, true, "P12"));
    _tank2 = make_shared<Tank>(true, "Tank2", 50, make_unique<Pump>(2, false, true, "P22"));
    _tank3 = make_shared<Tank>(true, "Tank3", 60, make_unique<Pump>(3, false, true, "P32"));

    _tank1->getFieldProgressBar()->setOrientation(Qt::Vertical);
    _tank2->getFieldProgressBar()->setOrientation(Qt::Vertical);
    _tank3->getFieldProgressBar()->setOrientation(Qt::Vertical);

    _tank1->getFieldProgressBar()->setFixedWidth(100);
    _tank2->getFieldProgressBar()->setFixedWidth(100);
    _tank3->getFieldProgressBar()->setFixedWidth(100);

    _vt12 = new Valve(_tank1, _tank2, false, "VT12");
    _vt23 = new Valve(_tank2, _tank3, false, "VT23");
    _v12 = new Valve(_tank1, _tank2, false, "V12");
    _v23 = new Valve(_tank2, _tank3, false, "V23");
    _v13 = new Valve(_tank1, _tank3, false, "V13");

    system_state = new QTextEdit();
    system_state->setEnabled(false);
    system_state->setTextColor(QColor("#61D800"));
    _layout1 = new QVBoxLayout(this);
    _layout2 = new QVBoxLayout(this);
}

void UserInterface::_init_interface_one()
{
    //Init layout for all buttons
    QHBoxLayout *tmp_valve_layout = new QHBoxLayout();
    QHBoxLayout *secondary_pump_layout = new QHBoxLayout();
    QHBoxLayout *valve_layout = new QHBoxLayout();

    //Add button valve in the tmp layout
    tmp_valve_layout->addWidget(_vt12->getValveButton());
    tmp_valve_layout->addWidget(_vt23->getValveButton());

    //Add button secondary pump in the tmp layout
    secondary_pump_layout->addWidget(_tank1->getPump()->getPumpButton());
    secondary_pump_layout->addWidget(_tank2->getPump()->getPumpButton());
    secondary_pump_layout->addWidget(_tank3->getPump()->getPumpButton());

    //Add button valve in the tmp layout
    valve_layout->addWidget(_v12->getValveButton());
    valve_layout->addWidget(_v23->getValveButton());
    valve_layout->addWidget(_v13->getValveButton());

    //Add all Layout in the layout2.
    _layout1->addLayout(tmp_valve_layout);
    _layout1->addLayout(secondary_pump_layout);
    _layout1->addLayout(valve_layout);
}

void UserInterface::_init_interface_two()
{
    //Init layout
    QHBoxLayout *tank_layout = new QHBoxLayout();
    QVBoxLayout *tank1_layout = new QVBoxLayout();
    QVBoxLayout *tank2_layout = new QVBoxLayout();
    QVBoxLayout *tank3_layout = new QVBoxLayout();

    //Add layout of each tank features in specific layout
    tank1_layout->addWidget(_tank1->getFieldProgressBar());
    tank1_layout->addWidget(_tank1->getDrainageButton());
    tank1_layout->addWidget(_tank1->getPump()->getBreakDownButton());

    tank2_layout->addWidget(_tank2->getFieldProgressBar());
    tank2_layout->addWidget(_tank2->getDrainageButton());
    tank2_layout->addWidget(_tank2->getPump()->getBreakDownButton());

    tank3_layout->addWidget(_tank3->getFieldProgressBar());
    tank3_layout->addWidget(_tank3->getDrainageButton());
    tank3_layout->addWidget(_tank3->getPump()->getBreakDownButton());

    //Add all specific layout in their main layout.
    tank_layout->addLayout(tank1_layout);
    tank_layout->addLayout(tank2_layout);
    tank_layout->addLayout(tank3_layout);

    //Add main layout tank and state widget to the layout2.
    _layout2->addLayout(tank_layout);
}

UserInterface::~UserInterface()
{
    _tank1->~Tank();
    _tank2->~Tank();
}

void UserInterface::update_vt12_state()
{
    _vt12->draining(*system_state);
}

void UserInterface::update_vt23_state()
{
    _vt23->draining(*system_state);
}

void UserInterface::update_v13_state()
{
    _v13->draining(*system_state);
}

void UserInterface::update_v23_state()
{
    _v23->draining(*system_state);
}

void UserInterface::update_v12_state()
{
    _v12->draining(*system_state);
}

void UserInterface::break_pump_tank1()
{
    _tank1->getPump()->disable_break_down_button(*system_state);
}

void UserInterface::break_pump_tank2()
{
    _tank2->getPump()->disable_break_down_button(*system_state);
}

void UserInterface::break_pump_tank3()
{
    _tank3->getPump()->disable_break_down_button(*system_state);
}

void UserInterface::draining_tank1()
{
    _tank1->emptyTheTank(*system_state);
}

void UserInterface::draining_tank2()
{
    _tank2->emptyTheTank(*system_state);
}

void UserInterface::draining_tank3()
{
    _tank3->emptyTheTank(*system_state);
}

void UserInterface::pump1_starting()
{
    _tank1->getPump()->start_pump(*system_state);
}

void UserInterface::pump2_starting()
{
    _tank2->getPump()->start_pump(*system_state);
}

void UserInterface::pump3_starting()
{
    _tank3->getPump()->start_pump(*system_state);
}


