#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QDialog>

#include "mainwindow.h"
#include "titles.h"

QT_BEGIN_NAMESPACE
namespace Ui {class InfoWindow;}
QT_END_NAMESPACE

class InfoWindow : public QDialog
{
    Q_OBJECT

public:
    InfoWindow(QStringList& infoList, const QModelIndex& index, QWidget *parent = nullptr);
    ~InfoWindow();

protected:
    Titles* _infoStorage;
    QStringListModel* _modelInfo;

    const QModelIndex _index;
    const QString _filePath;

    QStringList _infoList;
    QStringList _watchList;

private slots:

    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

private:
    void assignFileToStorage();

    Ui::InfoWindow *ui;
};

#endif // INFOWINDOW_H
