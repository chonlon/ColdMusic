#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include<QObject>

class MusicPlayer : public QObject {
  Q_OBJECT
public:
    MusicPlayer() { }
    ~MusicPlayer();

    /// <summary>播放目前在列表的歌曲
    /// 成功播放返回true.
    /// 播放失败返回false. 如: 目前播放列表为空返回空
    /// </summary>
    virtual bool play() = 0;

    /// <summary>暂停播放目前歌曲, 不存在暂停失败情况.</summary>
    virtual void pause() = 0;

    /// <summary>获取当前歌曲的总时间
    /// 如果目前没有歌曲在播放列表中, 那么返回 0
    /// </summary>
    virtual uint64_t getSongTotalTime() const = 0;

    /// <param  name: v>
    /// 需要设置的音量(百分比)
    /// 参数范围: 0 - 100
    ///  </param>
    /// <summary>如果参数不在范围内, 将音量设置到最接近的音量, 并且返回false.
    /// 并且可能会在这个函数当中发出信号, 以调整界面中的音量图标以及相关界面元素.
    /// </summary>
    virtual bool setVolume(uint8_t v) = 0;

    /// <summary>设置下一首歌
    /// 成功则返回true
    /// 失败则返回false, 如: 目前播放列表为空返回空
    /// </summary>
    virtual bool setNextSong() = 0;

    /// <summary>设置上一首歌
    /// 成功则返回true
    /// 失败则返回false, 如: 目前播放列表为空返回空
    /// </summary>
    virtual bool setPreviousSong() = 0;

    /// <param  name:list> 由于虚函数不能是模版函数. 所以只能先提供一个丑陋的接口了.
    /// 推荐使用vector<string>保存播放列表
    /// 歌曲列表当中可能含有大量信息, 为保证性能, 可以重新实现这个函数, 如果不使用推荐的vector, 避免大量转换
    /// 比如使用QStringList, 那么在子类中只实现空函数, 另外提供其他版本的函数
    /// </param>
    /// <summary> 添加歌曲到播放列表中, 返回成功添加的歌曲数量 </summary>
    virtual int32_t addMusicToList(const std::vector<std::string>& list) = 0;
    virtual int32_t addMusicToList(const QStringList& list) = 0;

    /// <param  name: position> 希望地歌曲进度, 以百分比来调整歌曲进度
    /// 范围: 0 - 100
    ///  </param>
    /// <summary>调整歌曲进度
    /// 成功返回true
    /// 失败返回false
    /// </summary>
    virtual bool setDuration(uint8_t position) = 0;

    /// <summary> 返回当前歌曲的序号 </summary>
    virtual uint16_t getCurrentIndex() const = 0;

    /// <summary>以序号设置当前歌曲
    /// 成功返回true
    /// 失败返回false
    /// </summary>
    virtual bool setCurrentIndex(uint16_t index) = 0;

    enum loop_modes{m_loop};
    virtual bool changeLoopMode(loop_modes mode) = 0;

    /// <return param: song_name_list> 由于虚函数不能是模版函数. 所以只能先提供一个丑陋的接口了.
    /// 推荐使用vector<string>获得返回的播放列表.
    /// 歌曲列表当中可能含有大量信息, 为保证性能, 可以重新实现这个函数, 不使用推荐的vector, 避免大量转换
    /// </return param>
    /// <summary> 获取当前的播放列表
    /// 成功返回true
    /// 失败返回false
    /// </summary>
    virtual bool getSongNameToList( std::vector<std::string>* song_name_list ) = 0;

private:

    // no copying allowed
    MusicPlayer(const MusicPlayer& player);
    void* operator= (const MusicPlayer& player);
};

#endif // MUSICPLAYER_H
