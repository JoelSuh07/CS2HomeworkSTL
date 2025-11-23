#include <map>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string stateName, capitalCity;
    ifstream file;

    map<string, string> stateToCapital;
    file.open("StateCapitals.txt");

    if (!file.is_open()){
        cout << "Error opening file";
        return 1;
    }
    else{
        while (file >> stateName){

            getline(file, stateName, ',');
            getline(file, capitalCity);
            stateToCapital[stateName] = capitalCity;
        }
        file.close();
    }

    cout << "Enter a State: ";
    getline(cin,stateName);
    if (stateToCapital.find(stateName) == stateToCapital.end()) {
        cout << "State not found." << endl;
        return 1;
    }
    cout << "The capital of " << stateName << " is " << stateToCapital[stateName] << "." << endl;
    return 0;
}