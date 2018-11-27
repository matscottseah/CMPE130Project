#include "smurfing.h"

smurfing::smurfing()
{
    listofstopwords.push_back("i");
    listofstopwords.push_back("me");
    listofstopwords.push_back("myself");
    listofstopwords.push_back("my");
    listofstopwords.push_back("we");
    listofstopwords.push_back("ours");
    listofstopwords.push_back("our");
    listofstopwords.push_back("ourselves");
    listofstopwords.push_back("you");
    listofstopwords.push_back("your");
    listofstopwords.push_back("yours");
    listofstopwords.push_back("yourself");
    listofstopwords.push_back("yourselves");
    listofstopwords.push_back("he");
    listofstopwords.push_back("him");
    listofstopwords.push_back("his");
    listofstopwords.push_back("himself");
    listofstopwords.push_back("she");
    listofstopwords.push_back("her");
    listofstopwords.push_back("hers");
    listofstopwords.push_back("herself");
    listofstopwords.push_back("it");
    listofstopwords.push_back("its");
    listofstopwords.push_back("itself");
    listofstopwords.push_back("they");
    listofstopwords.push_back("them");
    listofstopwords.push_back("their");
    listofstopwords.push_back("theirs");
    listofstopwords.push_back("themselves");
    listofstopwords.push_back("what");
    listofstopwords.push_back("which");
    listofstopwords.push_back("who");
    listofstopwords.push_back("whom");
    listofstopwords.push_back("this");
    listofstopwords.push_back("that");
    listofstopwords.push_back("these");
    listofstopwords.push_back("those");
    listofstopwords.push_back("am");
    listofstopwords.push_back("is");
    listofstopwords.push_back("are");
    listofstopwords.push_back("was");
    listofstopwords.push_back("were");
listofstopwords.push_back("be");
listofstopwords.push_back("been");
listofstopwords.push_back("being");
listofstopwords.push_back("have");
listofstopwords.push_back("has");
listofstopwords.push_back("had");
listofstopwords.push_back("having");
listofstopwords.push_back("do");
listofstopwords.push_back("does");
listofstopwords.push_back("did");
listofstopwords.push_back("doing");
listofstopwords.push_back("a");
listofstopwords.push_back("an");
listofstopwords.push_back("the");
listofstopwords.push_back("and");
listofstopwords.push_back("but");
listofstopwords.push_back("if");
listofstopwords.push_back("or");
listofstopwords.push_back("because");
listofstopwords.push_back("as");
listofstopwords.push_back("until");
listofstopwords.push_back("while");
listofstopwords.push_back("of");
listofstopwords.push_back("at");
listofstopwords.push_back("by");
listofstopwords.push_back("for");
listofstopwords.push_back("with");
listofstopwords.push_back("about");
listofstopwords.push_back("against");
listofstopwords.push_back("between");
listofstopwords.push_back("into");
listofstopwords.push_back("through");
listofstopwords.push_back("during");
listofstopwords.push_back("before");
listofstopwords.push_back("after");
listofstopwords.push_back("above");
listofstopwords.push_back("below");
listofstopwords.push_back("to");
listofstopwords.push_back("from");
listofstopwords.push_back("up");
listofstopwords.push_back("down");
listofstopwords.push_back("in");
listofstopwords.push_back("out");
listofstopwords.push_back("off");
listofstopwords.push_back("over");
listofstopwords.push_back("under");
listofstopwords.push_back("again");
listofstopwords.push_back("further");
listofstopwords.push_back("then");
listofstopwords.push_back("once");
listofstopwords.push_back("here");
listofstopwords.push_back("there");
listofstopwords.push_back("when");
listofstopwords.push_back("where");
listofstopwords.push_back("why");
listofstopwords.push_back("how");
listofstopwords.push_back("all");
listofstopwords.push_back("any");
listofstopwords.push_back("both");
listofstopwords.push_back("each");
listofstopwords.push_back("few");
listofstopwords.push_back("more");
listofstopwords.push_back("most");
listofstopwords.push_back("other");
listofstopwords.push_back("some");
listofstopwords.push_back("such");
listofstopwords.push_back("no");
listofstopwords.push_back("nor");
listofstopwords.push_back("not");
listofstopwords.push_back("only");
listofstopwords.push_back("own");
listofstopwords.push_back("same");
listofstopwords.push_back("so");
listofstopwords.push_back("than");
listofstopwords.push_back("too");
listofstopwords.push_back("very");
listofstopwords.push_back("can");
listofstopwords.push_back("will");
listofstopwords.push_back("just");
listofstopwords.push_back("don");
listofstopwords.push_back("should");
listofstopwords.push_back("now");
}
void eraseAllSubStr(std::string & mainStr, const std::string & toErase)
{
    size_t pos = std::string::npos;

    // Search for the substring in string in a loop untill nothing is found
    while ((pos  = mainStr.find(toErase) )!= std::string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}
void eraseSubStringsPre(std::string & mainStr, const std::vector<std::string> & strList)
{
    // Iterate over the given list of substrings. For each substring call eraseAllSubStr() to
    // remove its all occurrences from main string.
    for (std::vector<std::string>::const_iterator it = strList.begin(); it != strList.end(); it++)
    {
        eraseAllSubStr(mainStr, *it);
    }

}

void smurfing::to_lower(char word[]){
    for(size_t i=0; i<strlen(word); i++){
        if(isupper(word[i])){
         word[i]=tolower(word[i]);
        }
    }
}
void smurfing::White_space_cleaner(char* word, char * new_word){
    int input_index =0;
    int output_index =0;
    while(word[input_index]!= '\0'){//equivalent to white space
        new_word[output_index]=word[input_index];
        if(word[input_index]== ' '){
            while(word[input_index+1]== ' '){
                  input_index++; //skips white spaces
        }
        }
        output_index++;
        input_index++;
    }
    new_word[output_index] = '\0';//null-terminate output
}
void preKMP(vector<string> pattern, int f[]){
    string patternlen=pattern.front();
int m = patternlen.length(), k;
f[0]=-1;
for(int i=1; i<m;i++){
    k= f[i-1];
    while(k>=0){
        if(pattern[k]==pattern[i-1]){
            break;
        }
        else{
            k=f[k];
        }
    }
    f[i]=k+1;
}
}
bool KMP(vector<string>target,vector<string> pattern){
string targetlen= target.front();
string patternlen= pattern.front();
int m=patternlen.length();
int n = targetlen.length();
int f[m];
preKMP(pattern,f);
int i=0;
int k=0;
while(i<n){
    if(k==-1){
        i++;
        k=0;
    }
    else if(target[i]==pattern[k]){
        i++;
        k++;
        if(k==m){
            return 1;
        }
    }
    else{
        k=f[k];
    }
}
return 0;
}
