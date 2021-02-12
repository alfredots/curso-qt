#ifndef MYCOUNTER_H
#define MYCOUNTER_H

#include <QDebug>
#include <QObject>

class MyCounter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(unsigned value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit MyCounter(unsigned value = 0, QObject *parent = nullptr);

    unsigned value() const;
    friend QDebug operator<<(QDebug dbg, const MyCounter &counter);

public Q_SLOTS:
    void setValue(unsigned value);

signals:
    void valueChanged(unsigned value);

private:
    unsigned _value;
};

#endif // MYCOUNTER_H
