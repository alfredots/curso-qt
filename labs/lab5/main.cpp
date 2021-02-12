#include <QDebug>
#include <QMetaProperty>

#include "mycounter.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    // Create and initialize counters
    MyCounter counter1 {};
    MyCounter counter2 {10};
    qDebug() << counter1;
    qDebug() << counter2;

    // Create connections
    QObject::connect(&counter1, &MyCounter::valueChanged, &counter2, &MyCounter::setValue);

    // Change counter1 value => counter2 value changes
    counter1.setValue(12);
    qDebug() << counter1;
    qDebug() << counter2;

    // Change counter2 value => counter1 value *does not* change
    counter2.setValue(24);
    qDebug() << counter1;
    qDebug() << counter2;

    // Using Qt's property system
    qDebug() << "Counter1 value:" << counter1.property("value").toUInt();
    const auto *metaObject = counter1.metaObject();
    qDebug() << QStringLiteral("Listing %1 properties:").arg(metaObject->propertyCount());
    for (int i = 0; i < metaObject->propertyCount(); ++i) {
        qDebug() << metaObject->property(i).name();
    }

    return 0;
}
