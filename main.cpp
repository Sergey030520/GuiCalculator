#include <QApplication>
#include "./ui_caller.h"
#include "CallerMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CallerMainWindow win(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&win);
    win.lineEdit = caller.lineEdit;
    win.resize(500, 750);
    win.show();
    return QApplication::exec();
}
