#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QWidget>

#include "valve.h"

class UserInterface: public QWidget
{
    Q_OBJECT

    public:
        UserInterface();
        ~UserInterface();
    private:
        std::shared_ptr<Tank> _tank1;
        std::shared_ptr<Tank> _tank2;
        std::shared_ptr<Tank> _tank3;
        Valve *_vt12;
        Valve *_vt23;
        Valve *_v12;
        Valve *_v23;
        Valve *_v13;
        QVBoxLayout *_layout1;
        QVBoxLayout *_layout2;
        QTextEdit *system_state;
        void _init_interface_one();
        void _init_interface_two();
        void _init_properties();

     public slots:
        void update_vt12_state();
        void update_vt23_state();
        void update_v12_state();
        void update_v13_state();
        void update_v23_state();
        void break_pump_tank1();
        void break_pump_tank2();
        void break_pump_tank3();
        void draining_tank1();
        void draining_tank2();
        void draining_tank3();
        void pump1_starting();
        void pump2_starting();
        void pump3_starting();
};

#endif // USERINTERFACE_H
