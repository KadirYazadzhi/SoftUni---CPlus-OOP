#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> 

using namespace std;

class Locations {
public:
    typedef vector<string> Names;
    typedef vector<pair<string, string>> Coords;

private:
    Names names;
    Coords coords;

public:
    Locations(istream &istr) {
        string line;
        while (getline(istr, line)) {
            if (line == ".") {
                break;
            }

            istringstream iss(line);

            string name;
            pair<string, string> coordinates;

            getline(iss, name, ',');
            getline(iss, coordinates.first, ',');
            iss >> coordinates.second;

            names.push_back(name);
            coords.push_back(coordinates);
        }
    }

    string findByCoords(pair<string, string> &coordinates) {
        ostringstream oss;
        for (size_t i = 0; i < coords.size(); ++i) {
            if (coords[i] == coordinates) {
                oss << names[i] << "," << coords[i].first << "," << coords[i].second << endl;
            }
        }
        return oss.str();
    }

    string findByName(const string &name) {
        ostringstream oss;
        auto it = find(names.begin(), names.end(), name);
        if (it != names.end()) {
            size_t idx = distance(names.begin(), it);
            oss << names[idx] << "," << coords[idx].first << "," << coords[idx].second << endl;
        }
        return oss.str();
    }
};

int main() {
    Locations locs(cin);

    string line;
    while (getline(cin, line)) {
        if (line == ".") {
            break;
        }

        istringstream iss(line);

        string resultStr;

        if (isdigit(line[0])) {
            pair<string, string> coordinates;
            iss >> coordinates.first >> coordinates.second;

            resultStr = locs.findByCoords(coordinates);
        } else {
            string name;
            iss >> name;

            resultStr = locs.findByName(name);
        }

        if (!resultStr.empty()) {
            cout << resultStr;
        }
    }

    return 0;
}
