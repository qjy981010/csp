#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Value {
    string s;
    map<string, Value> m;
};
map<string, Value> data;
int n, m;
string json;
int idx;
vector<string> quary;

string get_str() {
    string result;
    ++idx;
    for (; idx < json.length() && json[idx] != '"'; ++idx) {
        if (json[idx] == '\\')
            result.push_back(json[++idx]);
        else
            result.push_back(json[idx]);
    }
    ++idx;
    return result;
}

map<string, Value> get_obj() {
    map<string, Value> result;
    while (idx < json.length() && json[idx] != '}') {
        string k;
        Value v;
        for (; idx < json.length(); ++idx) {
            if (json[idx] == '"') {
                k = get_str();
                break;
            }
        }
        for (; idx < json.length(); ++idx) {
            if (json[idx] == '"') {
                v.s = get_str();
                result.insert({k, v});
                break;
            }
            else if(json[idx] == '{') {
                v.m = get_obj();
                result.insert({k, v});
                break;
            }
        }
    }
    ++idx;
    return result;
}

void search(int i, map<string, Value>& d) {
    int dot_idx = quary[i].find_first_of('.');
    if (dot_idx != quary[i].npos) {
        auto iter = d.find(quary[i].substr(0, dot_idx));
        if (iter == d.end()) {
            cout << "NOTEXIST" << endl;
            return;
        }
        quary[i] = quary[i].substr(dot_idx+1);
        search(i, iter->second.m);
    }
    else {
        auto iter = d.find(quary[i]);
        if (iter == d.end()) {
            cout << "NOTEXIST" << endl;
        }
        else {
            if (iter->second.s == "") {
                cout << "OBJECT" << endl;
            }
            else {
                cout << "STRING " << iter->second.s << endl;
            }
        }
        return;
    }
}

int main() {
    cin >> n >> m;
    char line[90];
    getchar();
    for (int i = 0; i < n; ++i) {
        cin.getline(line, 89);
        json += string(line);
    }
    idx = 0;
    data = get_obj();
    // for (auto iter = data.begin(); iter != data.end(); ++iter) {
    //     cout << iter->first << endl;
    // }
    for (int i = 0; i < m; ++i) {
        cin.getline(line, 89);
        quary.push_back(string(line));
    }
    for (int i = 0; i < m; ++i) {
        search(i, data);
    }
    return 0;
}