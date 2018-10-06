#ifndef SONGINFRO_H
#define SONGINFRO_H
#include <QString>

//歌曲信息
//currentIndex用于和mediaPlayList的index对应, 使用这个歌曲信息跳转响应歌曲.
//其他信息如果没有获取到则置空.
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
