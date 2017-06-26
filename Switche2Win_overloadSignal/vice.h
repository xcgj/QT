#ifndef VICE_H
#define VICE_H

#include <QWidget>
#include <QPushButton>
#include <QString>

class Vice : public QWidget
{
    Q_OBJECT
public:
    explicit Vice(QWidget *parent = 0);

private:
    QPushButton p2;

signals:
    //信号重载
    void ViceSignal();
    void ViceSignal(int, QString);

public slots:
    void signal();
};

#endif // VICE_H
