#include "eventmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    eventManager::EventManager w;
    w.show();

    return app.exec();
}

