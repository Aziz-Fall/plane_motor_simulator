#ifndef PUMP_H
#define PUMP_H

#include <QPushButton>
#include <QTextEdit>
#include <QObject>
#include <memory>
#include <iostream>

class Pump: public QObject
{
    Q_OBJECT

    public:
        Pump();
        ~Pump();
        Pump(int num_tank, bool state, bool operative, QString name);
        void setState(bool state);
        bool getState() const;
        void setNumTank(int num_tank);
        int getNumTank() const;
        bool getOperative() const;
        QPushButton *getBreakDownButton();
        QPushButton *getPumpButton();
        void setOperative(bool operative);
        void setName(QString name);
        QString getName() const;
        void disable_break_down_button(QTextEdit & system_state);
    public slots:
        void start_pump(QTextEdit & system_state);

    private:
        int _num_tank;
        bool _state;
        bool _operative;
        QString _name;
        std::unique_ptr<QPushButton> _break_down_button;
        std::unique_ptr<QPushButton> _pump_button;

};

std::ostream &operator<<(std::ostream &os, const Pump & pump);

#endif // PUMP_H
