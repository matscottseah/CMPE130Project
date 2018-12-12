#ifndef SHOWSENTENCES_H
#define SHOWSENTENCES_H

#include <QDialog>

namespace Ui {
class ShowSentences;
}

class ShowSentences : public QDialog
{
    Q_OBJECT

public:
    explicit ShowSentences(QWidget *parent = nullptr);
    ~ShowSentences();

private slots:
    void on_Close_button_clicked();

private:
    Ui::ShowSentences *ui;
};

#endif // SHOWSENTENCES_H
