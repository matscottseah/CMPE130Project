#include "showfile.h"
#include "ui_showfile.h"
showfile::showfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showfile)
{
    ui->setupUi(this);
    projectfile="/Users/jacksontruong/Qt/AAAAAAAAAAAAAAAAAAAAAAAA/ProjectFile";
    ui->textEdit->setText(open_file(projectfile,txt));


}

showfile::~showfile()
{
    delete ui;
}


QString showfile::open_file(QString NameOfFile,QString text){
    QFile file(NameOfFile);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        exit(1);
    }
    QTextStream textStream(&file);
    QStringList hi;
    while(!textStream.atEnd()){
        hi<<textStream.readLine();
    }
    text = hi.join(" ");
    file.close();
    return text;
}


void showfile::on_CloseWindow_clicked()
{
    close();
}
