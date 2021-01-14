#ifndef LQDSERVER_H
#define LQDSERVER_H

#include <QDialog>

class QLabel;
class QPushButton;
class QLocalServer;

class LQDServer : public QDialog
{
    Q_OBJECT
public:
    explicit LQDServer(QWidget *parent = nullptr);

private slots:
    void sendData();

private:
    QLocalServer *mServer;
    QStringList mMessages;
};

#endif //LQDSERVER_H
