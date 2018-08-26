#include "musicplayer.h"

#include <QDebug>
MusicPlayer::MusicPlayer()
{
	player = new QMediaPlayer();
	//connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
	playList = new QMediaPlaylist();
	//playList->addMedia(QUrl::fromLocalFile("E:\\音乐\\Beyond - 喜欢你.mp3"));
    //playList->addMedia(QUrl::fromLocalFile("E:\\音乐\\陈奕迅 - 红玫瑰.mp3"));
	player->setPlaylist(playList);
	//player->setVolume(30);
    //player->play();
	//qDebug()<<"test in music player";
	connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChangedSlot(qint64)));

}

qint64 MusicPlayer::getSongTotalTime() {
	return player->duration();
}

void MusicPlayer::positionChangedSlot(qint64 position) {
	emit positionChanged(position);
}

void MusicPlayer::setVolume(int v)
{
	player->setVolume(v);
}

void MusicPlayer::play() {
	player->play();
}

void MusicPlayer::pause() {
	player->pause();
}

int MusicPlayer::addMusicToList(const QStringList& list) {
    //qDebug() << "current id" << playList->currentIndex();
	playList->setPlaybackMode(QMediaPlaylist::Loop);
	QUrl url;
	for (QString fileName : list) {
		url = QUrl::fromLocalFile(fileName);
		if (url.isValid()) {
            //qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
			playList->addMedia(url);
		}
		//qDebug()<<fileName;
	}
//	qDebug() << "current id next" << playList->nextIndex();
//	qDebug() << "total" << playList->mediaCount();
	//qDebug()<playList->currentMedia();
	if (playList->mediaCount() - playList->currentIndex() != 1)//这里注意的是，和我们正常数数一样，mediaCount是从1开始计数的
	{
		//player->pause();
		//myPlayer->setMedia(playList->media(playList->nextIndex()));
		playList->setCurrentIndex(playList->nextIndex());
		player->play();
	}
	else
	{
		playList->setCurrentIndex(0);
		// myPlayer->setMedia(playList->media(0));
		player->play();
	}

	player->play();
	return playList->currentIndex();
}

void MusicPlayer::nextSong() {

    const int total = playList->mediaCount() - 1;
    qDebug()<<"next song "<<total<<endl;
    qDebug()<<"currentindex" <<playList->currentIndex()<<endl;
    if(playList->currentIndex() == total)
        playList->setCurrentIndex(0);
    else
        playList->setCurrentIndex(playList->currentIndex() + 1);
    player->play();
    QString str;
    //qDebug()<<player->metaData(str).toString().toUtf8().data();
    qDebug()<<player->metaData(QString("Duration")).toString();
    qDebug()<<playList->mediaObject();
}

void MusicPlayer::previousSong() {
    qDebug()<<"previous song" <<endl;
    qDebug()<<"currentindex" <<playList->currentIndex()<<endl;
    if(playList->currentIndex() == 0)
        {qDebug()<<"== 0";
        playList->setCurrentIndex(playList->mediaCount() - 1);}
    else
        playList->setCurrentIndex(playList->currentIndex() - 1);
    player->play();
}
void MusicPlayer::replace(QString& string) {
	if (!string.size())
		return;
	string = string.replace(QRegExp("/"), "\\");
}

void MusicPlayer::setDuration(int position) {
    qint64 position_ = position*player->duration()/100;
    player->setPosition(position_);
}
