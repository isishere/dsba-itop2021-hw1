#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QList>
#include <QPixmap>
#include <QStringList>


struct TBasics
{
    QString tConst;
    QString titleType;
    QString primaryTitle; /// nu. 2
    QString originalTitle;
    QString isAdult;
    QString startYear;
    QString endYear;
    QString runtimeMins;
    QString geners;
};

struct TRatings
{
    QString tConst;
    QString averageRatings;
    QString numVotes;
};

struct TPrinciples
{
    QString tConst;
    QString ordering;
    QString nConst;
    QString category;
    QString job;
    QString characters;
};


class Titles : public QObject
{
    Q_OBJECT
public:
    explicit Titles(QObject* parent = nullptr);

    void openFile(const QString& fileName);
    void addNewFilmToModel(const QPair<QString, TBasics>& pairTitleAtts);
    void deleteFilmFromModel(const QString title);

    QList<QString> getKeys() const;
    QList<TBasics> getValues() const;
    TBasics getDetails(const QString& tConst) const;
    QStringList getWatchList() const;

    QStringList addToWatchList(const QString& title);
    QStringList removeFromWatchList(const QString& title);

    //QPixmap getPixmap(const QString& productName) const;

protected:
    void readFile();

    QString _fileName;
    QMap<QString, TBasics> _mapTitleAtts;
    QStringList _watchList;

signals:
    void fileOpen();
    void filmAdded();
    void filmDeleted();
};

#endif // MENU_H
