#include "savefile.h"
#include "ui_savefile.h"
#include <iostream>
#include <QFileInfo>

using namespace std;


static QString filepath = "/home/adrian/Documents/example.dat";
static QString filepath_temp;

int fileFormat = 1;
// file format:
//      ROOT == 0
//      data file == 1;




SaveFile::SaveFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveFile)
{
    ui->setupUi(this);

    ui->textBrowser_filePath->append(filepath);
    ui->comboBox_fileFormat->setCurrentIndex(fileFormat);
}

SaveFile::~SaveFile()
{
    delete ui;
}


void SaveFile::on_pushButton_selectFile_clicked()
{

    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), "/home/", tr("All Files (*)"));

    ui->textBrowser_filePath->clear();
    ui->textBrowser_filePath->append(filename);
    filepath_temp = filename;

    cout << filename.toStdString() << endl;

}

void SaveFile::on_pushButton_OK_clicked()
{
    filepath = filepath_temp;
    QWidget::close();
}

void SaveFile::on_pushButton_Cancel_clicked()
{
    QWidget::close();
}

void SaveFile::on_comboBox_fileFormat_currentIndexChanged(int index)
{
    fileFormat = index;
    cout << fileFormat << endl;
}
