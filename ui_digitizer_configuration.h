/********************************************************************************
** Form generated from reading UI file 'digitizer_configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGITIZER_CONFIGURATION_H
#define UI_DIGITIZER_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Digitizer_Configuration
{
public:
    QPushButton *pushButton_DigConfig_OK;
    QPushButton *pushButton_DigConfig_Cancel;
    QPushButton *pushButton_DigConfig_Load;
    QPushButton *pushButton_DigConfig_Save;
    QLabel *label;
    QLabel *label_9;
    QLabel *label_2;
    QComboBox *comboBox_ChannelEnableMask;
    QLabel *label_3;
    QSpinBox *spinBox_RecordLength;
    QLabel *label_4;
    QSpinBox *spinBox_PostTriggSize;
    QLabel *label_5;
    QComboBox *comboBox_AcquisitionMode;
    QComboBox *comboBox_Channels;
    QCheckBox *checkBox_EveryChannel;
    QLabel *label_6;
    QSpinBox *spinBox_ChannelDCOffset;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *comboBox_DESM;
    QComboBox *comboBox_DecimationFactor;

    void setupUi(QDialog *Digitizer_Configuration)
    {
        if (Digitizer_Configuration->objectName().isEmpty())
            Digitizer_Configuration->setObjectName(QStringLiteral("Digitizer_Configuration"));
        Digitizer_Configuration->resize(500, 660);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Digitizer_Configuration->sizePolicy().hasHeightForWidth());
        Digitizer_Configuration->setSizePolicy(sizePolicy);
        Digitizer_Configuration->setMinimumSize(QSize(500, 660));
        Digitizer_Configuration->setMaximumSize(QSize(500, 660));
        pushButton_DigConfig_OK = new QPushButton(Digitizer_Configuration);
        pushButton_DigConfig_OK->setObjectName(QStringLiteral("pushButton_DigConfig_OK"));
        pushButton_DigConfig_OK->setGeometry(QRect(290, 610, 92, 36));
        pushButton_DigConfig_Cancel = new QPushButton(Digitizer_Configuration);
        pushButton_DigConfig_Cancel->setObjectName(QStringLiteral("pushButton_DigConfig_Cancel"));
        pushButton_DigConfig_Cancel->setGeometry(QRect(390, 610, 92, 36));
        pushButton_DigConfig_Load = new QPushButton(Digitizer_Configuration);
        pushButton_DigConfig_Load->setObjectName(QStringLiteral("pushButton_DigConfig_Load"));
        pushButton_DigConfig_Load->setGeometry(QRect(10, 610, 131, 36));
        pushButton_DigConfig_Save = new QPushButton(Digitizer_Configuration);
        pushButton_DigConfig_Save->setObjectName(QStringLiteral("pushButton_DigConfig_Save"));
        pushButton_DigConfig_Save->setGeometry(QRect(150, 610, 131, 36));
        label = new QLabel(Digitizer_Configuration);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 201, 31));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label_9 = new QLabel(Digitizer_Configuration);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(70, 300, 321, 31));
        label_9->setFont(font);
        label_2 = new QLabel(Digitizer_Configuration);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 470, 141, 31));
        comboBox_ChannelEnableMask = new QComboBox(Digitizer_Configuration);
        comboBox_ChannelEnableMask->setObjectName(QStringLiteral("comboBox_ChannelEnableMask"));
        comboBox_ChannelEnableMask->setGeometry(QRect(260, 470, 221, 31));
        label_3 = new QLabel(Digitizer_Configuration);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 430, 121, 31));
        spinBox_RecordLength = new QSpinBox(Digitizer_Configuration);
        spinBox_RecordLength->setObjectName(QStringLiteral("spinBox_RecordLength"));
        spinBox_RecordLength->setGeometry(QRect(260, 430, 221, 31));
        spinBox_RecordLength->setMaximum(10000);
        label_4 = new QLabel(Digitizer_Configuration);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 80, 141, 31));
        spinBox_PostTriggSize = new QSpinBox(Digitizer_Configuration);
        spinBox_PostTriggSize->setObjectName(QStringLiteral("spinBox_PostTriggSize"));
        spinBox_PostTriggSize->setGeometry(QRect(260, 80, 221, 31));
        spinBox_PostTriggSize->setMaximum(100);
        label_5 = new QLabel(Digitizer_Configuration);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 120, 131, 31));
        comboBox_AcquisitionMode = new QComboBox(Digitizer_Configuration);
        comboBox_AcquisitionMode->setObjectName(QStringLiteral("comboBox_AcquisitionMode"));
        comboBox_AcquisitionMode->setGeometry(QRect(260, 120, 221, 31));
        comboBox_Channels = new QComboBox(Digitizer_Configuration);
        comboBox_Channels->setObjectName(QStringLiteral("comboBox_Channels"));
        comboBox_Channels->setGeometry(QRect(360, 360, 121, 36));
        checkBox_EveryChannel = new QCheckBox(Digitizer_Configuration);
        checkBox_EveryChannel->setObjectName(QStringLiteral("checkBox_EveryChannel"));
        checkBox_EveryChannel->setGeometry(QRect(30, 370, 241, 26));
        label_6 = new QLabel(Digitizer_Configuration);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 510, 151, 31));
        spinBox_ChannelDCOffset = new QSpinBox(Digitizer_Configuration);
        spinBox_ChannelDCOffset->setObjectName(QStringLiteral("spinBox_ChannelDCOffset"));
        spinBox_ChannelDCOffset->setGeometry(QRect(260, 510, 221, 31));
        spinBox_ChannelDCOffset->setMaximum(65535);
        label_7 = new QLabel(Digitizer_Configuration);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 160, 181, 31));
        label_8 = new QLabel(Digitizer_Configuration);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 199, 151, 31));
        comboBox_DESM = new QComboBox(Digitizer_Configuration);
        comboBox_DESM->setObjectName(QStringLiteral("comboBox_DESM"));
        comboBox_DESM->setGeometry(QRect(260, 160, 221, 31));
        comboBox_DecimationFactor = new QComboBox(Digitizer_Configuration);
        comboBox_DecimationFactor->setObjectName(QStringLiteral("comboBox_DecimationFactor"));
        comboBox_DecimationFactor->setGeometry(QRect(260, 200, 221, 31));

        retranslateUi(Digitizer_Configuration);

        QMetaObject::connectSlotsByName(Digitizer_Configuration);
    } // setupUi

    void retranslateUi(QDialog *Digitizer_Configuration)
    {
        Digitizer_Configuration->setWindowTitle(QApplication::translate("Digitizer_Configuration", "Acquisition Configuration", Q_NULLPTR));
        pushButton_DigConfig_OK->setText(QApplication::translate("Digitizer_Configuration", "OK", Q_NULLPTR));
        pushButton_DigConfig_Cancel->setText(QApplication::translate("Digitizer_Configuration", "Cancel", Q_NULLPTR));
        pushButton_DigConfig_Load->setText(QApplication::translate("Digitizer_Configuration", "Load settings", Q_NULLPTR));
        pushButton_DigConfig_Save->setText(QApplication::translate("Digitizer_Configuration", "Save settings", Q_NULLPTR));
        label->setText(QApplication::translate("Digitizer_Configuration", "General settings", Q_NULLPTR));
        label_9->setText(QApplication::translate("Digitizer_Configuration", "Settings for selected channel", Q_NULLPTR));
        label_2->setText(QApplication::translate("Digitizer_Configuration", "Channel Enable Mask", Q_NULLPTR));
        comboBox_ChannelEnableMask->clear();
        comboBox_ChannelEnableMask->insertItems(0, QStringList()
         << QApplication::translate("Digitizer_Configuration", "DISABLE", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "ENABLE", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("Digitizer_Configuration", "Record Length", Q_NULLPTR));
        label_4->setText(QApplication::translate("Digitizer_Configuration", "Post Trigger Size (%)", Q_NULLPTR));
        label_5->setText(QApplication::translate("Digitizer_Configuration", "Acquisition Mode", Q_NULLPTR));
        comboBox_AcquisitionMode->clear();
        comboBox_AcquisitionMode->insertItems(0, QStringList()
         << QApplication::translate("Digitizer_Configuration", "SOFTWARE CONTROLLED", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "S-IN CONTROLLED", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "FIRST TRG CONTROLLED", Q_NULLPTR)
        );
        comboBox_Channels->clear();
        comboBox_Channels->insertItems(0, QStringList()
         << QApplication::translate("Digitizer_Configuration", "Channel 0", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "Channel 1", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "Channel 2", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "Channel 3", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "Channel 4", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "Channel 5", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "Channel 6", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "Channel 7", Q_NULLPTR)
        );
        checkBox_EveryChannel->setText(QApplication::translate("Digitizer_Configuration", "Same settings for every channel", Q_NULLPTR));
        label_6->setText(QApplication::translate("Digitizer_Configuration", "Channel DC Offset", Q_NULLPTR));
        label_7->setText(QApplication::translate("Digitizer_Configuration", "Dual Edge Sampling Mode", Q_NULLPTR));
        label_8->setText(QApplication::translate("Digitizer_Configuration", "Decimation Factor", Q_NULLPTR));
        comboBox_DESM->clear();
        comboBox_DESM->insertItems(0, QStringList()
         << QApplication::translate("Digitizer_Configuration", "ENABLE", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "DISABLE", Q_NULLPTR)
        );
        comboBox_DecimationFactor->clear();
        comboBox_DecimationFactor->insertItems(0, QStringList()
         << QApplication::translate("Digitizer_Configuration", "1", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "2", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "4", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "8", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "16", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "32", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "64", Q_NULLPTR)
         << QApplication::translate("Digitizer_Configuration", "128", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class Digitizer_Configuration: public Ui_Digitizer_Configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGITIZER_CONFIGURATION_H
