#include "deletefilm.h"
#include "ui_deletefilm.h"

DeleteFilm::DeleteFilm(QWidget *parent) :
    QDialog(parent),
    _flag(false),
    ui(new Ui::DeleteFilm)
{
    ui->setupUi(this);
}

DeleteFilm::~DeleteFilm()
{
    delete ui;
}


void DeleteFilm::deleteFilm()
{
    QString title = ui->lineEdit_filmToRemove->text();
    _title = title;
    _flag  = true;
}

void DeleteFilm::on_pushButton_ok_clicked()
{
    deleteFilm();
}
