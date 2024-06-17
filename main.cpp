#include <QApplication>
#include <QPushButton>
#include "GUI.h"
#include "UserGui.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Admin mode");
    QPushButton button2("User mode");
    QPushButton button3("Exit");
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(&button);
    layout->addWidget(&button2);
    layout->addWidget(&button3);
    Service* service=new Service{};
    GUI gui(service);
    UserGui usergui(service);
    QObject::connect(&button, &QPushButton::clicked, [&gui, &service]() {
        gui.populate_list();
        gui.show();
    });
    QObject::connect(&button2, &QPushButton::clicked, [&usergui,&service]() {
        usergui.populate_list();
        usergui.show();
    });
    QObject::connect(&button3, &QPushButton::clicked, [&a]() {
        a.exit(0);
    });
    QWidget window;
    window.resize(300, 100);
    window.setLayout(layout);
    window.show();
    return a.exec();
}
