#include "showsentences.h"
#include "ui_showsentences.h"

ShowSentences::ShowSentences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowSentences)
{
    ui->setupUi(this);
}

ShowSentences::~ShowSentences()
{
    delete ui;
}

void ShowSentences::on_Close_button_clicked()
{
    close();
}
