#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include "stopwords.h"
#include <QTextEdit>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <QString>
#include <iostream>
#include <cstdlib>
#include "stdio.h"
#include <fstream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString UserString;
const    QString ProjectString;
public slots:
void openNewWindow();
void openStopWords();
private slots:
    void on_ClearButton_clicked();

    void on_SubmitButton_clicked();

    void on_Exitprog_clicked();

    void on_DisplayStop_clicked();

    void open_file(QString NameOfFile);

    void save_into_user();

    void Lowercase(QString& input);

    void DestroyWhiteSpace(QString& string);

    QString read(QString into, QString out);

private:
    Ui::MainWindow *ui;
    QString UserFileName;
    QString ProjectFileName;
    Form    *New_window;
    StopWords *StopWordsWindow;

};

#endif // MAINWINDOW_H
