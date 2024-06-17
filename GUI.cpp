#include <sstream>
#include "GUI.h"
#include <QPushButton>
using namespace std;
GUI::GUI(Service* service,QWidget* parent) : QWidget(parent), service{service} {
    this->resize(1200, 600);
    this->init_GUI();
    this->populate_list();
    this->connect_signals_and_slots();
}

void GUI::init_GUI() {
    QHBoxLayout *layout = new QHBoxLayout(this);
    QVBoxLayout *left = new QVBoxLayout();

    layout->addLayout(left);

    QHBoxLayout *buttons = new QHBoxLayout();
    this->AddButton = new QPushButton("Add movie");
    this->DeleteButton = new QPushButton("Delete movie");
    this->UpdateButton = new QPushButton("Update movie");
    this->ExitButton = new QPushButton("Exit");
    buttons->addWidget(this->AddButton);
    buttons->addWidget(this->DeleteButton);
    buttons->addWidget(this->UpdateButton);
    left->addLayout(buttons);

    this->listmovies = new QListWidget();

    layout->addWidget(this->listmovies);

    QFormLayout *right = new QFormLayout();
    this->TitleEdit = new QLineEdit();
    this->GenreEdit = new QLineEdit();
    this->LikesEdit = new QLineEdit();
    this->TrailerEdit = new QLineEdit();
    this->PositionEdit = new QLineEdit();
    right->addRow("&Title:", this->TitleEdit);
    right->addRow("&Genre:", this->GenreEdit);
    right->addRow("&Likes:", this->LikesEdit);
    right->addRow("&Trailer:", this->TrailerEdit);
    right->addRow("&Position:", this->PositionEdit);
    right->addWidget(this->ExitButton);
    left->addLayout(right);
}

void GUI::populate_list() {
        this->listmovies->clear();
    Movie* movies = this->service->get_all_movies();
    int number_of_movies = this->service->get_number_of_movies();
    for (int i = 0; i < number_of_movies; i++) {
        stringstream buffer;
        buffer << movies[i].get_movie_title() << " - " << movies[i].get_movie_genre() << " - " << movies[i].get_number_of_likes() << " - " << movies[i].get_movie_trailer();
        this->listmovies->addItem(QString::fromStdString(buffer.str()));
    }
    this->listmovies->setCurrentRow(0);
}
void GUI::connect_signals_and_slots() {
    QObject::connect(AddButton, &QPushButton::clicked, this, &GUI::add_movie);
    QObject::connect(DeleteButton, &QPushButton::clicked, this, &GUI::delete_movie);
    QObject::connect(UpdateButton, &QPushButton::clicked, this, &GUI::update_movie);
    QObject::connect(ExitButton, &QPushButton::clicked, this, &GUI::exit);

}
void GUI::add_movie() {
    string title = this->TitleEdit->text().toStdString();
    string genre = this->GenreEdit->text().toStdString();
    int likes = this->LikesEdit->text().toInt();
    string trailer = this->TrailerEdit->text().toStdString();
    this->service->add_movie_service(title, genre, likes, trailer);
    this->service->write_to_file("movies1.txt");
    this->populate_list();
}
void GUI::delete_movie() {
    int position = this->PositionEdit->text().toInt();
    this->service->delete_movie(position);
    this->service->write_to_file("movies1.txt");
    this->populate_list();
}
void GUI::update_movie() {
    string title = this->TitleEdit->text().toStdString();
    string genre = this->GenreEdit->text().toStdString();
    int likes = this->LikesEdit->text().toInt();
    string trailer = this->TrailerEdit->text().toStdString();
    int position = this->PositionEdit->text().toInt();
    this->service->update_movie_service(title, genre, likes, trailer, position);
    this->service->write_to_file("movies1.txt");
    this->populate_list();
}
void GUI::exit() {
    this->hide();
}


