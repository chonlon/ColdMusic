/********************************************************************************
** Form generated from reading UI file 'contentwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTENTWIDGET_H
#define UI_CONTENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContentWidget
{
public:
    QWidget *contentWindow;
    QWidget *tableWindow;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *ContentWidget)
    {
        if (ContentWidget->objectName().isEmpty())
            ContentWidget->setObjectName(QStringLiteral("ContentWidget"));
        ContentWidget->resize(772, 570);
        ContentWidget->setMinimumSize(QSize(772, 570));
        ContentWidget->setMaximumSize(QSize(772, 570));
        contentWindow = new QWidget(ContentWidget);
        contentWindow->setObjectName(QStringLiteral("contentWindow"));
        contentWindow->setGeometry(QRect(10, 10, 751, 551));
        tableWindow = new QWidget(contentWindow);
        tableWindow->setObjectName(QStringLiteral("tableWindow"));
        tableWindow->setGeometry(QRect(0, 50, 741, 481));
        tableWidget = new QTableWidget(tableWindow);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 20, 741, 491));
        tableWidget->setStyleSheet(QString::fromUtf8("QHeaderView                    // QTableWidget \346\240\207\351\242\230\345\244\264\346\225\264\344\270\252\345\214\272\345\237\237\n"
"{\n"
"    background:rgba(255,255,255,128);        // \346\225\264\344\270\252\346\240\207\351\242\230\345\244\264\345\214\272\345\237\237\350\203\214\346\231\257\350\211\262\n"
"}\n"
"background-color:rgba(255,255,255,128)\n"
"\n"
"QScrollBar::handle:vertical        // \345\236\202\347\233\264\346\273\232\345\212\250\346\235\241 handle\n"
"{\n"
"    background: rgba(255,255,255,20%); // \345\236\202\347\233\264\346\273\232\345\212\250\346\235\241 handle \347\232\204\350\203\214\346\231\257\350\211\262\n"
"    border: 0px solid grey;            // \345\236\202\347\233\264\346\273\232\345\212\250\346\235\241 handle \350\276\271\346\241\206\n"
"    border-radius:3px;                 // \345\236\202\347\233\264\346\273\232\345\212\250\346\235\241 handle \345\234\206\350\247\222\n"
"    width: 8px;                        // \345\236\202\347\233\264\346\273\232\345\212\250\346\235\241"
                        " handle \345\256\275\345\272\246\n"
"}"));
        pushButton = new QPushButton(contentWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 93, 28));
        textEdit = new QTextEdit(contentWindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(530, 10, 211, 29));
        textEdit->setStyleSheet(QLatin1String("font: 9pt \"Microsoft YaHei UI\";\n"
"border-image: url(:/background/resource/background/blue_transparent.png);"));

        retranslateUi(ContentWidget);

        QMetaObject::connectSlotsByName(ContentWidget);
    } // setupUi

    void retranslateUi(QWidget *ContentWidget)
    {
        ContentWidget->setWindowTitle(QApplication::translate("ContentWidget", "Form", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("ContentWidget", "\346\255\214\346\233\262\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("ContentWidget", "\346\255\214\346\211\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("ContentWidget", "\344\270\223\350\276\221", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("ContentWidget", "\346\227\266\351\225\277", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QApplication::translate("ContentWidget", "\345\244\247\345\260\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ContentWidget", "\346\222\255\346\224\276\345\205\250\351\203\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ContentWidget: public Ui_ContentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTENTWIDGET_H
