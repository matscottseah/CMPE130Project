#ifndef SHOWFILE_H
#define SHOWFILE_H

#include <QDialog>

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

    void on_CloseWindow_clicked();

private:
    Ui::showfile *ui;



};

#endif // SHOWFILE_H
