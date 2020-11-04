#pragma once

#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <memory>
#include <QCryptographicHash>

class Connexion: public QWidget
{
    Q_OBJECT

    private:
        QLineEdit *_identifier;
        QLineEdit *_password;
        QPushButton *_connexion_button;
    public:
        Connexion();

     public slots:
        void display_interface_similator();
};

