#include <QApplication>

#include "LQDClient.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(LQDClient::tr("Liquid Client"));
    LQDClient client;
    client.show();
    return app.exec();
}
