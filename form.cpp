#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    projectfile = "/Users/jacksontruong/Qt/ComputerEngineering130/ProjectFile";
    ui->textEdit->setText(open_file(projectfile,txt));
}

Form::~Form()
{
    delete ui;
}

QString Form::open_file(QString NameOfFile,QString text)
{
    QFile file(NameOfFile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        exit(1);
    }

    QTextStream textStream(&file);
    QStringList hi;
    while(!textStream.atEnd())
    {
        hi<<textStream.readLine();
    }
    text = hi.join(" ");
    file.close();
    return text;
}

void Form::on_close_button_clicked()
{
    close();
}

