#ifndef VALVE_H
#define VALVE_H

#include <QTextEdit>
#include <SystemState.h>
#include "tank.h"
#include <iostream>
#include <string>

class Valve: public QObject
{
    Q_OBJECT

    public:
        Valve();
        Valve(std::shared_ptr<Tank> tank1, std::shared_ptr<Tank> tank2, bool state, QString name);
        ~Valve();
        void setState(const bool state);
        void setName(const QString name);
        void setTank1(std::shared_ptr<Tank> tank1);
        void setTank2(std::shared_ptr<Tank> tank2);
        void setValveState(const QString valve_state);
        bool getState() const;
        QString getValveState() const;
        QString getName() const;
        Tank *getTank1() const;
        Tank *getTank2() const;
        QPushButton *getValveButton() const;
        void draining(QTextEdit & system_state);
    public slots:
        void enable_disable();
    private:
        std::shared_ptr<Tank> _tank1;
        std::shared_ptr<Tank> _tank2;
        bool _state;
        QString _name;
        QString _valve_state;
        QPushButton *_valve_button;
};

std::ostream &operator<<(std::ostream & os, const Valve & valve);
#endif // VALVE_H
