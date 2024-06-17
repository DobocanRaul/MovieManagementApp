#pragma once
#include "Service.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
class UserGui:public QWidget {
    Q_OBJECT
private:
    Service* service;
    QListWidget* listmovies;
    QListWidget* watchlist;
    QPushButton* AddButton;
    QPushButton* DeleteButton;
    QPushButton* ExitButton;
    QPushButton* OpenButton;
    QLineEdit* GenreEdit;
    QLineEdit* PositionEdit;
public:
    UserGui(Service* service,QWidget* parent = 0);
    void init_GUI();
    void populate_list();
    void connect_signals_and_slots();
    void add_movie_to_watchlist();
    void delete_movie_from_watchlist();
    void open_watchlist();
    void exit();
};