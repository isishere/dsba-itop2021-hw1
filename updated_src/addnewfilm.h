#ifndef ADDNEWFILM_H
#define ADDNEWFILM_H

#include <QDialog>

#include "titles.h"
#include "mainwindow.h"

namespace Ui {
class AddNewFilm;
}

class AddNewFilm : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewFilm(QWidget *parent = nullptr);
    ~AddNewFilm();

    void createNewFilm();
    QPair<QString, TBasics> getPairTitleAtts() { return _pairTitleAtts; }
    bool getFlag() { return _flag; };

protected:
    QPair<QString, TBasics> _pairTitleAtts;
    bool _flag;

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::AddNewFilm *ui;

};

#endif // ADDNEWFILM_H
