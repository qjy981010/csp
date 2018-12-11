#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int n;
string s, t;
vector<vector<vector<string>>> v;
unordered_map<string, vector<int>> result;

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c) {
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int main() {
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) {
        vector<vector<string>> tmp_v;
        string tmp_s;
        for (int j = 0; j < 6; ++j) {
            vector<string> dot_split;
            cin >> tmp_s;
            SplitString(tmp_s, dot_split, ",");
            tmp_v.push_back(dot_split);
        }
        v.push_back(tmp_v);
    }
    for (int i = 0; i < n; ++i) {
        
    }
    return 0;
}