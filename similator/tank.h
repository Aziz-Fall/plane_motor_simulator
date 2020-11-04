#ifndef TANK_H
#define TANK_H

#include <QProgressBar>
#include <QTextEdit>
#include <QThread>
#include <QObject>
#include "pump.h"

class Tank : public QObject
{
    Q_OBJECT

    public:
        Tank();
        ~Tank();
        Tank(bool state, QString tank_name, int quantity_field, std::unique_ptr<Pump> pump);
        bool getState() const;
        void setState(int state);
        int getQuantityField() const;
        void setQuantityField(int quantity_field);
        QString getTankName() const;
        void setTankName(QString tank_name);
        Pump *getPump() const;
        QProgressBar *getFieldProgressBar();
        QPushButton *getDrainageButton();

    public slots:
        void emptyTheTank(QTextEdit & system_state);
    private:
        bool _state;
        QString _tank_name;
        int _quantity_field;
        std::unique_ptr<Pump> _pump;
        std::unique_ptr<QProgressBar> _field_progress_bar;
        QPushButton *_drainage_button;

};

std::ostream &operator<<(std::ostream & os, const Tank & tank);
#endif // TANK_H
