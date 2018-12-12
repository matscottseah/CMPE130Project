#ifndef STOPWORDS_H
#define STOPWORDS_H

#include <QWidget>

namespace Ui {
    class StopWords;
}

class StopWords:public QWidget
{
    Q_OBJECT

public:
    explicit StopWords(QWidget *parent = nullptr);
    ~StopWords();

private slots:
    void on_CloseButton_clicked();

private:
    Ui::StopWords *ui;
};

#endif // STOPWORDS_H
