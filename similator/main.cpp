#include <QApplication>
#include "userinterface.h"
#include "connexion.h"

using namespace std;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*UserInterface user_interface;
    user_interface.show();*/
    Connexion connexion;
    connexion.show();

    return app.exec();
}
