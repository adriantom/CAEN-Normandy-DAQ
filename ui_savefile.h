/********************************************************************************
** Form generated from reading UI file 'savefile.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEFILE_H
#define UI_SAVEFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_SaveFile
{
public:
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_OK;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_fileFormat;
    QTextBrowser *textBrowser_filePath;
    QPushButton *pushButton_selectFile;

    void setupUi(QDialog *SaveFile)
    {
        if (SaveFile->objectName().isEmpty())
            SaveFile->setObjectName(QStringLiteral("SaveFile"));
        SaveFile->resize(486, 315);
        pushButton_Cancel = new QPushButton(SaveFile);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(370, 250, 92, 36));
        pushButton_OK = new QPushButton(SaveFile);
        pushButton_OK->setObjectName(QStringLiteral("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(270, 250, 92, 36));
        label = new QLabel(SaveFile);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(19, 20, 151, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(SaveFile);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(19, 110, 141, 31));
        label_2->setFont(font);
        comboBox_fileFormat = new QComboBox(SaveFile);
        comboBox_fileFormat->setObjectName(QStringLiteral("comboBox_fileFormat"));
        comboBox_fileFormat->setGeometry(QRect(10, 140, 121, 36));
        textBrowser_filePath = new QTextBrowser(SaveFile);
        textBrowser_filePath->setObjectName(QStringLiteral("textBrowser_filePath"));
        textBrowser_filePath->setGeometry(QRect(9, 50, 381, 31));
        textBrowser_filePath->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser_filePath->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton_selectFile = new QPushButton(SaveFile);
        pushButton_selectFile->setObjectName(QStringLiteral("pushButton_selectFile"));
        pushButton_selectFile->setGeometry(QRect(400, 50, 71, 31));

        retranslateUi(SaveFile);

        QMetaObject::connectSlotsByName(SaveFile);
    } // setupUi

    void retranslateUi(QDialog *SaveFile)
    {
        SaveFile->setWindowTitle(QApplication::translate("SaveFile", "Saving file settings", Q_NULLPTR));
        pushButton_Cancel->setText(QApplication::translate("SaveFile", "Cancel", Q_NULLPTR));
        pushButton_OK->setText(QApplication::translate("SaveFile", "OK", Q_NULLPTR));
        label->setText(QApplication::translate("SaveFile", "Saving path:", Q_NULLPTR));
        label_2->setText(QApplication::translate("SaveFile", "File format:", Q_NULLPTR));
        comboBox_fileFormat->clear();
        comboBox_fileFormat->insertItems(0, QStringList()
         << QApplication::translate("SaveFile", "ROOT", Q_NULLPTR)
         << QApplication::translate("SaveFile", ".dat file", Q_NULLPTR)
        );
        pushButton_selectFile->setText(QApplication::translate("SaveFile", "Select...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SaveFile: public Ui_SaveFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEFILE_H
