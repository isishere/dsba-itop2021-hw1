#include "addnewfilm.h"
#include "ui_addnewfilm.h"
#include "titles.h"

#include <QMap>

AddNewFilm::AddNewFilm(QWidget *parent) :
    QDialog(parent),
    _flag(false),
    ui(new Ui::AddNewFilm)
{
    ui->setupUi(this);
}

AddNewFilm::~AddNewFilm()
{
    delete ui;
}

void AddNewFilm::createNewFilm()
{
    TBasics atts;
    QString title;

    QPair<QString, TBasics> pairTitleAtts;

    title = ui->lineEdit_title->text();

    pairTitleAtts.first = title;
    pairTitleAtts.second.primaryTitle = ui->lineEdit_title->text();
    pairTitleAtts.second.titleType = ui->lineEdit_type->text();;
    pairTitleAtts.second.startYear = ui->lineEdit_year->text();
    pairTitleAtts.second.runtimeMins = ui->lineEdit_duration->text();
    pairTitleAtts.second.geners = ui->lineEdit_genre->text();

    _pairTitleAtts = pairTitleAtts;

    _flag = true;
}

void AddNewFilm::on_pushButton_ok_clicked()
{
    createNewFilm();
}
