#ifndef SMURFING_H
#define SMURFING_H
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class smurfing
{
public:
    smurfing();
    vector<string> place;
    void to_lower(char input[]);
    void White_space_cleaner(char* input, char* output);
    void preKMP(vector<string> pattern, int f[]);
    bool KMP(vector<string>target,vector<string> pattern);
    void eraseAllSubStr(std::string &mainStr, const std::string &toErase);
    void eraseSubStringsper(std::string &mainStr, const std::vector<std::string> &strList);
    vector<string> listofstopwords;

private:
    int userSentenceCount;
    int fileSentenceCount;
    vector<string> user;
    vector<string> files;
};

#endif // SMURFING_H
