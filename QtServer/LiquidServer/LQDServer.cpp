#include "LQDServer.h"

#include <QtWidgets>
#include <QtNetwork>

LQDServer::LQDServer(QWidget *parent) : QDialog(parent)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    mServer = new QLocalServer(this);
    if (!mServer->listen("liquid")) {
        QMessageBox::critical(this, tr("Liquid Server"),tr("Unable to start the server: %1.").arg(mServer->errorString()));
        close();
        return;
    }

    QLabel *statusLabel = new QLabel;
    statusLabel->setWordWrap(true);
    statusLabel->setText(tr("The server is running.\n"
                            "Run the Liquid Client now."));

    mMessages << tr("You've been leading a dog's life. Stay off the furniture.")
             << tr("You've got to think about tomorrow.")
             << tr("You will be surprised by a loud noise.")
             << tr("You will feel hungry again in another hour.")
             << tr("You might have mail.")
             << tr("You cannot kill time without injuring eternity.")
             << tr("Computers are not intelligent. They only think they are.");

    QPushButton *quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);
    connect(quitButton, &QPushButton::clicked, this, &LQDServer::close);
    connect(mServer, &QLocalServer::newConnection, this, &LQDServer::sendData);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);

    setWindowTitle(QGuiApplication::applicationDisplayName());
}

void LQDServer::sendData()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);
    const int fortuneIndex = QRandomGenerator::global()->bounded(0, mMessages.size());
    const QString &message = mMessages.at(fortuneIndex);
    out << quint32(message.size());
    out << message;

    QLocalSocket *clientConnection = mServer->nextPendingConnection();
    connect(clientConnection, &QLocalSocket::disconnected,
            clientConnection, &QLocalSocket::deleteLater);

    clientConnection->write(block);
    clientConnection->flush();
    clientConnection->disconnectFromServer();
}
