#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Normalize a token: remove punctuation and convert to lowercase
static inline void normalize_token(string &s) {
    s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){
        return ispunct(c);
    }), s.end());
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
        return tolower(c);
    });
}

int main(int argc, char* argv[]) {
    string filename = (argc > 1) ? argv[1] : "LineFile.txt";

    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open file: " << filename << '\n';
        return 1;
    }

    set<string> words;
    string line;
    while (getline(file, line)) {
        size_t i = 0;
        while (i < line.size()) {
            // skip non-alphanumeric characters
            while (i < line.size() && !isalnum((unsigned char)line[i])) ++i;
            size_t j = i;
            while (j < line.size() && isalnum((unsigned char)line[j])) ++j;
            if (j > i) {
                string w = line.substr(i, j - i);
                normalize_token(w);
                if (!w.empty()) words.insert(w);
            }
            i = j;
        }
    }

    file.close();

    for (const auto &w : words) cout << w << '\n';

    return 0;
}


