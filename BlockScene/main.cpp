#include "blockwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlockWindow w;
    w.show();
    
    return a.exec();
}
