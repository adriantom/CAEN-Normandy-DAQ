/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDigitizer_configuration;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionManual;
    QAction *actionAbout;
    QAction *actionTrigger_configuration;
    QAction *actionContext_help;
    QWidget *centralWidget;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Stop;
    QTextBrowser *textBrowser_AppLogs;
    QPushButton *pushButton_GetInfo;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Calibrate;
    QPushButton *pushButton_Reset;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCustomPlot *widget_HistogramPlot;
    QPushButton *pushButton;
    QCheckBox *checkBox_HistogramChannel4;
    QCheckBox *checkBox_HistogramChannel5;
    QCheckBox *checkBox_HistogramChannel3;
    QCheckBox *checkBox_HistogramChannel2;
    QCheckBox *checkBox_HistogramChannel1;
    QCheckBox *checkBox_HistogramChannel7;
    QCheckBox *checkBox_HistogramChannel0;
    QCheckBox *checkBox_HistogramChannel6;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_5;
    QCheckBox *checkBox_logaritmicScale;
    QWidget *tab_2;
    QCustomPlot *widget_SignalPlot;
    QCheckBox *checkBox_SignalChannel0;
    QCheckBox *checkBox_SignalChannel1;
    QCheckBox *checkBox_SignalChannel2;
    QCheckBox *checkBox_SignalChannel3;
    QCheckBox *checkBox_SignalChannel4;
    QCheckBox *checkBox_SignalChannel5;
    QCheckBox *checkBox_SignalChannel6;
    QCheckBox *checkBox_SignalChannel7;
    QPushButton *pushButton_ClearPlot;
    QLabel *label;
    QPushButton *pushButton_autoscale;
    QLabel *label_Temperature;
    QLabel *label_BoardStatus;
    QLabel *label_boardStatusAns;
    QLabel *label_temperatureAns;
    QPushButton *pushButton_calibrateDCO;
    QPushButton *pushButton_restart;
    QPushButton *pushButton_readTemp;
    QTimeEdit *timeEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1300, 800);
        MainWindow->setMinimumSize(QSize(1300, 800));
        MainWindow->setMaximumSize(QSize(1300, 800));
        actionDigitizer_configuration = new QAction(MainWindow);
        actionDigitizer_configuration->setObjectName(QStringLiteral("actionDigitizer_configuration"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionManual = new QAction(MainWindow);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionTrigger_configuration = new QAction(MainWindow);
        actionTrigger_configuration->setObjectName(QStringLiteral("actionTrigger_configuration"));
        actionContext_help = new QAction(MainWindow);
        actionContext_help->setObjectName(QStringLiteral("actionContext_help"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_Start = new QPushButton(centralWidget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(10, 10, 141, 51));
        pushButton_Stop = new QPushButton(centralWidget);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));
        pushButton_Stop->setGeometry(QRect(160, 10, 141, 51));
        textBrowser_AppLogs = new QTextBrowser(centralWidget);
        textBrowser_AppLogs->setObjectName(QStringLiteral("textBrowser_AppLogs"));
        textBrowser_AppLogs->setGeometry(QRect(10, 220, 601, 511));
        pushButton_GetInfo = new QPushButton(centralWidget);
        pushButton_GetInfo->setObjectName(QStringLiteral("pushButton_GetInfo"));
        pushButton_GetInfo->setGeometry(QRect(10, 180, 92, 36));
        pushButton_Clear = new QPushButton(centralWidget);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(510, 180, 92, 36));
        pushButton_Calibrate = new QPushButton(centralWidget);
        pushButton_Calibrate->setObjectName(QStringLiteral("pushButton_Calibrate"));
        pushButton_Calibrate->setGeometry(QRect(110, 180, 92, 36));
        pushButton_Reset = new QPushButton(centralWidget);
        pushButton_Reset->setObjectName(QStringLiteral("pushButton_Reset"));
        pushButton_Reset->setGeometry(QRect(210, 180, 92, 36));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(610, 0, 681, 731));
        tabWidget->setMaximumSize(QSize(1300, 16777215));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        widget_HistogramPlot = new QCustomPlot(tab);
        widget_HistogramPlot->setObjectName(QStringLiteral("widget_HistogramPlot"));
        widget_HistogramPlot->setGeometry(QRect(10, 10, 651, 491));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(541, 510, 121, 36));
        checkBox_HistogramChannel4 = new QCheckBox(tab);
        checkBox_HistogramChannel4->setObjectName(QStringLiteral("checkBox_HistogramChannel4"));
        checkBox_HistogramChannel4->setGeometry(QRect(120, 560, 93, 26));
        checkBox_HistogramChannel5 = new QCheckBox(tab);
        checkBox_HistogramChannel5->setObjectName(QStringLiteral("checkBox_HistogramChannel5"));
        checkBox_HistogramChannel5->setGeometry(QRect(120, 590, 93, 26));
        checkBox_HistogramChannel3 = new QCheckBox(tab);
        checkBox_HistogramChannel3->setObjectName(QStringLiteral("checkBox_HistogramChannel3"));
        checkBox_HistogramChannel3->setGeometry(QRect(0, 650, 93, 26));
        checkBox_HistogramChannel2 = new QCheckBox(tab);
        checkBox_HistogramChannel2->setObjectName(QStringLiteral("checkBox_HistogramChannel2"));
        checkBox_HistogramChannel2->setGeometry(QRect(0, 620, 93, 26));
        checkBox_HistogramChannel1 = new QCheckBox(tab);
        checkBox_HistogramChannel1->setObjectName(QStringLiteral("checkBox_HistogramChannel1"));
        checkBox_HistogramChannel1->setGeometry(QRect(0, 590, 93, 26));
        checkBox_HistogramChannel7 = new QCheckBox(tab);
        checkBox_HistogramChannel7->setObjectName(QStringLiteral("checkBox_HistogramChannel7"));
        checkBox_HistogramChannel7->setGeometry(QRect(120, 650, 93, 26));
        checkBox_HistogramChannel0 = new QCheckBox(tab);
        checkBox_HistogramChannel0->setObjectName(QStringLiteral("checkBox_HistogramChannel0"));
        checkBox_HistogramChannel0->setGeometry(QRect(0, 560, 93, 26));
        checkBox_HistogramChannel6 = new QCheckBox(tab);
        checkBox_HistogramChannel6->setObjectName(QStringLiteral("checkBox_HistogramChannel6"));
        checkBox_HistogramChannel6->setGeometry(QRect(120, 620, 93, 26));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 520, 201, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(540, 640, 121, 31));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(540, 610, 121, 20));
        checkBox_logaritmicScale = new QCheckBox(tab);
        checkBox_logaritmicScale->setObjectName(QStringLiteral("checkBox_logaritmicScale"));
        checkBox_logaritmicScale->setGeometry(QRect(390, 520, 141, 26));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        widget_SignalPlot = new QCustomPlot(tab_2);
        widget_SignalPlot->setObjectName(QStringLiteral("widget_SignalPlot"));
        widget_SignalPlot->setGeometry(QRect(10, 10, 651, 491));
        checkBox_SignalChannel0 = new QCheckBox(tab_2);
        checkBox_SignalChannel0->setObjectName(QStringLiteral("checkBox_SignalChannel0"));
        checkBox_SignalChannel0->setGeometry(QRect(0, 560, 93, 26));
        checkBox_SignalChannel1 = new QCheckBox(tab_2);
        checkBox_SignalChannel1->setObjectName(QStringLiteral("checkBox_SignalChannel1"));
        checkBox_SignalChannel1->setGeometry(QRect(0, 590, 93, 26));
        checkBox_SignalChannel2 = new QCheckBox(tab_2);
        checkBox_SignalChannel2->setObjectName(QStringLiteral("checkBox_SignalChannel2"));
        checkBox_SignalChannel2->setGeometry(QRect(0, 620, 93, 26));
        checkBox_SignalChannel3 = new QCheckBox(tab_2);
        checkBox_SignalChannel3->setObjectName(QStringLiteral("checkBox_SignalChannel3"));
        checkBox_SignalChannel3->setGeometry(QRect(0, 650, 93, 26));
        checkBox_SignalChannel4 = new QCheckBox(tab_2);
        checkBox_SignalChannel4->setObjectName(QStringLiteral("checkBox_SignalChannel4"));
        checkBox_SignalChannel4->setGeometry(QRect(120, 560, 93, 26));
        checkBox_SignalChannel5 = new QCheckBox(tab_2);
        checkBox_SignalChannel5->setObjectName(QStringLiteral("checkBox_SignalChannel5"));
        checkBox_SignalChannel5->setGeometry(QRect(120, 590, 93, 26));
        checkBox_SignalChannel6 = new QCheckBox(tab_2);
        checkBox_SignalChannel6->setObjectName(QStringLiteral("checkBox_SignalChannel6"));
        checkBox_SignalChannel6->setGeometry(QRect(120, 620, 93, 26));
        checkBox_SignalChannel7 = new QCheckBox(tab_2);
        checkBox_SignalChannel7->setObjectName(QStringLiteral("checkBox_SignalChannel7"));
        checkBox_SignalChannel7->setGeometry(QRect(120, 650, 93, 26));
        pushButton_ClearPlot = new QPushButton(tab_2);
        pushButton_ClearPlot->setObjectName(QStringLiteral("pushButton_ClearPlot"));
        pushButton_ClearPlot->setGeometry(QRect(541, 510, 121, 36));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 520, 201, 31));
        label->setFont(font);
        pushButton_autoscale = new QPushButton(tab_2);
        pushButton_autoscale->setObjectName(QStringLiteral("pushButton_autoscale"));
        pushButton_autoscale->setGeometry(QRect(540, 630, 121, 36));
        tabWidget->addTab(tab_2, QString());
        label_Temperature = new QLabel(centralWidget);
        label_Temperature->setObjectName(QStringLiteral("label_Temperature"));
        label_Temperature->setGeometry(QRect(310, 31, 121, 31));
        QFont font1;
        font1.setPointSize(14);
        label_Temperature->setFont(font1);
        label_BoardStatus = new QLabel(centralWidget);
        label_BoardStatus->setObjectName(QStringLiteral("label_BoardStatus"));
        label_BoardStatus->setGeometry(QRect(310, 11, 111, 31));
        label_BoardStatus->setFont(font1);
        label_boardStatusAns = new QLabel(centralWidget);
        label_boardStatusAns->setObjectName(QStringLiteral("label_boardStatusAns"));
        label_boardStatusAns->setGeometry(QRect(430, 10, 151, 31));
        label_temperatureAns = new QLabel(centralWidget);
        label_temperatureAns->setObjectName(QStringLiteral("label_temperatureAns"));
        label_temperatureAns->setGeometry(QRect(430, 30, 181, 31));
        pushButton_calibrateDCO = new QPushButton(centralWidget);
        pushButton_calibrateDCO->setObjectName(QStringLiteral("pushButton_calibrateDCO"));
        pushButton_calibrateDCO->setGeometry(QRect(110, 130, 92, 36));
        pushButton_restart = new QPushButton(centralWidget);
        pushButton_restart->setObjectName(QStringLiteral("pushButton_restart"));
        pushButton_restart->setGeometry(QRect(210, 130, 92, 36));
        pushButton_readTemp = new QPushButton(centralWidget);
        pushButton_readTemp->setObjectName(QStringLiteral("pushButton_readTemp"));
        pushButton_readTemp->setGeometry(QRect(10, 130, 92, 36));
        timeEdit = new QTimeEdit(centralWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(10, 70, 141, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 28));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuSettings->addAction(actionDigitizer_configuration);
        menuSettings->addAction(actionTrigger_configuration);
        menuHelp->addAction(actionManual);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_Stop, SIGNAL(clicked(bool)), pushButton_Start, SLOT(setChecked(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionDigitizer_configuration->setText(QApplication::translate("MainWindow", "Acquisition configuration", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("MainWindow", "Saving file", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionManual->setText(QApplication::translate("MainWindow", "Manual", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionTrigger_configuration->setText(QApplication::translate("MainWindow", "Trigger configuration", Q_NULLPTR));
        actionContext_help->setText(QApplication::translate("MainWindow", "Context help", Q_NULLPTR));
        pushButton_Start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        pushButton_Stop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        textBrowser_AppLogs->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hello!</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Welcome to CAEN Normandy - data acquisition program for CAEN x730 series devices.</p></body></html>", Q_NULLPTR));
        pushButton_GetInfo->setText(QApplication::translate("MainWindow", "Get Info", Q_NULLPTR));
        pushButton_Clear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        pushButton_Calibrate->setText(QApplication::translate("MainWindow", "Calibrate", Q_NULLPTR));
        pushButton_Reset->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Clear histogram", Q_NULLPTR));
        checkBox_HistogramChannel4->setText(QApplication::translate("MainWindow", "Channel 4", Q_NULLPTR));
        checkBox_HistogramChannel5->setText(QApplication::translate("MainWindow", "Channel 5", Q_NULLPTR));
        checkBox_HistogramChannel3->setText(QApplication::translate("MainWindow", "Channel 3", Q_NULLPTR));
        checkBox_HistogramChannel2->setText(QApplication::translate("MainWindow", "Channel 2", Q_NULLPTR));
        checkBox_HistogramChannel1->setText(QApplication::translate("MainWindow", "Channel 1", Q_NULLPTR));
        checkBox_HistogramChannel7->setText(QApplication::translate("MainWindow", "Channel 7", Q_NULLPTR));
        checkBox_HistogramChannel0->setText(QApplication::translate("MainWindow", "Channel 0", Q_NULLPTR));
        checkBox_HistogramChannel6->setText(QApplication::translate("MainWindow", "Channel 6", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Display signal from:", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Peak", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Integral", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("MainWindow", "Histogram values", Q_NULLPTR));
        checkBox_logaritmicScale->setText(QApplication::translate("MainWindow", "Logaritmic Scale", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Histogram", Q_NULLPTR));
        checkBox_SignalChannel0->setText(QApplication::translate("MainWindow", "Channel 0", Q_NULLPTR));
        checkBox_SignalChannel1->setText(QApplication::translate("MainWindow", "Channel 1", Q_NULLPTR));
        checkBox_SignalChannel2->setText(QApplication::translate("MainWindow", "Channel 2", Q_NULLPTR));
        checkBox_SignalChannel3->setText(QApplication::translate("MainWindow", "Channel 3", Q_NULLPTR));
        checkBox_SignalChannel4->setText(QApplication::translate("MainWindow", "Channel 4", Q_NULLPTR));
        checkBox_SignalChannel5->setText(QApplication::translate("MainWindow", "Channel 5", Q_NULLPTR));
        checkBox_SignalChannel6->setText(QApplication::translate("MainWindow", "Channel 6", Q_NULLPTR));
        checkBox_SignalChannel7->setText(QApplication::translate("MainWindow", "Channel 7", Q_NULLPTR));
        pushButton_ClearPlot->setText(QApplication::translate("MainWindow", "Clear Plot", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Display signal from:", Q_NULLPTR));
        pushButton_autoscale->setText(QApplication::translate("MainWindow", "Autoscale", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Signal", Q_NULLPTR));
        label_Temperature->setText(QApplication::translate("MainWindow", "Temperature:", Q_NULLPTR));
        label_BoardStatus->setText(QApplication::translate("MainWindow", "Board status:", Q_NULLPTR));
        label_boardStatusAns->setText(QApplication::translate("MainWindow", "Waiting", Q_NULLPTR));
        label_temperatureAns->setText(QApplication::translate("MainWindow", "0, 0, 0, 0, 0 ,0 ,0 , 0", Q_NULLPTR));
        pushButton_calibrateDCO->setText(QApplication::translate("MainWindow", "Cal. DCO", Q_NULLPTR));
        pushButton_restart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        pushButton_readTemp->setText(QApplication::translate("MainWindow", "Read temp.", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
