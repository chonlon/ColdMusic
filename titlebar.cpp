#include "titlebar.h"
#include <QApplication>
#include <QEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>

#ifdef Q_OS_WIN
#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
#endif

TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    //    setFixedHeight(30);
    setFixedSize(parent->width(), 50);
    m_pIconLabel = new QLabel(this);
    m_pTitleLabel = new QLabel(this);
    m_pMinimizeButton = new QPushButton(this);
    m_pMaximizeButton = new QPushButton();
    m_pCloseButton = new QPushButton(this);

    m_pIconLabel->setFixedSize(30, 30);
    m_pIconLabel->setScaledContents(true);

    m_pTitleLabel->setSizePolicy(QSizePolicy::Expanding,
                                 QSizePolicy::Expanding);

    m_pMinimizeButton->setFixedSize(27, 22);
    m_pMaximizeButton->setFixedSize(27, 22);
    m_pCloseButton->setFixedSize(27, 22);

    m_pTitleLabel->setObjectName("whiteLabel");
    m_pMinimizeButton->setObjectName("minimizeButton");
    m_pMaximizeButton->setObjectName("maximizeButton");
    m_pCloseButton->setObjectName("closeButton");

    m_pMinimizeButton->setToolTip("Minimize");
    m_pMaximizeButton->setToolTip("Maximize");
    m_pCloseButton->setToolTip("Close");

    //设置按钮图标
    m_pCloseButton->setStyleSheet(
        "QPushButton{border-image: url(:/icon/resource/icon/close_normal.png);}\
                                                            QPushButton:hover{border-image: url(:/icon/resource/icon/close_hover.png);}\
                                                            QPushButton:pressed{border-image: url(:/icon/resource/icon/close_pressed.png);}");
    m_pMinimizeButton->setStyleSheet(
        "QPushButton{border-image: url(:/icon/resource/icon/minus_normal.png);}\
                                                 QPushButton:hover{border-image: url(:/icon/resource/icon/minus_hover.png);}\
                                                 QPushButton:pressed{border-image: url(:/icon/resource/icon/minus_hover.png);}");

    QHBoxLayout *pLayout = new QHBoxLayout(this);
    pLayout->addWidget(m_pIconLabel);
    pLayout->addSpacing(5);
    pLayout->addWidget(m_pTitleLabel);
    pLayout->addWidget(m_pMinimizeButton);
    //pLayout->addWidget(m_pMaximizeButton);
    pLayout->addWidget(m_pCloseButton);
    pLayout->setSpacing(0);
    pLayout->setContentsMargins(5, 0, 5, 0);

    setLayout(pLayout);

    connect(m_pMinimizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pMaximizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pCloseButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

TitleBar::~TitleBar() {}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    emit m_pMaximizeButton->clicked();
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
#ifdef Q_OS_WIN
    if (ReleaseCapture()) {
        QWidget *pWindow = this->window();
        if (pWindow->isTopLevel()) {
            SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND,
                        SC_MOVE + HTCAPTION, 0);
        }
    }
    event->ignore();
#else
#endif
}

bool TitleBar::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type()) {
        case QEvent::WindowTitleChange: {
            QWidget *pWidget = qobject_cast<QWidget *>(obj);
            if (pWidget) {
                m_pTitleLabel->setText(pWidget->windowTitle());
                return true;
            }
        }
        case QEvent::WindowIconChange: {
            QWidget *pWidget = qobject_cast<QWidget *>(obj);
            if (pWidget) {
                QIcon icon = pWidget->windowIcon();
                m_pIconLabel->setPixmap(icon.pixmap(m_pIconLabel->size()));
                return true;
            }
        }
        case QEvent::WindowStateChange:
        case QEvent::Resize:
            updateMaximize();
            return true;
        default:
            return QWidget::eventFilter(obj, event);
    }
    return QWidget::eventFilter(obj, event);
}

void TitleBar::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel()) {
        if (pButton == m_pMinimizeButton) {
            pWindow->showMinimized();
        } else if (pButton == m_pMaximizeButton) {
            //pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
        } else if (pButton == m_pCloseButton) {
            pWindow->close();
        }
    }
}

void TitleBar::updateMaximize()
{
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel()) {
        bool bMaximize = pWindow->isMaximized();
        if (bMaximize) {
            m_pMaximizeButton->setToolTip(tr("Restore"));
            m_pMaximizeButton->setProperty("maximizeProperty", "restore");
        } else {
            m_pMaximizeButton->setProperty("maximizeProperty", "maximize");
            m_pMaximizeButton->setToolTip(tr("Maximize"));
        }

        m_pMaximizeButton->setStyle(QApplication::style());
    }
}