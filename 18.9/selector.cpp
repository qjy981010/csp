// n=1, m=1 test !!!!!

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <utility>
#include <stdio.h>

using namespace std;

void tolow(string& s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] <= 'Z' && s[i] >= 'A') s[i] += 32; 
    }
}

struct Doc {
    int line;
    string label;
    string id;
    vector<Doc> children;
    Doc(){}
    Doc(int line_, string label_, string id_): line(line_), label(label_), id(id_) {
        // transform(label.begin(), label.end(), label.begin(), ::tolow);
        tolow(label);
        // transform(id.begin(), id.end(), id.begin(), ::tolow);
    }
};

int n, m;
vector<string> raw_doc;
vector<set<int>> result;
vector<Doc> doc;

pair<Doc, int> process_raw_doc(int idx) {
    int level = -1, label_start = -1, id_start = -1;
    for (int i = 0; raw_doc[idx][i]; ++i) {
        if (raw_doc[idx][i] != '.') {
            if (level == -1) {
                level = i / 2;
                label_start = i;
            }
            else if (raw_doc[idx][i] == ' ') {
                id_start = i + 1;
                break;
            }
        }
    }
    Doc d;
    if (id_start > -1)
        d = Doc(idx+1, raw_doc[idx].substr(label_start, id_start-label_start-1), raw_doc[idx].substr(id_start));
    else
        d = Doc(idx+1, raw_doc[idx].substr(label_start), "");
    ++idx;
    while (idx < raw_doc.size() && raw_doc[idx].find_last_of('.')+1 > level*2) {
        pair<Doc, int> p = process_raw_doc(idx);
        d.children.push_back(p.first);
        idx = p.second;
    }
    return pair<Doc, int>(d, idx);
}

void print(Doc d, int level) {
    for (int i = 0; i < level; ++i) cout << "  ";
    cout << d.line << " " << d.label << " " << d.id << endl;
    for (auto iter = d.children.begin(); iter != d.children.end(); ++iter) print(*iter, level+1);
}

vector<string> split(string raw_filter) {
    vector<string> result;
    int idx = raw_filter.find_first_of(' ');
    string tmp;
    if (idx != raw_filter.npos) tmp = raw_filter.substr(0, idx);
    else tmp = raw_filter.substr(0);
    if (tmp[0] != '#') tolow(tmp); //transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolow);
    result.push_back(tmp);
    vector<string> t;
    if (idx != raw_filter.npos)
        t = split(raw_filter.substr(idx+1));
        result.insert(result.end(), t.begin(), t.end());
    return result;
}

void match(vector<Doc> vd, vector<string> filter, int idx, int vi) {
    for (auto iter = vd.begin(); iter != vd.end(); ++iter) {
        if (iter->label == filter[vi] || iter->id == filter[vi]) {
            if (vi+1 == filter.size()) {
                result[idx].insert(iter->line);
                match(iter->children, filter, idx, vi);
            }
            else {
                match(iter->children, filter, idx, vi+1);
            }
        }
        else
            match(iter->children, filter, idx, vi);
    }
}

int main(int argc, char const *argv[])
{
    char tmp[90];
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; ++i) {
        cin.getline(tmp, 90);
        raw_doc.push_back(string(tmp));
    }
    doc.push_back(process_raw_doc(0).first);
    // print(doc, 0);

    for (int i = 0; i < m; ++i) {
        cin.getline(tmp, 90);
        vector<string> filter = split(string(tmp));
        // for (auto iter = filter.begin(); iter != filter.end(); ++iter) {
        //     cout << *iter << "  ";
        // }
        // cout << endl;
        result.push_back(set<int>());
        match(doc, filter, i, 0);
    }

    for (int i = 0; i < m; ++i) {
        cout << result[i].size() << " ";
        for (auto iter = result[i].begin(); iter != result[i].end(); ++iter) {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}