#include "mycounter.h"

MyCounter::MyCounter(unsigned value, QObject *parent)
    : QObject {parent}, _value {value}
{
}

unsigned MyCounter::value() const
{
    return _value;
}

void MyCounter::setValue(unsigned value)
{
    if (_value != value) {
        _value = value;
        Q_EMIT valueChanged(_value);
    }
}

QDebug operator<<(QDebug dbg, const MyCounter &counter)
{
    dbg.nospace() << "MyCounter[" << counter._value << "]";
    return dbg;
}
