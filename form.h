#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <showsentences.h>
#include <showfile.h>

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
    void opensentencewindow();
    void locatefile();

private slots:
    void on_show_sentences_clicked();

    void on_close_button_clicked();

    void on_show_file_clicked();

private:
    Ui::Form *ui;
    ShowSentences *sentenceWindow;
    showfile *fileWindow;
};

#endif // FORM_H
