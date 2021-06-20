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
    QObject::connect(_basicsStorage, SIGNAL(filmAdded()), this, SLOT(onStorageOpen()));
    QObject::connect(_basicsStorage, SIGNAL(filmDeleted()), this, SLOT(onStorageOpen()));
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
    basicsAttsList.append("Duration: " + atts.runtimeMins + " mins");
    basicsAttsList.append("Genere: " + atts.geners);

    _infoList = basicsAttsList;

    iw = new InfoWindow(_infoList, index, this);
    iw->show();
}

void MainWindow::on_pushButton_add_clicked()
{
    aw = new AddNewFilm();
    aw->exec();

    if (aw->getFlag())
    {
        QPair<QString, TBasics> pairTitleAtts = aw->getPairTitleAtts();
        _basicsStorage->addNewFilmToModel(pairTitleAtts);
    }
}

void MainWindow::on_pushButton_delete_clicked()
{
    dw = new DeleteFilm();
    dw->exec();

    if (dw->getFlag())
    {
        QString title = dw->getTitle();
        _basicsStorage->deleteFilmFromModel(title);
    }
}
