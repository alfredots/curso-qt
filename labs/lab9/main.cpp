#include <QtConcurrent/QtConcurrentMap>
#include <QVector>

int map(const int &x) {  // clazy:exclude=function-args-by-value
    return x;
}

void reduce(int &result, const int &partial) {  // clazy:exclude=function-args-by-value
    result += partial;
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QVector<int> vector {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto future = QtConcurrent::mappedReduced(vector, map, reduce);
    qDebug() << future.result();

    return 0;
}
