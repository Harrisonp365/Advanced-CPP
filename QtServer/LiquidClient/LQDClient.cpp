#include <QtWidgets>
#include <QtNetwork>

#include "LQDClient.h"

LQDClient::LQDClient(QWidget *parent)
    : QDialog(parent),
      mHostEdit(new QLineEdit("liquid")),
      mConnectBtn(new QPushButton(tr("Connect to Liquid Server"))),
      mStatusLabel(new QLabel(tr("Ensure the Liquid Server is running."))),
      mTcpSocket(new QLocalSocket(this))
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QLabel *hostLabel = new QLabel(tr("&Server name:"));
    hostLabel->setBuddy(mHostEdit);

    mStatusLabel->setWordWrap(true);

    mConnectBtn->setDefault(true);
    QPushButton *quitButton = new QPushButton(tr("Quit"));

    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(mConnectBtn, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    mDataIn.setDevice(mTcpSocket);
    mDataIn.setVersion(QDataStream::Qt_5_10);

    connect(mHostEdit, &QLineEdit::textChanged,this, &LQDClient::enableButton);
    connect(mConnectBtn, &QPushButton::clicked,this, &LQDClient::connectToServer);
    connect(quitButton, &QPushButton::clicked, this, &LQDClient::close);
    connect(mTcpSocket, &QLocalSocket::readyRead, this, &LQDClient::receiveFromServer);
    connect(mTcpSocket, &QLocalSocket::errorOccurred, this, &LQDClient::displayError);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(mHostEdit, 0, 1);
    mainLayout->addWidget(mStatusLabel, 2, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);

    setWindowTitle(QGuiApplication::applicationDisplayName());
    mHostEdit->setFocus();
}

void LQDClient::connectToServer()
{
    mConnectBtn->setEnabled(false);
    mBlockSize = 0;
    mTcpSocket->abort();
    mTcpSocket->connectToServer(mHostEdit->text());
}

void LQDClient::receiveFromServer()
{
    if (mBlockSize == 0) {
        // Relies on the fact that QDataStream serializes a quint32 into
        // sizeof(quint32) bytes
        if (mTcpSocket->bytesAvailable() < (int)sizeof(quint32))
            return;
        mDataIn >> mBlockSize;
    }

    if (mTcpSocket->bytesAvailable() < mBlockSize || mDataIn.atEnd())
        return;

    QString serverData;
    mDataIn >> serverData;

    if (serverData == mState) {
        QTimer::singleShot(0, this, &LQDClient::connectToServer);
        return;
    }

    mState = serverData;
    mStatusLabel->setText(mState);
    mConnectBtn->setEnabled(true);
}

void LQDClient::displayError(QLocalSocket::LocalSocketError socketError)
{
    switch (socketError) {
    case QLocalSocket::ServerNotFoundError:
        QMessageBox::information(this, tr("Local Liquid Client"),
                                 tr("The host was not found. Please make sure "
                                    "that the server is running and that the "
                                    "server name is correct."));
        break;
    case QLocalSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Local Liquid Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the liquid server is running, "
                                    "and check that the server name "
                                    "is correct."));
        break;
    case QLocalSocket::PeerClosedError:
        break;
    default:
        QMessageBox::information(this, tr("Local Liquid Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(mTcpSocket->errorString()));
    }

    mConnectBtn->setEnabled(true);
}

void LQDClient::enableButton()
{
    mConnectBtn->setEnabled(!mHostEdit->text().isEmpty());
}
