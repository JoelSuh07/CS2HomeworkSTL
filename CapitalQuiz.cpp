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
         string line;
        // Read the file line by line
        while (getline(file, line)) {
            // Find the position of the comma
            size_t commaPos = line.find(','); 
            if (commaPos != string::npos) {
                // Extract the state name (before the comma)
                stateName = line.substr(0, commaPos); 
                // Extract the capital city (after the comma)
                capitalCity = line.substr(commaPos + 1);

                stateToCapital[stateName] = capitalCity;
        }
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