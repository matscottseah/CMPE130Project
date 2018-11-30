#include "mainwindow.h"
#include "ui_mainwindow.h"
//std::cout << FUNCNAME.toUtf8().constData() << std::endl

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UserFileName="/Users/jacksontruong/Qt/AAAAAAAAAAAAAAAAAAAAAAAA/UserFile";
    UserFileRevisedName="/Users/jacksontruong/Qt/AAAAAAAAAAAAAAAAAAAAAAAA/ProjectFileRevised";
    ProjectFileName="/Users/jacksontruong/Qt/AAAAAAAAAAAAAAAAAAAAAAAA/ProjectFile";
    ProjectFileRevisedName="/Users/jacksontruong/Qt/AAAAAAAAAAAAAAAAAAAAAAAA/UserFileRevised";
    UserString = "";
    ProjectString = "";
    Stopwords.insert("i");
    Stopwords.insert("me");
    Stopwords.insert("myself");
    Stopwords.insert("my");
    Stopwords.insert("we");
    Stopwords.insert("ours");
    Stopwords.insert("our");
    Stopwords.insert("ourselves");
    Stopwords.insert("you");
    Stopwords.insert("your");
    Stopwords.insert("yours");
    Stopwords.insert("yourself");
    Stopwords.insert("yourselves");
    Stopwords.insert("he");
    Stopwords.insert("him");
    Stopwords.insert("his");
    Stopwords.insert("himself");
    Stopwords.insert("she");
    Stopwords.insert("her");
    Stopwords.insert("hers");
    Stopwords.insert("herself");
    Stopwords.insert("it");
    Stopwords.insert("its");
    Stopwords.insert("itself");
    Stopwords.insert("they");
    Stopwords.insert("them");
    Stopwords.insert("their");
    Stopwords.insert("theirs");
    Stopwords.insert("themselves");
    Stopwords.insert("what");
    Stopwords.insert("which");
    Stopwords.insert("who");
    Stopwords.insert("whom");
    Stopwords.insert("this");
    Stopwords.insert("that");
    Stopwords.insert("these");
    Stopwords.insert("those");
    Stopwords.insert("am");
    Stopwords.insert("is");
    Stopwords.insert("are");
    Stopwords.insert("was");
    Stopwords.insert("were");
    Stopwords.insert("be");
    Stopwords.insert("been");
    Stopwords.insert("being");
    Stopwords.insert("have");
    Stopwords.insert("has");
    Stopwords.insert("had");
    Stopwords.insert("having");
    Stopwords.insert("do");
    Stopwords.insert("does");
    Stopwords.insert("did");
    Stopwords.insert("doing");
    Stopwords.insert("a");
    Stopwords.insert("an");
    Stopwords.insert("the");
    Stopwords.insert("and");
    Stopwords.insert("but");
    Stopwords.insert("if");
    Stopwords.insert("or");
    Stopwords.insert("because");
    Stopwords.insert("as");
    Stopwords.insert("until");
    Stopwords.insert("while");
    Stopwords.insert("of");
    Stopwords.insert("at");
    Stopwords.insert("by");
    Stopwords.insert("for");
    Stopwords.insert("with");
    Stopwords.insert("about");
    Stopwords.insert("against");
    Stopwords.insert("between");
    Stopwords.insert("into");
    Stopwords.insert("through");
    Stopwords.insert("during");
    Stopwords.insert("before");
    Stopwords.insert("after");
    Stopwords.insert("above");
    Stopwords.insert("below");
    Stopwords.insert("to");
    Stopwords.insert("from");
    Stopwords.insert("up");
    Stopwords.insert("down");
    Stopwords.insert("in");
    Stopwords.insert("out");
    Stopwords.insert("off");
    Stopwords.insert("over");
    Stopwords.insert("under");
    Stopwords.insert("again");
    Stopwords.insert("further");
    Stopwords.insert("then");
    Stopwords.insert("once");
    Stopwords.insert("here");
    Stopwords.insert("there");
    Stopwords.insert("when");
    Stopwords.insert("where");
    Stopwords.insert("why");
    Stopwords.insert("how");
    Stopwords.insert("all");
    Stopwords.insert("any");
    Stopwords.insert("both");
    Stopwords.insert("each");
    Stopwords.insert("few");
    Stopwords.insert("more");
    Stopwords.insert("most");
    Stopwords.insert("other");
    Stopwords.insert("some");
    Stopwords.insert("such");
    Stopwords.insert("no");
    Stopwords.insert("nor");
    Stopwords.insert("not");
    Stopwords.insert("only");
    Stopwords.insert("own");
    Stopwords.insert("same");
    Stopwords.insert("so");
    Stopwords.insert("than");
    Stopwords.insert("too");
    Stopwords.insert("very");
    Stopwords.insert("can");
    Stopwords.insert("will");
    Stopwords.insert("just");
    Stopwords.insert("don");
    Stopwords.insert("should");
    Stopwords.insert("now");

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

void MainWindow::erase(QString& input,QString& stringname,QString& output){
    QFile sFile(input);
    if(sFile.open(QFile::WriteOnly|QFile::Text)){
    QSet<QString>::iterator it;
    std::string Hello;

    }


}

void MainWindow::save_into_file(QString& input){
    QFile sFile(input);//the next 6 lines help save the Qtextedit information into the  user text file
    if(sFile.open(QFile::WriteOnly|QFile::Text)){
        QTextStream out(&sFile);
        out<< ui->Userinput->toPlainText();
        sFile.flush();
        sFile.close();
    }
}

void MainWindow::Lowercase( QString& input){ // HAVENT USED THIS YET NEED TO MAKE FUNCTIONS TO OPEN FILES AND STORE THEM INTO A QSTRING
    std::string Hello;
    Hello = input.toStdString();
    for(int i=0; i<Hello.size();i++){
        if(isupper(Hello[i])){
            Hello[i]=tolower(Hello[i]);
        }
    }
    input = QString::fromStdString(Hello);
}

void MainWindow::DestroyWhiteSpace( QString& string){
    for(int i=0; i<string.size();i++){
        if(string[i]==' '){
            while(string[i+1]==' '){
               string = string.simplified();
            }
        }
    }

}

QString MainWindow::read(QString into,  QString out){
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
        save_into_file(UserFileName);
        ui->Userinput->setText(read(UserFileName,UserString));
      //  ui->Userinput->append(read(ProjectFileName,ProjectString));

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

