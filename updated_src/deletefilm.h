#ifndef DELETEFILM_H
#define DELETEFILM_H

#include <QDialog>

#include "titles.h"
#include "mainwindow.h"

namespace Ui {
class DeleteFilm;
}

class DeleteFilm : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteFilm(QWidget *parent = nullptr);
    ~DeleteFilm();

    void deleteFilm();
    QString getTitle() {return _title; };
    bool getFlag() { return _flag; };
protected:
    QString _title;
    bool _flag;

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::DeleteFilm *ui;
};

#endif // DELETEFILM_H
