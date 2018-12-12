#include "mainwindow.h"
#include "ui_mainwindow.h"
//std::cout << FUNCNAME.toUtf8().constData() << std::endl

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        UserFileName="/Users/jacksontruong/Qt/ComputerEngineering130/UserFile";
        UserFileRevisedName="/Users/jacksontruong/Qt/ComputerEngineering130/UserFileREVISED";
        ProjectFileName="/Users/jacksontruong/Qt/ComputerEngineering130/ProjectFile";
        ProjectFileRevisedName="/Users/jacksontruong/Qt/ComputerEngineering130/ProjectFileREVISED";
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

void MainWindow::openNewWindow() //maybe in this function we can the information to it
{
    New_window = new Form();
    New_window->show();
}

void MainWindow::openStopWords()
{
    StopWordsWindow = new StopWords();
    StopWordsWindow->show();
}

void MainWindow::computeLPSArray(QString pat, int M, int* lps) // Fills lps[] for given patttern pat[0..M-1]
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int MainWindow::KMPSearch(QString pat, QString txt) // Prints occurrences of txt[] in pat[]
{
    int copied = 0; // flag to show if txt has been copied from pat
    int M = pat.length();
    int N = txt.length();
    int lps[M]; // create lps[] that will hold the longest prefix suffix values for pattern

    computeLPSArray(pat, M, lps); // Preprocess the pattern (calculate lps[] array)

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]

    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            copied = 1; // string has been copied
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return copied; //return copied flag
}

void MainWindow::ourKMP(QList<QString>testList, QList<QString>userList,
                        QList<QString>originalUserList)
{
    int copied = 0;
    QString Cop = "SENTENCES COPIED:";
    ui->Userinput->append(Cop);
    for(int j = 0; j <= userList.size()-1; j++)
    {
        for(int i = 0; i <= testList.size()-1; i++)
        {
            //run KMP
            copied = KMPSearch(testList.at(i), userList.at(j));
            if(copied == 1){
                break;
            }
        }
        if(copied == 1)
        {
            QString userString = originalUserList.at(j);
            QString str = "**";
            str = str+ userString + str;
            ui->Userinput->append(str);
        }
        else
        {
            ui->Userinput->append(UserString);
        }
    }
}

void MainWindow::CreateCharArr(QString& UserInput, QString& ProjOutput, QString& Origin) //THIS WILL TAKE IN THE REVISED PROJECT
{
    QFile InputFile(UserInput);
    QFile PInputFile(ProjOutput);
    QFile OriginalFile(Origin);

    QList<QString> User;
    QList<QString> Project;
    QList<QString> UserOriginal;

    QString OriginalTxt;
    QString Usertxt;
    QString Projecttxt;

    int OriginalWordStart = 0;
    int OriginalWordEnd = 0;
    int UserWordStart = 0;
    int UserWordEnd = 0;
    int ProjectWordStart = 0;
    int ProjectWordEnd = 0;

    if(InputFile.open(QFile::ReadOnly|QFile::Text)&& PInputFile.open(QFile::ReadOnly|QFile::Text)&& OriginalFile.open(QFile::ReadWrite|QFile::Text))
    {
        QTextStream readOrigin(&OriginalFile);
        QTextStream readUser(&InputFile);
        QTextStream readProject(&PInputFile);

        OriginalTxt = readOrigin.readAll();
        Usertxt = readUser.readAll();
        Projecttxt = readProject.readAll();
        for(int k = 0; k <= OriginalTxt.size(); k++)
        {
            if(OriginalTxt[k] == '.' || OriginalTxt[k] == '!' || OriginalTxt[k] == '?')
            {
                if(OriginalTxt[k + 1] == ' ')
                {
                    QString insert;
                    OriginalWordEnd = k + 1;
                    while(OriginalWordStart < OriginalWordEnd)
                    {
                        insert.append(OriginalTxt[OriginalWordStart]);
                        OriginalWordStart++;
                    }
                    UserOriginal.append(insert);
                    OriginalWordEnd++;
                    OriginalWordStart++;
                }
            }
        }
        for(int i = 0; i <= Usertxt.size(); i++)
        {
            if(Usertxt[i] == '.' || Usertxt[i]== '!' || Usertxt[i]== '?')
            {
                if(Usertxt[i + 1] == ' ')
                {
                    QString insert;
                    UserWordEnd = i + 1;
                    while(UserWordStart<UserWordEnd)
                    {
                       insert.append(Usertxt[UserWordStart]);
                       UserWordStart++;
                    }
                    User.append(insert);
                    UserWordEnd++;
                    UserWordStart++;
                }
            }
        }
        for(int j = 0; j <= Projecttxt.size(); j++)
        {
            if(Projecttxt[j] == '.' || Projecttxt[j] == '?' || Projecttxt[j] == '!' )
            {
                if(Projecttxt[j + 1]== ' ')
                {
                    QString insert;
                    ProjectWordEnd = j + 1;
                    while(ProjectWordStart<ProjectWordEnd)
                    {
                       insert.append(Projecttxt[ProjectWordStart]);
                       ProjectWordStart++;
                    }
                    Project.append(insert);
                    ProjectWordEnd++;
                    ProjectWordStart++;
                }
            }
        }
        ourKMP(User,Project,UserOriginal);

    }
    InputFile.close();
    PInputFile.close();
    OriginalFile.close();
}

void MainWindow::RemoveStopWords(QString& input,QString& output)
{
    QFile InputFile(input);//File you would like to remove
    QFile OutputFile(output);//File to store the new input

    if(InputFile.open(QFile::ReadOnly|QFile::Text) && OutputFile.open(QFile::WriteOnly|QFile::Text))
    {
        QList<QString> Filelist;
        QTextStream ReadFile(&InputFile);//Reads the file
        QTextStream WriteFile(&OutputFile);//Writes into the file
        QString FileString;

        FileString = ReadFile.readAll();
        Lowercase(FileString);
        DestroyWhiteSpace(FileString);

        int WordStart = 0;
        int WordEnd = 0;
        for(int i = 0; i <= FileString.size(); i++)
        {
            if(FileString[i] == ' ')
            {
                QString insert;
                WordEnd = i;
                while(WordStart<WordEnd)
                {
                    if(FileString[WordStart]== ' ')
                    {
                        WordStart++;
                    }
                    insert.append(FileString[WordStart]);
                    WordStart++;
                }
                Filelist.append(insert);
                WordEnd++;
            }
        }

        WordStart++;
        WordEnd = FileString.size() - 1;
        QString LastWord;
        while(WordStart <= WordEnd)
        {
            if(FileString[WordStart] == ' ')
            {
                WordStart++;
            }
            LastWord.append(FileString[WordStart]);
            WordStart++;
        }

        Filelist.append(LastWord);
        QList<QString>::iterator it = Filelist.begin();
        for(it = Filelist.begin();it != Filelist.end(); it++)
        {
            QSet<QString>::iterator match;
            for(match = Stopwords.begin(); match != Stopwords.end(); ++match)
            {
                QString Reference = *match;
                if(*it == Reference)
                {
                    Filelist.removeOne(*it);
                }
            }
        }

        QString Revised;
        for(it = Filelist.begin(); it!=Filelist.end(); ++it)
        {
            QString concatenate = *it;
            Revised.append(concatenate);
            Revised.append(" ");
        }

        ui->Userinput->setText(Revised);
        save_into_file(output);
    }

    InputFile.flush();
    InputFile.close();
    OutputFile.flush();
    OutputFile.close();
}

int MainWindow::GetWordCount(QString& inputString)
{
    int wordCount = 0;
    for(int i = 0; i < inputString.length(); i++)
    {
        if(inputString[i] == ' ')
        {
            wordCount++;
        }
    }
    return wordCount + 1;
}

void MainWindow::save_into_file(QString& input)
{
    QFile sFile(input);
    if(sFile.open(QFile::WriteOnly|QFile::Text))
    {
        QTextStream out(&sFile);
        out<< ui->Userinput->toPlainText();
//      sFile.flush();
        sFile.close();
    }
}

void MainWindow::Lowercase(QString& stringUppercase) //this is used in the read function //returns lowercase version of input
{
    for(int i = 0; i < stringUppercase.size(); i++)
    {
        if(stringUppercase.at(i).isUpper())
        {
           stringUppercase[i] = (stringUppercase[i].toLower());
        }
    }
}

void MainWindow::DestroyWhiteSpace(QString& stringWhiteSpaces) //this is used in the read function //removes excess whitespaces from input
{
    for(int i = 0; i < stringWhiteSpaces.size(); i++)
    {
        if(stringWhiteSpaces[i]==' ')
        {
            while(stringWhiteSpaces[i + 1] == ' ')
            {
               stringWhiteSpaces = stringWhiteSpaces.simplified();
            }
        }
    }
}

void MainWindow::on_ClearButton_clicked()
{
      ui->Userinput->clear();
}

void MainWindow::on_SubmitButton_clicked()
{
    QString c;
    save_into_file(UserFileName);
    QFile a(UserFileName);
    if(a.open(QFile::ReadOnly|QFile::Text))
    {
        QTextStream b(&a);
        c = b.readAll();
    }

    RemoveStopWords(ProjectFileName,ProjectFileRevisedName);
    RemoveStopWords(UserFileName,UserFileRevisedName);//LOWERCASES AND REMOVES WHITE SPACES
    ui->Userinput->setText(c);

    CreateCharArr(UserFileRevisedName,ProjectFileRevisedName,UserFileName);
    //      THESE LINES ARE USED TO CHECK THE WORD COUNT AS WELL AS READ OF THE FILE WORKS GREAT
    //      UserString = read(UserFileName,UserString);
    //      ProjectString = read(ProjectFileName,ProjectString);
    //      ProjectCount = QString::number(GetWordCount(ProjectString));
    //      UserCount = QString::number(GetWordCount(UserString));
    //      ui->Userinput->append(UserCount);
    //      ui->Userinput->append(ProjectCount);
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
