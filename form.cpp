#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

}

Form::~Form()
{
    delete ui;
}
void Form::opensentencewindow(){
    sentenceWindow = new ShowSentences();
    sentenceWindow->show();
}

void Form::locatefile()
{
    fileWindow = new showfile();
    fileWindow->show();
}
void Form::on_show_sentences_clicked()
{
    Form::opensentencewindow();
}

void Form::on_show_file_clicked()
{
    Form::locatefile();
}

void Form::on_close_button_clicked()
{
    close();
}

