#include <QApplication>
#include <QFileDialog>
#include <QPixmap>

#include "mainwindow.h"
#include "infowindow.h"
#include "./ui_mainwindow.h"
//#include "mylogo.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //MyLogo* logoWidget = new MyLogo(ui->frame);
    //logoWidget->setGeometry(10, 5, 70, 100);

    _basicsStorage = new Titles(this);

    _modelAllMovies = new QStringListModel(this);
    _modelMyMovies = new QStringListModel(this);

    ui->listView_allMovies->setModel(_modelAllMovies);
    ui->listView_myMovies->setModel(_modelMyMovies);

    QObject::connect(_basicsStorage, SIGNAL(fileOpen()), this, SLOT(onStorageOpen()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpenFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Data Storage"), "", tr("CSV Files (*.csv)"));

    _filePath = fileName;

    if (fileName.isNull())
        return;

    _basicsStorage->openFile(fileName);
}

void MainWindow::onStorageOpen()
{
    QStringList tBasics_primaryTitle;
    for (auto k : _basicsStorage->getValues())
        tBasics_primaryTitle.push_back(k.primaryTitle);

    _modelAllMovies->setStringList(tBasics_primaryTitle);
}


void MainWindow::on_listView_allMovies_doubleClicked(const QModelIndex& index)
{    
    QString tConst = index.data().toString();
    TBasics atts = _basicsStorage->getDetails(tConst);

    QStringList basicsAttsList;
    basicsAttsList.append("Title: " + atts.primaryTitle);
    basicsAttsList.append(" ");
    basicsAttsList.append("Type: " + atts.titleType);
    basicsAttsList.append("Year: " + atts.startYear);
    basicsAttsList.append("Duration (in minutes): " + atts.runtimeMins);
    basicsAttsList.append("Genere: " + atts.geners);

    _infoList = basicsAttsList;

    iw = new InfoWindow(_infoList, index, this);
    iw->show();
}















