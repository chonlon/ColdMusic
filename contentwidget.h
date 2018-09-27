#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QString>
#include <QGraphicsOpacityEffect>

#include <vector>

#include "music_play/songinfro.h"

namespace Ui {
	class ContentWidget;
}

class ContentWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ContentWidget(QWidget *parent = 0);
	~ContentWidget();

private:
	Ui::ContentWidget *ui;

public slots:
    void addMusicToList();
    void updateMusicList(const std::vector<SongInfro>& infroList);
};

#endif // CONTENTWIDGET_H
