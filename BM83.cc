#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string trans(string s, int n) {
        // write code here
        auto strs = split(s, " ");
        string result;
        while(!strs.empty()){
            auto &str = strs.back();
            for(auto &c : str) {
                if (islower(c)) {
                    c = toupper(c);
                } else {
                    c = tolower(c);
                }
            }
            result += str;
            result += " ";
            strs.pop_back();
        }
        return result.substr(0, result.size() - 1);
    }
    vector<string> split(string s, string patter) {
        vector<string> s_vec;
        auto pos = s.find(patter);
        if (pos != s.npos) {
            s += patter;
        } else {
            s_vec.push_back(s);
            return s_vec;
        }
        
        while (pos != s.npos) {
            /* code */
            auto substring = s.substr(0, pos);
            s_vec.push_back(substring);
            s = s.substr(pos + patter.size(), s.size());
            pos = s.find(patter);
        }
        return s_vec;
        
    }
};