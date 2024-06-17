#include <QVBoxLayout>
#include <QHBoxLayout>
#include "UserGui.h"
#include <QFormLayout>
#include <sstream>
#include <stdlib.h>
#include <fstream>
UserGui::UserGui(Service* service,QWidget* parent) : QWidget(parent), service{service} {
    this->resize(1200, 600);
    this->init_GUI();
    this->populate_list();
    this->connect_signals_and_slots();
}
void UserGui::exit() {
    this->hide();
}

void UserGui::init_GUI() {
    QHBoxLayout *layout = new QHBoxLayout(this);
    QVBoxLayout *left = new QVBoxLayout();
    this->listmovies = new QListWidget();
    this->watchlist = new QListWidget();
    layout->addLayout(left);
    layout->addWidget(this->listmovies);
    layout->addWidget(this->watchlist);

    QHBoxLayout *buttons = new QHBoxLayout();
    this->AddButton = new QPushButton("Add movie");
    this->DeleteButton = new QPushButton("Delete movie");
    this->ExitButton = new QPushButton("Exit");
    this->OpenButton = new QPushButton("Open watchlist");
    buttons->addWidget(this->AddButton);
    buttons->addWidget(this->DeleteButton);
    buttons->addWidget(this->OpenButton);
    left->addLayout(buttons);

    QFormLayout *right = new QFormLayout();
    this->GenreEdit = new QLineEdit();
    this->PositionEdit = new QLineEdit();
    right->addRow("&Genre:", this->GenreEdit);
    right->addRow("&Position:", this->PositionEdit);
    right->addWidget(this->ExitButton);
    left->addLayout(right);
}
void UserGui::connect_signals_and_slots() {
    QObject::connect(AddButton, &QPushButton::clicked, this, &UserGui::add_movie_to_watchlist);
    QObject::connect(DeleteButton, &QPushButton::clicked, this, &UserGui::delete_movie_from_watchlist);
    QObject::connect(ExitButton, &QPushButton::clicked, this, &UserGui::exit);
    QObject::connect(OpenButton, &QPushButton::clicked, this, &UserGui::open_watchlist);
}
void UserGui::populate_list() {
    this->listmovies->clear();
    Movie* movies = this->service->get_all_movies();
    int number_of_movies = this->service->get_number_of_movies();
    for (int i = 0; i < number_of_movies; i++) {
        stringstream buffer;
        buffer << movies[i].get_movie_title() << " " << movies[i].get_movie_genre() << " " << movies[i].get_number_of_likes() << " " << movies[i].get_movie_trailer();
        this->listmovies->addItem(QString::fromStdString(buffer.str()));
    }
    this->listmovies->setCurrentRow(0);
}

void UserGui::open_watchlist() {
    ofstream f("watchlist.html");
    f << "<!DOCTYPE html>\n";
    f << "<html>\n";
    f << "<head>\n";
    f << "<title>Watchlist</title>\n";
    f << "</head>\n";
    f << "<body>\n";
    f << "<table border=\"1\">\n";
    f << "<tr>\n";
    f << "<td>Title</td>\n";
    f << "<td>Genre</td>\n";
    f << "<td>Likes</td>\n";
    f << "<td>Trailer</td>\n";
    f << "</tr>\n";
    int length = this->watchlist->count();
    Movie *movies = this->service->get_all_movies();
    int i;
    for (i = 0; i < length; i++){
        string title = this->watchlist->item(i)->text().toStdString();
        for (int j = 0; j < this->service->get_number_of_movies(); j++)
            if (movies[j].get_movie_title() == this->watchlist->item(i)->text().toStdString()){
                f<<"<tr>\n";
                f<<"<td>"<<movies[j].get_movie_title()<<"</td>\n";
                f<<"<td>"<<movies[j].get_movie_genre()<<"</td>\n";
                f<<"<td>"<<movies[j].get_number_of_likes()<<"</td>\n";
                f<<"<td><a href=\""<<movies[j].get_movie_trailer()<<"\">Trailer Link</a></td>\n";
                f<<"</tr>\n";
                }
    }
    f << "</table>\n";
    f << "</body>\n";
    f << "</html>\n";
    f.close();
    system("start watchlist.html");
}
void UserGui::add_movie_to_watchlist() {
    int position = this->PositionEdit->text().toInt();
    Movie* movies = this->service->get_all_movies();
    string genre = this->GenreEdit->text().toStdString();
    for(int i=0;i<this->service->get_number_of_movies();i++)
        if(movies[i].get_movie_genre()==genre || genre=="")
            this->watchlist->addItem(QString::fromStdString(movies[i].get_movie_title()));
    this->populate_list();

}

void UserGui::delete_movie_from_watchlist() {
    int position = this->PositionEdit->text().toInt();
    this->watchlist->takeItem(position);
    this->populate_list();
}

/*
 * void UserGui::add_movie() {
    string genre = this->GenreEdit->text().toStdString();
    this->service.add_movie_to_watchlist(genre);
    this->populate_list();
}
 */
