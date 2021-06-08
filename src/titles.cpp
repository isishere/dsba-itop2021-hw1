#include "titles.h"

#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QStringList>

Titles::Titles(QObject *parent)
    : QObject(parent)
{

}

void Titles::readFile()
{
    if (_fileName.isEmpty())
        throw std::invalid_argument("File name is not set.");

    QFile file(_fileName);

    if (!file.open(QIODevice::ReadOnly))
        throw std::runtime_error("Could not open file.");

    bool firstLine = true;

    QTextStream fStream(&file);
    while (!fStream.atEnd())
    {
       QString line = fStream.readLine();
       if (line.isNull())
           continue;

       if (firstLine)
       {
           firstLine = false;
           continue;
       }

       QStringList att = line.split(QLatin1Char(','));

       if (att.size() < 9)
           continue;

       TBasics tb = {att[0], att[1], att[2], att[3],
                    att[4], att[5], att[6], att[7], att[8]};
       _mapTitleAtts.insert(att[0], tb); /// {tConst, TBasics}
    }

    file.close();
}

void Titles::openFile(const QString& fileName)
{
    _fileName = fileName;
    readFile();

    emit fileOpen();
}

QList<QString> Titles::getKeys() const
{
    return _mapTitleAtts.keys();
}

QList<TBasics> Titles::getValues() const
{
    return _mapTitleAtts.values();
}

TBasics Titles::getDetails(const QString& tConst) const
{
    return _mapTitleAtts[tConst];
}

QStringList Titles::getWatchList() const
{
    return _watchList;
}

QStringList Titles::addToWatchList(const QString& title)
{
    _watchList.push_back(title);
    return _watchList;
}

QStringList Titles::removeFromWatchList(const QString &title)
{
    for (auto k : _watchList)
        if (title == k)
            _watchList.removeOne(title);

    return _watchList;
}



//QPixmap Titles::getPixmap(const QString& productName) const
//{
//    QMap<QString, TBasics>::const_iterator it = _titleBasics.find(productName);
//    if (it == _titleBasics.end())
//        return QPixmap();
//
//    QFileInfo fi(_fileName);
//    QString imgFileName = fi.absolutePath() + "/" + it->imagePath;
//
//    QPixmap img(imgFileName);
//
//    return img;
//}
