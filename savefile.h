#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class SaveFile;
}

class SaveFile : public QDialog
{
    Q_OBJECT

public:
    explicit SaveFile(QWidget *parent = 0);
    ~SaveFile();

private slots:
    void on_pushButton_selectFile_clicked();

    void on_pushButton_OK_clicked();

    void on_pushButton_Cancel_clicked();

    void on_comboBox_fileFormat_currentIndexChanged(int index);

private:
    Ui::SaveFile *ui;
};

#endif // SAVEFILE_H
