#ifndef TRIGGER_CONFIGURATION_H
#define TRIGGER_CONFIGURATION_H

#include <QDialog>

namespace Ui {
class Trigger_Configuration;
}

class Trigger_Configuration : public QDialog
{
    Q_OBJECT

public:
    explicit Trigger_Configuration(QWidget *parent = 0);
    ~Trigger_Configuration();

private slots:
    void on_pushButton_TriggConfig_OK_clicked();

    void on_pushButton_TriggConfig_Cancel_clicked();

    void on_comboBox_SoftwareTriggerMode_currentIndexChanged(int index);

    void on_comboBox_ExternalTriggerInputMode_currentIndexChanged(int index);

    void on_comboBox_IOLevel_currentIndexChanged(int index);

    void on_RunSynchronizationMode_currentIndexChanged(int index);

    void on_comboBox_Channels_currentIndexChanged(int index);

    void on_checkBox_EveryChannel_clicked(bool checked);

    void on_comboBox_TriggerPolarity_currentIndexChanged(int index);

    void on_doubleSpinBox_ChannelTriggerThreshold_valueChanged(double arg1);

    void on_comboBox_ChannelSelfTrigger_currentIndexChanged(int index);

    void on_horizontalSlider_ChannelTriggerThreshold_valueChanged(int value);

signals:

    void setTrigSettings();

private:
    Ui::Trigger_Configuration *ui;
};

#endif // TRIGGER_CONFIGURATION_H
