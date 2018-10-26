#include "musplayer_qmediaplayer.h"

#include <QDebug>

MusicPlayer_QMediaPlayer::MusicPlayer_QMediaPlayer()
    :MusicPlayer () {
    player_ = new QMediaPlayer();
    play_list_ = new QMediaPlaylist();

    player_->setPlaylist(play_list_);

    connect(player_, SIGNAL(positionChanged(qint64)), this, SLOT(positionChangedSlot(qint64)));
}

MusicPlayer_QMediaPlayer::~MusicPlayer_QMediaPlayer() {
    delete player_;
    delete play_list_;
}

bool MusicPlayer_QMediaPlayer::play() {
    if(play_list_->mediaCount() == 0) return false;
    player_->play();
    return true;
}

void MusicPlayer_QMediaPlayer::pause() {
    player_->pause();
}

uint64_t MusicPlayer_QMediaPlayer::getSongTotalTime() const {
    return static_cast<uint64_t>(player_->duration());
}

bool MusicPlayer_QMediaPlayer::setVolume(uint8_t v) {
    player_->setVolume(static_cast<int>(v));
    return true;
}

int32_t MusicPlayer_QMediaPlayer::addMusicToList(const QStringList &list) {
    //qDebug() << "current id" << playList->currentIndex();
    play_list_->setPlaybackMode(QMediaPlaylist::Loop);
    QUrl url;
    for (QString fileName : list) {
        url = QUrl::fromLocalFile(fileName);
        if (url.isValid()) {
            //qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
            play_list_->addMedia(url);
        }
    }

    if (play_list_->mediaCount() - play_list_->currentIndex() != 1)//这里注意的是，和我们正常数数一样，mediaCount是从1开始计数的
    {
        play_list_->setCurrentIndex(play_list_->nextIndex());
        player_->play();

    }
    else
    {
        play_list_->setCurrentIndex(0);
        // myPlayer->setMedia(playList->media(0));
        player_->play();
    }

    player_->play();
    return play_list_->mediaCount();
}

void MusicPlayer_QMediaPlayer::positionChangedSlot(qint64 position) {
	emit positionChanged(position);
}



bool MusicPlayer_QMediaPlayer::setNextSong() {

    const int total = play_list_->mediaCount() - 1;
    if(!total) return false;

    qDebug()<<"next song "<<total<<endl;
    qDebug()<<"currentindex" <<play_list_->currentIndex()<<endl;

    if(play_list_->currentIndex() == total)
        play_list_->setCurrentIndex(0);
    else
        play_list_->setCurrentIndex(play_list_->currentIndex() + 1);
    player_->play();
    return true;

    //qDebug()<<player->metaData(str).toString().toUtf8().data();
    qDebug()<<player_->metaData(QString("Duration")).toString();
    qDebug()<<play_list_->mediaObject();
}

bool MusicPlayer_QMediaPlayer::setPreviousSong() {
    if(play_list_->mediaCount() == 1) return false;

    qDebug()<<"previous song" <<endl;
    qDebug()<<"currentindex" <<play_list_->currentIndex()<<endl;

    if(play_list_->currentIndex() == 0)
        {qDebug()<<"== 0";
        play_list_->setCurrentIndex(play_list_->mediaCount() - 1);}
    else
        play_list_->setCurrentIndex(play_list_->currentIndex() - 1);
    player_->play();

    return true;
}

//void MusicPlayer::replace(QString& string) {
//	if (!string.size())
//		return;
//	string = string.replace(QRegExp("/"), "\\");
//}

bool MusicPlayer_QMediaPlayer::setDuration(uint8_t position) {
    qint64 position_ = position*player_->duration()/100;
    player_->setPosition(position_);
    return true;
}

uint16_t MusicPlayer_QMediaPlayer::getCurrentIndex() const {
    return static_cast<uint16_t>(play_list_->currentIndex());
}

bool MusicPlayer_QMediaPlayer::setCurrentIndex(uint16_t index) {
    const int total_num = play_list_->mediaCount() - 1;
    bool return_value = true;
    if(index > total_num) { index = static_cast<uint16_t>(total_num); return return_value = false; }
    play_list_->setCurrentIndex(static_cast<int>(index));
    return return_value;
}
