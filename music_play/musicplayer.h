#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include <QMediaMetaData>
#include <QAction>

class MusicPlayer :public QObject
{
	Q_OBJECT
public:
	MusicPlayer();
	\
    //player
    qint64 getSongTotalTime();
	void setVolume(int v);
    void nextSong();
    void previousSong();

	//music list
    int addMusicToList(const QStringList& list);
    //设置歌曲进度(分成一百份)
    void setDuration(int position);
private:
	QMediaPlayer *player;
	QMediaPlaylist *playList;
	QSoundEffect *effect;

private:
	void inline replace(QString& string);



signals:
	void positionChanged(qint64 position);
private slots:
	void positionChangedSlot(qint64 position);
    //void onMetaDataAvailableChanged(bool available);
public slots:
    void play();
    void pause();
};

#endif // MUSICPLAYER_H
