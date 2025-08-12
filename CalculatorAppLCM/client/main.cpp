#include <QApplication>
#include "UI/MainWindow.h"
#include "../LCM/client.hpp"

int main(int argc, char *argv[]) {
    startLCMListener(); 

    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}