/********************************************************************************
** Form generated from reading UI file 'leftsidebarui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTSIDEBARUI_H
#define UI_LEFTSIDEBARUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeftSideBarUI
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QPushButton *addmusic;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *LeftSideBarUI)
    {
        if (LeftSideBarUI->objectName().isEmpty())
            LeftSideBarUI->setObjectName(QStringLiteral("LeftSideBarUI"));
        LeftSideBarUI->resize(250, 570);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LeftSideBarUI->sizePolicy().hasHeightForWidth());
        LeftSideBarUI->setSizePolicy(sizePolicy);
        LeftSideBarUI->setMinimumSize(QSize(250, 570));
        layoutWidget = new QWidget(LeftSideBarUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 161, 531));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(11);
        label->setFont(font);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));
        pushButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/background/resource/background/transparent.png);}\n"
"QPushButton:hover{border-image: url(:/background/resource/background/blue_transparent.png);}\n"
"QPushButton:pressed{border-image: url:(/background/resource/background/transparent.png);}"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/background/resource/background/transparent.png);}\n"
"QPushButton:hover{border-image: url(:/background/resource/background/blue_transparent.png);}\n"
"QPushButton:pressed{border-image: url:(/background/resource/background/transparent.png);}"));

        verticalLayout->addWidget(pushButton_2);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 30));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/background/resource/background/transparent.png);}\n"
"QPushButton:hover{border-image: url(:/background/resource/background/blue_transparent.png);}\n"
"QPushButton:pressed{border-image: url:(/background/resource/background/transparent.png);}"));

        verticalLayout_2->addWidget(pushButton_3);

        addmusic = new QPushButton(layoutWidget);
        addmusic->setObjectName(QStringLiteral("addmusic"));
        addmusic->setMinimumSize(QSize(0, 30));
        addmusic->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/background/resource/background/transparent.png);}\n"
"QPushButton:hover{border-image: url(:/background/resource/background/blue_transparent.png);}\n"
"QPushButton:pressed{border-image: url:(/background/resource/background/transparent.png);}"));

        verticalLayout_2->addWidget(addmusic);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 50));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 30));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/background/resource/background/transparent.png);}\n"
"QPushButton:hover{border-image: url(:/background/resource/background/blue_transparent.png);}\n"
"QPushButton:pressed{border-image: url:(/background/resource/background/transparent.png);}"));

        verticalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 30));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/background/resource/background/transparent.png);}\n"
"QPushButton:hover{border-image: url(:/background/resource/background/blue_transparent.png);}\n"
"QPushButton:pressed{border-image: url:(/background/resource/background/transparent.png);}"));

        verticalLayout_3->addWidget(pushButton_6);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(LeftSideBarUI);

        QMetaObject::connectSlotsByName(LeftSideBarUI);
    } // setupUi

    void retranslateUi(QWidget *LeftSideBarUI)
    {
        LeftSideBarUI->setWindowTitle(QApplication::translate("LeftSideBarUI", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("LeftSideBarUI", "\347\275\221\347\273\234\351\237\263\344\271\220", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LeftSideBarUI", "QQ\351\237\263\344\271\220", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("LeftSideBarUI", "\347\275\221\346\230\223\344\272\221\351\237\263\344\271\220", Q_NULLPTR));
        label_2->setText(QApplication::translate("LeftSideBarUI", "\346\234\254\345\234\260\351\237\263\344\271\220", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("LeftSideBarUI", "\351\237\263\344\271\220\345\210\227\350\241\250", Q_NULLPTR));
        addmusic->setText(QApplication::translate("LeftSideBarUI", "\346\267\273\345\212\240\351\237\263\344\271\220", Q_NULLPTR));
        label_3->setText(QApplication::translate("LeftSideBarUI", "\346\255\214\345\215\225", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("LeftSideBarUI", "\346\210\221\345\226\234\346\254\242\347\232\204", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("LeftSideBarUI", "\350\275\273\351\237\263\344\271\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LeftSideBarUI: public Ui_LeftSideBarUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTSIDEBARUI_H
