#include "connexion.h"
#include "userinterface.h"

using namespace std;

Connexion::Connexion()
{
    setFixedSize(400, 100);

    _identifier = new QLineEdit;
    _password = new QLineEdit;
    _connexion_button = new QPushButton;
    _connexion_button->setText("Connexion");

    _password->setEchoMode(QLineEdit::Password);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("ID", _identifier);
    formLayout->addRow("Password", _password);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(_connexion_button);
    setLayout(mainLayout);

    connect(_connexion_button, SIGNAL(clicked()), this, SLOT(display_interface_similator()));
}

void Connexion::display_interface_similator()
{
    QByteArray valid_password = QCryptographicHash::hash(QByteArray("WelcomeBack"), QCryptographicHash::Sha256);
    QByteArray user_password =QCryptographicHash::hash(_password->text().toUtf8(), QCryptographicHash::Sha256);

    if( valid_password == user_password)
    {
        UserInterface *user = new UserInterface;
        user->show();
    }
    else
    {
        QMessageBox::warning(this, "Password", " Password incorrect ! ");
    }
}
