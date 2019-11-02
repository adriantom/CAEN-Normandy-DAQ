#ifndef DIGITIZER_CONFIGURATION_H
#define DIGITIZER_CONFIGURATION_H

#include <QDialog>

namespace Ui {
class Digitizer_Configuration;
}

class Digitizer_Configuration : public QDialog
{
    Q_OBJECT

public:
    explicit Digitizer_Configuration(QWidget *parent = 0);
    ~Digitizer_Configuration();
    Ui::Digitizer_Configuration *uiDC;

private slots:
    void on_pushButton_DigConfig_Cancel_clicked();

    void on_pushButton_DigConfig_OK_clicked();

    void on_spinBox_PostTriggSize_valueChanged(int arg1);

    void on_comboBox_AcquisitionMode_currentIndexChanged(int index);


    void on_comboBox_DESM_currentIndexChanged(int index);

    void on_comboBox_DecimationFactor_currentIndexChanged(int index);

    void on_comboBox_Channels_currentIndexChanged(int index);

    void on_spinBox_RecordLength_valueChanged(int arg1);

    void on_comboBox_ChannelEnableMask_currentIndexChanged(int index);

//    void on_doubleSpinBox_ChannelDCOffset_valueChanged(double arg1);

    void on_pushButton_DigConfig_Load_clicked();

    void on_checkBox_EveryChannel_clicked(bool checked);

    void on_spinBox_ChannelDCOffset_valueChanged(int arg1);


signals:
    void setDigiSettings();

private:
    Ui::Digitizer_Configuration *ui;
};

#endif // DIGITIZER_CONFIGURATION_H
