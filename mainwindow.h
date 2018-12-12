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
#include <form.h>
#include <QSet>
#include <set>
#include <QRegExp>
#include <QList>
#include <Qt>
#include <QMap>
#include <QChar>

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
    QString UserStringRevised;
    QString ProjectString;
    QString ProjectStringRevised;
    QSet<QString> Stopwords;

    int ProjectWordCount; //USE THIS IN AN INT FUNCTION TO RETURN THE COUNT AND CONVERT THE INT TO A QSTRING WILL BE USED TO DIVIDE LATER
    int RevisedProjectWordCount;
    QString ProjectCount; //USE THIS TO DISPLAY
    QString RevisedProjectCount;

    int UserWordCount; //USE THIS IN AN INT FUNCTION TO RETURN THE COUNT AND CONVERT THE INT TO A QSTRING
    int RevisedUserWordCount;
    QString UserCount; //DISPLAY
    QString RevisedUserCount;

    QString UserFileName;
    QString ProjectFileName;
    QString UserFileRevisedName;
    QString ProjectFileRevisedName;

    char* User;
    char* Project;


public slots:
    void openNewWindow();
    void openStopWords();

private slots:
    void on_ClearButton_clicked();
    void on_SubmitButton_clicked();
    void on_Exitprog_clicked();
    void on_DisplayStop_clicked();
    void save_into_file(QString& input);
    void Lowercase( QString& input);
    void DestroyWhiteSpace( QString& string);
    void RemoveStopWords(QString &input, QString& output);
    int GetWordCount(QString& into);
    void CreateCharArr(QString& UserInput, QString& ProjOutput, QString& Origin);
    void computeLPSArray(QString pat, int M, int* lps);
    int KMPSearch(QString pat, QString txt);
    void ourKMP(QList<QString>testList, QList<QString>userList, QList<QString>originalUserList);


private:
    Ui::MainWindow *ui;
    Form *New_window;
    StopWords *StopWordsWindow;
};

#endif // MAINWINDOW_H
