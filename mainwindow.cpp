#include "mainwindow.h"
#include "ui_mainwindow.h"
//std::cout << FUNCNAME.toUtf8().constData() << std::endl

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UserFileName="/Users/jacksontruong/Qt/AAAAAAAAAAAAAAAAAAAAAAAA/UserFile";
    ProjectFileName="/Users/jacksontruong/Qt/AAAAAAAAAAAAAAAAAAAAAAAA/ProjectFile";
    UserString = "";
    ProjectString == "";

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openNewWindow(){//maybe in this function we can the information to it
    New_window = new Form();
    New_window->show();
}
void MainWindow::openStopWords(){
    StopWordsWindow = new StopWords();
    StopWordsWindow->show();
}

void MainWindow::save_into_user(){
    QFile sFile(UserFileName);//the next 6 lines help save the Qtextedit information into the  user text file
    if(sFile.open(QFile::WriteOnly|QFile::Text)){
        QTextStream out(&sFile);
        out<< ui->Userinput->toPlainText();
        sFile.flush();
        sFile.close();
    }
}

void MainWindow::Lowercase(QString& input){ // HAVENT USED THIS YET NEED TO MAKE FUNCTIONS TO OPEN FILES AND STORE THEM INTO A QSTRING
    std::string Hello;
    Hello = input.toStdString();
    for(int i=0; i<Hello.size();i++){
        if(isupper(Hello[i])){
            Hello[i]=tolower(Hello[i]);
        }
    }
    input = QString::fromStdString(Hello);
//    QString lower = input.toLower();
//    input= lower;
}

void MainWindow::DestroyWhiteSpace(QString& string){
    for(int i=0; i<string.size();i++){
        if(string[i]==' '){
            while(string[i+1]==' '){
               string = string.simplified();
            }
        }
    }

}

QString MainWindow::read(QString into, QString out){
    QFile file(into);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        exit(1);
    }
    QTextStream textStream(&file);
    QStringList hi;
    while(!textStream.atEnd()){
        hi<<textStream.readLine();
    }
    out = hi.join(" ");
    Lowercase(out);
    DestroyWhiteSpace(out);
    file.close();
    return out;
}

void MainWindow::on_ClearButton_clicked()
{
      ui->Userinput->clear();
}

void MainWindow::on_SubmitButton_clicked()
{
//    QString Input = "HELLO WORLD     MY                                                                                NAME    JACKSON!!!!!!!!!";
//    Lowercase(Input);
//    DestroyWhiteSpace(Input);
//    ui->Userinput->setText(Input);
        save_into_user();
        ui->Userinput->setText(read(UserFileName,UserString));
        ui->Userinput->append(read(ProjectFileName,ProjectString));

        MainWindow::openNewWindow();

}


void MainWindow::on_Exitprog_clicked()
{
    close();
}

void MainWindow::on_DisplayStop_clicked()
{
    MainWindow::openStopWords();
}

void MainWindow::open_file(QString NameOfFile){
    QFile sFile(NameOfFile);
    if(sFile.open(QFile::WriteOnly|QFile::Text)){
        QTextStream out(&sFile);
    }
}

