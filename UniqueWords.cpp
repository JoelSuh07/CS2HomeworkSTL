#include <fstream>
#include <iostream>
#include <set>
#include <string>
using namespace std;


ifstream file;

int main(){

    string line;
    ifstream file;

    file.open("LineFile.txt");
    //stores unique words
    set<string> words;
    if (file.is_open())
    {
        //Read the first line
        while (getline(file,line))
        {
            //cout << line << '\n';
            words.insert(line);
        }
        file.close();
    }

    set<string>::iterator it;
    for (it = words.begin();it != words.end(); it++)
    {
        cout << *it << endl; 
    }

    return 0;
}


