#ifndef LQDCLIENT_H
#define LQDCLIENT_H

#include <QDialog>
#include <QDataStream>
#include <QLocalSocket>

class QLabel;
class QLineEdit;
class QPushButton;

class LQDClient : public QDialog
{
    Q_OBJECT
public:
    explicit LQDClient(QWidget *parent = nullptr);

private slots:
    void connectToServer();
    void receiveFromServer();
    void displayError(QLocalSocket::LocalSocketError socketError);
    void enableButton();

private:
    QLineEdit *mHostEdit;
    QPushButton *mConnectBtn;
    QLabel *mStatusLabel;
    QLocalSocket *mTcpSocket;
    QDataStream mDataIn;
    quint32 mBlockSize;
    QString mState;
};
#endif //LQDCLIENT_H
