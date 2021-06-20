#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

#include "titles.h"
#include "infowindow.h"
#include "addnewfilm.h"
#include "deletefilm.h"


QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class InfoWindow;  /// forward declaration for a compiler
class AddNewFilm;
class DeleteFilm;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    Titles* _basicsStorage;
    //Titles* _ratingsStorage;
    //Titles* _principlesStorage;

    QStringListModel* _modelAllMovies;
    QStringListModel* _modelMyMovies;

    QString _filePath;
    QStringList _infoList;

private slots:
    void on_actionOpenFile_triggered();

    void onStorageOpen();

    void on_listView_allMovies_doubleClicked(const QModelIndex& index);

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::MainWindow* ui;
    InfoWindow* iw;
    AddNewFilm* aw;
    DeleteFilm* dw;
};
#endif // MAINWINDOW_H
