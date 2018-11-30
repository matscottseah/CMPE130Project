#ifndef SHOWFILE_H
#define SHOWFILE_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
namespace Ui {
class showfile;
}

class showfile : public QDialog
{
    Q_OBJECT

public:
    explicit showfile(QWidget *parent = nullptr);
    ~showfile();

private slots:

    QString open_file(QString NameOfFile,QString text);

    void on_CloseWindow_clicked();

private:
    Ui::showfile *ui;

    QString projectfile;
    QString txt;

};

#endif // SHOWFILE_H
