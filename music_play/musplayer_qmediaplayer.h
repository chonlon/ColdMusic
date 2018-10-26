#ifndef MUSICPLAYER_QMediaPlayer_H
#define MUSICPLAYER_QMediaPlayer_H

#include <vector>
#include <string>
#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include <QMediaMetaData>
#include <QAction>

#include "musicplayer.h"


/// 由于是使用QMediaPlayer, 它和QMediaPlaylist是密切联系在一起的
/// 那么暂时不提供playlist的接口类(至少在这个类里面不会遇到重构时需要更改playlist类的情况)
class MusicPlayer_QMediaPlayer : public MusicPlayer{
    Q_OBJECT
public:
    MusicPlayer_QMediaPlayer();

    virtual bool play();

    virtual void pause();

    virtual uint64_t getSongTotalTime() const;

    virtual bool setVolume(uint8_t v);
    virtual bool setNextSong();
    virtual bool setPreviousSong();

    virtual int32_t addMusicToList(const std::vector<std::string>& list) {}
    int32_t addMusicToList(const QStringList& list);

    virtual bool setDuration(uint8_t position);

    virtual uint16_t getCurrentIndex() const;

    virtual bool setCurrentIndex(uint16_t index);

    virtual bool getSongNameToList( std::vector<std::string>* song_name_list ) {}

    virtual bool changeLoopMode(MusicPlayer::loop_modes mode) {}

    virtual ~MusicPlayer_QMediaPlayer();
private:
    QMediaPlayer *player_;
    //PlayList* list
    QMediaPlaylist *play_list_;
    QSoundEffect *effect_;

private:

    // no copying allowed
    MusicPlayer_QMediaPlayer(const MusicPlayer_QMediaPlayer&);
    void* operator= (const MusicPlayer_QMediaPlayer&);

signals:
    void positionChanged(qint64 position);
public slots:
private slots:
    void positionChangedSlot(qint64 position);
 };

#endif // MUSICPLAYER_H
