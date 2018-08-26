#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QIcon>

class TitleBar : public QWidget
{
	Q_OBJECT
public:
	explicit TitleBar(QWidget *parent = nullptr);
	~TitleBar();
protected:
	// 双击标题栏进行界面的最大化/还原
	virtual void mouseDoubleClickEvent(QMouseEvent *event);

	// 进行鼠界面的拖动
	virtual void mousePressEvent(QMouseEvent *event);

	// 设置界面标题与图标
	virtual bool eventFilter(QObject *obj, QEvent *event);
signals:

	public slots :
		private slots :
		void onClicked();
private:

	// 最大化/还原
	void updateMaximize();
	void SetButtonStyle(QPushButton *button, QString imgsrc, int CutSec);
private:
	QLabel *m_pIconLabel;
	QLabel *m_pTitleLabel;
	QPushButton *m_pMinimizeButton;
	QPushButton *m_pMaximizeButton;
	QPushButton *m_pCloseButton;
};

#endif // TOOLBAR_H
