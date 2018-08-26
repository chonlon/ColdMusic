#ifndef LEFTSIDEBARUI_H
#define LEFTSIDEBARUI_H

#include <QWidget>
#include <QList>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QDir>

namespace Ui {
	class LeftSideBarUI;
}

class LeftSideBarUI : public QWidget
{
	Q_OBJECT

public:
	explicit LeftSideBarUI(QWidget *parent = 0);
	~LeftSideBarUI();

signals:
	void addedMusic(const QStringList& list);
    void updatePlayList(const QStringList& list);

	private slots:

	void on_addmusic_clicked();

private:
	Ui::LeftSideBarUI *ui;
};

#endif // LEFTSIDEBARUI_H
