#pragma once
#include "Service.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QFormLayout>
class GUI:public QWidget {
    Q_OBJECT
private:
    Service* service;
    QListWidget* listmovies;
    QPushButton* AddButton;
    QPushButton* DeleteButton;
    QPushButton* UpdateButton;
    QPushButton* ExitButton;
    QLineEdit* TitleEdit;
    QLineEdit* GenreEdit;
    QLineEdit* LikesEdit;
    QLineEdit* TrailerEdit;
    QLineEdit* PositionEdit;

public:
    GUI(Service* service,QWidget* parent = 0);
    void init_GUI();
    void populate_list();
    void connect_signals_and_slots();
    void add_movie();
    void delete_movie();
    void update_movie();
    void exit();
};


