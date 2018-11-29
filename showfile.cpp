#include "showfile.h"
#include "ui_showfile.h"
#include "mainwindow.h"
showfile::showfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showfile)
{
    ui->setupUi(this);

}

showfile::~showfile()
{
    delete ui;
}


void showfile::on_CloseWindow_clicked()
{
    close();
}
