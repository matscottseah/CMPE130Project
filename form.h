#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <showfile.h>
#include <QTextStream>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public slots:

private slots:

    QString open_file(QString NameOfFile, QString text);

    void on_close_button_clicked();

private:
    Ui::Form *ui;
    QString projectfile;
    QString txt;
};

#endif // FORM_H
