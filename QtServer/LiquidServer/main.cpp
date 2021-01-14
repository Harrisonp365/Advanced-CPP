#include <QApplication>

#include "LQDServer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(LQDServer::tr("Liquid Server"));
    LQDServer server;
    server.show();
    return app.exec();
}
