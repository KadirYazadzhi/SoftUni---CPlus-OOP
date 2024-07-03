#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

class Words {
public:
    typedef set<string> WordData;

private:
    WordData data;

public:
    Words (istream & ist) {
        string buf;
        getline(ist, buf);

        for (char & c : buf) {
            if (ispunct(c)) {
                c = ' ';
            }
        }

        istringstream istr(buf);
        string tmp;
        while (istr >> tmp) {
            data.insert(tmp);
        }
    }

    string getWordsWithChar(char c) {
        ostringstream ostr;

        for (const string & curr : data) {
            string transformed = curr;
            transform(transformed.begin(), transformed.end(), transformed.begin(), ::tolower);
            if (transformed.find(c) != string::npos) {
                ostr << curr << " ";
            }
        }

        return ostr.str();
    }

    const WordData & getData(void) { return data; };
};

int main() {
    Words words(cin);

    while (true) {
        char c;
        cin >> c;

        if (c == '.') {
            break;
        }

        string wordsWithChar(words.getWordsWithChar(::tolower(c)));

        if (wordsWithChar.length() == 0) {
            cout << "---";
        }
        else {
            cout << wordsWithChar;
        }
        cout << endl;
    }
}
