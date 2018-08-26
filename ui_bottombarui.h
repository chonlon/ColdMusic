/********************************************************************************
** Form generated from reading UI file 'bottombarui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTTOMBARUI_H
#define UI_BOTTOMBARUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <playslider.h>

QT_BEGIN_NAMESPACE

class Ui_BottomBarUI
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *previous_btn;
    QPushButton *play_btn;
    QPushButton *next_btn;
    QLabel *label;
    PlaySlider *play_slider;
    QLabel *label_2;
    QPushButton *volume_btn;
    QSlider *volume_slider;
    QPushButton *loopMode_btn;
    QPushButton *pushButton_6;

    void setupUi(QWidget *BottomBarUI)
    {
        if (BottomBarUI->objectName().isEmpty())
            BottomBarUI->setObjectName(QStringLiteral("BottomBarUI"));
        BottomBarUI->resize(1022, 50);
        layoutWidget = new QWidget(BottomBarUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 991, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        previous_btn = new QPushButton(layoutWidget);
        previous_btn->setObjectName(QStringLiteral("previous_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(previous_btn->sizePolicy().hasHeightForWidth());
        previous_btn->setSizePolicy(sizePolicy);
        previous_btn->setMinimumSize(QSize(35, 30));
        previous_btn->setMaximumSize(QSize(35, 30));
        previous_btn->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/icon/resource/icon/previous_normal.png);}\n"
"QPushButton:hover{border-image: url(:/icon/resource/icon/previous_hover.png);}\n"
"QPushButton:pressed{border-image: url(:/icon/resource/icon/previous_pressed.png);}\n"
""));
        previous_btn->setIconSize(QSize(45, 40));

        horizontalLayout->addWidget(previous_btn);

        play_btn = new QPushButton(layoutWidget);
        play_btn->setObjectName(QStringLiteral("play_btn"));
        sizePolicy.setHeightForWidth(play_btn->sizePolicy().hasHeightForWidth());
        play_btn->setSizePolicy(sizePolicy);
        play_btn->setMinimumSize(QSize(45, 40));
        play_btn->setMaximumSize(QSize(45, 40));
        play_btn->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/icon/resource/icon/pause_normal.png);}\n"
"QPushButton:hover{border-image: url(:/icon/resource/icon/pause_hover.png);}\n"
"QPushButton:pressed{border-image: url(:/icon/resource/icon/pause_hover.png);}"));

        horizontalLayout->addWidget(play_btn);

        next_btn = new QPushButton(layoutWidget);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        sizePolicy.setHeightForWidth(next_btn->sizePolicy().hasHeightForWidth());
        next_btn->setSizePolicy(sizePolicy);
        next_btn->setMinimumSize(QSize(35, 30));
        next_btn->setMaximumSize(QSize(35, 30));
        next_btn->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/icon/resource/icon/next_normal.png);}\n"
"QPushButton:hover{border-image: url(:/icon/resource/icon/next_hover.png);}\n"
"QPushButton:pressed{border-image: url(:/icon/resource/icon/next_pressed.png);}"));

        horizontalLayout->addWidget(next_btn);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(label);

        play_slider = new PlaySlider(layoutWidget);
        play_slider->setObjectName(QStringLiteral("play_slider"));
        play_slider->setMinimumSize(QSize(400, 0));
        play_slider->setStyleSheet(QLatin1String("QSlider::groove:horizontal,QSlider::add-page:horizontal{\n"
"height:4px;\n"
"border-radius:3px;\n"
"background:#18181a;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
" \n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,stop:0 rgba(231,80,229, 255), stop:1 rgba(7,208,255, 255));\n"
"height:3px;\n"
" \n"
"}\n"
"\n"
"\n"
"QSlider::handle:horizontal{\n"
"width:12px;\n"
"margin-top:-5px;\n"
"margin-bottom:-4px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #565656,stop:0.8 #565656);\n"
"bacder-image:url(./res/images/live/GOUGOU.png)\n"
"}\n"
"\n"
"\n"
"QSlider::groove:vertical,QSlider::sub-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#D8D8D8;\n"
"}\n"
"\n"
"\n"
"QSlider::add-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#008aff;\n"
"}\n"
"\n"
"\n"
"QSlider::handle:vertical{\n"
"height:12px;\n"
"margin-left:-5px;\n"
"margin-right:-4px;\n"
"border-radius:6px;\n"
"background:qradialg"
                        "radient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #565656,stop:0.8 #565656);\n"
"bacder-image:url(./res/images/live/GOUGOU.png)\n"
"}"));
        play_slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(play_slider);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(label_2);

        volume_btn = new QPushButton(layoutWidget);
        volume_btn->setObjectName(QStringLiteral("volume_btn"));
        volume_btn->setMinimumSize(QSize(30, 30));
        volume_btn->setMaximumSize(QSize(30, 30));
        volume_btn->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/icon/resource/icon/volume.png);}\n"
"QPushButton:hover{border-image: url(:/icon/resource/icon/volume.png);}\n"
"QPushButton:pressed{border-image: url(:/icon/resource/icon/volume.png);}"));

        horizontalLayout->addWidget(volume_btn);

        volume_slider = new QSlider(layoutWidget);
        volume_slider->setObjectName(QStringLiteral("volume_slider"));
        volume_slider->setMaximumSize(QSize(80, 16777215));
        volume_slider->setStyleSheet(QLatin1String("QSlider::groove:horizontal,QSlider::add-page:horizontal{\n"
"height:3px;\n"
"border-radius:3px;\n"
"background:#18181a;\n"
"}\n"
"\n"
"\n"
"QSlider::sub-page:horizontal{\n"
"height:8px;\n"
"border-radius:3px;\n"
"background:#008aff;\n"
"}\n"
"\n"
"\n"
"QSlider::handle:horizontal{\n"
"width:12px;\n"
"margin-top:-5px;\n"
"margin-bottom:-4px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #565656,stop:0.8 #565656);\n"
"bacder-image:url(./res/images/live/GOUGOU.png)\n"
"}\n"
"\n"
"\n"
"QSlider::groove:vertical,QSlider::sub-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#D8D8D8;\n"
"}\n"
"\n"
"\n"
"QSlider::add-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#008aff;\n"
"}\n"
"\n"
"\n"
"QSlider::handle:vertical{\n"
"height:12px;\n"
"margin-left:-5px;\n"
"margin-right:-4px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #565656,stop:0.8 #565656);"
                        "\n"
"bacder-image:url(./res/images/live/GOUGOU.png)\n"
"}"));
        volume_slider->setMaximum(100);
        volume_slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(volume_slider);

        loopMode_btn = new QPushButton(layoutWidget);
        loopMode_btn->setObjectName(QStringLiteral("loopMode_btn"));
        loopMode_btn->setMinimumSize(QSize(30, 30));
        loopMode_btn->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(loopMode_btn);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(25, 20));
        pushButton_6->setMaximumSize(QSize(50, 16777215));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/icon/resource/icon/playlist.png);}\n"
"QPushButton:hover{border-image: url(:/icon/resource/icon/playlist.png);}\n"
"QPushButton:pressed{border-image: url(:/icon/resource/playlist.png);}"));

        horizontalLayout->addWidget(pushButton_6);


        retranslateUi(BottomBarUI);

        QMetaObject::connectSlotsByName(BottomBarUI);
    } // setupUi

    void retranslateUi(QWidget *BottomBarUI)
    {
        BottomBarUI->setWindowTitle(QApplication::translate("BottomBarUI", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        previous_btn->setToolTip(QApplication::translate("BottomBarUI", "<html><head/><body><p>\344\270\212\344\270\200\351\246\226</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        previous_btn->setWhatsThis(QApplication::translate("BottomBarUI", "<html><head/><body><p>\344\270\212\344\270\200\351\246\226</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        previous_btn->setText(QString());
#ifndef QT_NO_TOOLTIP
        play_btn->setToolTip(QApplication::translate("BottomBarUI", "<html><head/><body><p>\346\222\255\346\224\276/\346\232\202\345\201\234</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        play_btn->setWhatsThis(QApplication::translate("BottomBarUI", "<html><head/><body><p>\346\222\255\346\224\276/\346\232\202\345\201\234</p><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        play_btn->setText(QString());
#ifndef QT_NO_TOOLTIP
        next_btn->setToolTip(QApplication::translate("BottomBarUI", "<html><head/><body><p>\344\270\213\344\270\200\351\246\226</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        next_btn->setWhatsThis(QApplication::translate("BottomBarUI", "<html><head/><body><p>\344\270\213\344\270\200\351\246\226</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        next_btn->setText(QString());
        label->setText(QApplication::translate("BottomBarUI", "00:00", Q_NULLPTR));
        label_2->setText(QApplication::translate("BottomBarUI", "00:00", Q_NULLPTR));
        volume_btn->setText(QString());
#ifndef QT_NO_TOOLTIP
        volume_slider->setToolTip(QApplication::translate("BottomBarUI", "<html><head/><body><p>\346\233\264\346\224\271\351\237\263\351\207\217</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        volume_slider->setWhatsThis(QApplication::translate("BottomBarUI", "<html><head/><body><p>\346\233\264\346\224\271\351\237\263\351\207\217</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        loopMode_btn->setText(QApplication::translate("BottomBarUI", "\350\257\215", Q_NULLPTR));
        pushButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BottomBarUI: public Ui_BottomBarUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTTOMBARUI_H
