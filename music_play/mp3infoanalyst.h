#ifndef MP3INFOANALYST_H
#define MP3INFOANALYST_H

namespace std {
    class string;
}

struct SongInfor;

class Mp3InfoAnalyst
{
public:
    Mp3InfoAnalyst();

    virtual void load() = 0;

    virtual SongInfor getInfor() const = 0;

    virtual std::string getArtist() const = 0;

    virtual ~Mp3InfoAnalyst() = 0;
protected:
    virtual void analyze() = 0;
};

#endif // MP3INFOANALYST_H
