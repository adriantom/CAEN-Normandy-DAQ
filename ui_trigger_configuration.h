/********************************************************************************
** Form generated from reading UI file 'trigger_configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIGGER_CONFIGURATION_H
#define UI_TRIGGER_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Trigger_Configuration
{
public:
    QPushButton *pushButton_TriggConfig_OK;
    QPushButton *pushButton_TriggConfig_Cancel;
    QComboBox *comboBox_SoftwareTriggerMode;
    QLabel *label;
    QComboBox *comboBox_ExternalTriggerInputMode;
    QLabel *label_2;
    QComboBox *comboBox_ChannelSelfTrigger;
    QLabel *label_3;
    QPushButton *pushButton_TriggConfig_Load;
    QPushButton *pushButton_TriggConfig_Save;
    QSlider *horizontalSlider_ChannelTriggerThreshold;
    QLabel *label_5;
    QLabel *label_4;
    QComboBox *comboBox_IOLevel;
    QLabel *label_6;
    QComboBox *comboBox_TriggerPolarity;
    QDoubleSpinBox *doubleSpinBox_ChannelTriggerThreshold;
    QLabel *label_7;
    QComboBox *RunSynchronizationMode;
    QComboBox *comboBox_Channels;
    QLabel *label_8;
    QLabel *label_9;
    QCheckBox *checkBox_EveryChannel;

    void setupUi(QDialog *Trigger_Configuration)
    {
        if (Trigger_Configuration->objectName().isEmpty())
            Trigger_Configuration->setObjectName(QStringLiteral("Trigger_Configuration"));
        Trigger_Configuration->setEnabled(true);
        Trigger_Configuration->resize(500, 660);
        pushButton_TriggConfig_OK = new QPushButton(Trigger_Configuration);
        pushButton_TriggConfig_OK->setObjectName(QStringLiteral("pushButton_TriggConfig_OK"));
        pushButton_TriggConfig_OK->setGeometry(QRect(300, 610, 92, 36));
        pushButton_TriggConfig_Cancel = new QPushButton(Trigger_Configuration);
        pushButton_TriggConfig_Cancel->setObjectName(QStringLiteral("pushButton_TriggConfig_Cancel"));
        pushButton_TriggConfig_Cancel->setGeometry(QRect(400, 610, 92, 36));
        comboBox_SoftwareTriggerMode = new QComboBox(Trigger_Configuration);
        comboBox_SoftwareTriggerMode->setObjectName(QStringLiteral("comboBox_SoftwareTriggerMode"));
        comboBox_SoftwareTriggerMode->setGeometry(QRect(210, 70, 271, 31));
        label = new QLabel(Trigger_Configuration);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 69, 161, 31));
        comboBox_ExternalTriggerInputMode = new QComboBox(Trigger_Configuration);
        comboBox_ExternalTriggerInputMode->setObjectName(QStringLiteral("comboBox_ExternalTriggerInputMode"));
        comboBox_ExternalTriggerInputMode->setGeometry(QRect(210, 110, 271, 31));
        label_2 = new QLabel(Trigger_Configuration);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 110, 191, 31));
        comboBox_ChannelSelfTrigger = new QComboBox(Trigger_Configuration);
        comboBox_ChannelSelfTrigger->setObjectName(QStringLiteral("comboBox_ChannelSelfTrigger"));
        comboBox_ChannelSelfTrigger->setGeometry(QRect(210, 490, 271, 31));
        label_3 = new QLabel(Trigger_Configuration);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 490, 151, 31));
        pushButton_TriggConfig_Load = new QPushButton(Trigger_Configuration);
        pushButton_TriggConfig_Load->setObjectName(QStringLiteral("pushButton_TriggConfig_Load"));
        pushButton_TriggConfig_Load->setGeometry(QRect(20, 610, 131, 36));
        pushButton_TriggConfig_Save = new QPushButton(Trigger_Configuration);
        pushButton_TriggConfig_Save->setObjectName(QStringLiteral("pushButton_TriggConfig_Save"));
        pushButton_TriggConfig_Save->setGeometry(QRect(160, 610, 131, 36));
        horizontalSlider_ChannelTriggerThreshold = new QSlider(Trigger_Configuration);
        horizontalSlider_ChannelTriggerThreshold->setObjectName(QStringLiteral("horizontalSlider_ChannelTriggerThreshold"));
        horizontalSlider_ChannelTriggerThreshold->setGeometry(QRect(210, 440, 191, 21));
        horizontalSlider_ChannelTriggerThreshold->setMinimum(0);
        horizontalSlider_ChannelTriggerThreshold->setMaximum(2000);
        horizontalSlider_ChannelTriggerThreshold->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(Trigger_Configuration);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 440, 181, 31));
        label_4 = new QLabel(Trigger_Configuration);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 150, 81, 31));
        comboBox_IOLevel = new QComboBox(Trigger_Configuration);
        comboBox_IOLevel->setObjectName(QStringLiteral("comboBox_IOLevel"));
        comboBox_IOLevel->setGeometry(QRect(210, 150, 271, 31));
        label_6 = new QLabel(Trigger_Configuration);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 390, 111, 31));
        comboBox_TriggerPolarity = new QComboBox(Trigger_Configuration);
        comboBox_TriggerPolarity->setObjectName(QStringLiteral("comboBox_TriggerPolarity"));
        comboBox_TriggerPolarity->setGeometry(QRect(210, 390, 271, 31));
        doubleSpinBox_ChannelTriggerThreshold = new QDoubleSpinBox(Trigger_Configuration);
        doubleSpinBox_ChannelTriggerThreshold->setObjectName(QStringLiteral("doubleSpinBox_ChannelTriggerThreshold"));
        doubleSpinBox_ChannelTriggerThreshold->setGeometry(QRect(410, 440, 81, 31));
        doubleSpinBox_ChannelTriggerThreshold->setMinimum(0);
        doubleSpinBox_ChannelTriggerThreshold->setMaximum(2000);
        doubleSpinBox_ChannelTriggerThreshold->setSingleStep(1);
        label_7 = new QLabel(Trigger_Configuration);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 190, 181, 31));
        RunSynchronizationMode = new QComboBox(Trigger_Configuration);
        RunSynchronizationMode->setObjectName(QStringLiteral("RunSynchronizationMode"));
        RunSynchronizationMode->setGeometry(QRect(210, 190, 271, 31));
        comboBox_Channels = new QComboBox(Trigger_Configuration);
        comboBox_Channels->setObjectName(QStringLiteral("comboBox_Channels"));
        comboBox_Channels->setGeometry(QRect(360, 320, 121, 36));
        label_8 = new QLabel(Trigger_Configuration);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 10, 201, 31));
        QFont font;
        font.setPointSize(18);
        label_8->setFont(font);
        label_9 = new QLabel(Trigger_Configuration);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 270, 321, 31));
        label_9->setFont(font);
        checkBox_EveryChannel = new QCheckBox(Trigger_Configuration);
        checkBox_EveryChannel->setObjectName(QStringLiteral("checkBox_EveryChannel"));
        checkBox_EveryChannel->setGeometry(QRect(30, 330, 241, 26));

        retranslateUi(Trigger_Configuration);

        QMetaObject::connectSlotsByName(Trigger_Configuration);
    } // setupUi

    void retranslateUi(QDialog *Trigger_Configuration)
    {
        Trigger_Configuration->setWindowTitle(QApplication::translate("Trigger_Configuration", "Trigger Configuration", Q_NULLPTR));
        pushButton_TriggConfig_OK->setText(QApplication::translate("Trigger_Configuration", "OK", Q_NULLPTR));
        pushButton_TriggConfig_Cancel->setText(QApplication::translate("Trigger_Configuration", "Cancel", Q_NULLPTR));
        comboBox_SoftwareTriggerMode->clear();
        comboBox_SoftwareTriggerMode->insertItems(0, QStringList()
         << QApplication::translate("Trigger_Configuration", "DISABLED", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "TRIGGER OUTPUT", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "ACQUISITION TRIGGER", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "ACQUISITION & TRIGGER OUTPUT", Q_NULLPTR)
        );
        label->setText(QApplication::translate("Trigger_Configuration", "Software Trigger Mode", Q_NULLPTR));
        comboBox_ExternalTriggerInputMode->clear();
        comboBox_ExternalTriggerInputMode->insertItems(0, QStringList()
         << QApplication::translate("Trigger_Configuration", "DISABLED", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "TRIGGER OUTPUT", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "ACQUISITION TRIGGER", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "ACQUISITION & TRIGGER OUTPUT", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Trigger_Configuration", "External Trigger Input Mode", Q_NULLPTR));
        comboBox_ChannelSelfTrigger->clear();
        comboBox_ChannelSelfTrigger->insertItems(0, QStringList()
         << QApplication::translate("Trigger_Configuration", "DISABLED", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "TRIGGER OUTPUT", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "ACQUISITION TRIGGER", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "ACQUISITION & TRIGGER OUTPUT", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("Trigger_Configuration", "Channel Self-Trigger", Q_NULLPTR));
        pushButton_TriggConfig_Load->setText(QApplication::translate("Trigger_Configuration", "Load settings", Q_NULLPTR));
        pushButton_TriggConfig_Save->setText(QApplication::translate("Trigger_Configuration", "Save settings", Q_NULLPTR));
        label_5->setText(QApplication::translate("Trigger_Configuration", "Channel Trigger Threshold", Q_NULLPTR));
        label_4->setText(QApplication::translate("Trigger_Configuration", "I/O Level", Q_NULLPTR));
        comboBox_IOLevel->clear();
        comboBox_IOLevel->insertItems(0, QStringList()
         << QApplication::translate("Trigger_Configuration", "NIM", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "TTL", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("Trigger_Configuration", "Trigger Polarity", Q_NULLPTR));
        comboBox_TriggerPolarity->clear();
        comboBox_TriggerPolarity->insertItems(0, QStringList()
         << QApplication::translate("Trigger_Configuration", "Rising Edge", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "Falling Edge", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("Trigger_Configuration", "Run Synchronization Mode", Q_NULLPTR));
        RunSynchronizationMode->clear();
        RunSynchronizationMode->insertItems(0, QStringList()
         << QApplication::translate("Trigger_Configuration", "DISABLED", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "TRG-OUT / TRG-IN DAISY CHAIN", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "TRG-OUT / S-IN CONTROLLED", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "S-IN CONTROLLED", Q_NULLPTR)
        );
        comboBox_Channels->clear();
        comboBox_Channels->insertItems(0, QStringList()
         << QApplication::translate("Trigger_Configuration", "Channel 0", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "Channel 1", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "Channel 2", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "Channel 3", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "Channel 4", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "Channel 5", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "Channel 6", Q_NULLPTR)
         << QApplication::translate("Trigger_Configuration", "Channel 7", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("Trigger_Configuration", "General settings", Q_NULLPTR));
        label_9->setText(QApplication::translate("Trigger_Configuration", "Settings for selected channel", Q_NULLPTR));
        checkBox_EveryChannel->setText(QApplication::translate("Trigger_Configuration", "Same settings for every channel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Trigger_Configuration: public Ui_Trigger_Configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIGGER_CONFIGURATION_H
