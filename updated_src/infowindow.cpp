#include "infowindow.h"
#include "ui_infowindow.h"
#include "titles.h"

InfoWindow::InfoWindow(QStringList& infoList, const QModelIndex& index, QWidget *parent) :
    QDialog(parent),
    _index(index),
    _infoList(infoList),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);

    _infoStorage = new Titles(this);
    _modelInfo = new QStringListModel(this);

    ui->listView_info->setModel(_modelInfo);

    _modelInfo->setStringList(_infoList);
}

InfoWindow::~InfoWindow()
{
    delete ui;
}

void InfoWindow::assignFileToStorage()
{
    _infoStorage->openFile(_filePath);
}

void InfoWindow::on_pushButton_add_clicked()
{
    QString currTitle;
    for (auto k : _infoStorage->getKeys())
        if (k == _index.data().toString())
            currTitle = k;

    QStringList watchList;
    _watchList.push_back(currTitle);
}

void InfoWindow::on_pushButton_remove_clicked()
{

}
