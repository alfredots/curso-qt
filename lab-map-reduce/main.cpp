#include <QCoreApplication>
#include <QVector>
#include <QtConcurrent/QtConcurrentMap>


int map(const int &x) {
    return x;
}

void reduce(int &result, const int &partial) {
    qDebug() << "resultado parcial: " << result;
    result += partial;
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QVector<int> vector{1,2,3,4,5,6,7,8,9,10};


    auto future = QtConcurrent::mappedReduced(vector, map, reduce);
    qDebug() << "resultado final: " << future.result();

    return 0;
}
