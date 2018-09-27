#ifndef SONGINFRO_H
#define SONGINFRO_H
#include <QString>
struct SongInfro{
    QString artist;
    QString album;
    QString title;
    int currentIndex;
    SongInfro(QString artist, QString album, QString title, int currentIndex)
        :artist(artist), album(album), title(title), currentIndex(currentIndex) { }
    SongInfro(int curr):currentIndex(curr) { }
};
typedef struct SongInfro SongInfro;
#endif // SONGINFRO_H
