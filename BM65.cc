#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        if (s1.size() == 0 || s2.size() == 0) return "-1";
        vector<vector<int>> max_len(s1.size() + 1, vector<int>(s2.size() + 1));
        vector<vector<int>> str_path(s1.size() + 1, vector<int>(s2.size() + 1));

        for (int i = 1; i <= s1.size(); i++){
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    max_len[i][j] = max_len[i - 1][j -1] + 1;
                    str_path[i][j] = 1;
                } else {
                    if (max_len[i - 1][j] >= max_len[i][j - 1]) {
                        max_len[i][j] = max_len[i - 1][j];
                        str_path[i][j] = 2;
                    } else {
                        max_len[i][j] = max_len[i][j - 1]; 
                        str_path[i][j] = 3;
                    }
                }

            }
        }
        auto s = find_max_str(s1, str_path, s1.size(), s2.size());;
        if (s.empty()) s = "-1";
        return s;
    }
    string find_max_str(string &s1, vector<vector<int>> &str_path, int row, int col) {
        string s = "";
        if (row == 0 || col == 0) return s;
        if(str_path[row][col] == 1) {
            s = find_max_str(s1, str_path, row - 1, col - 1);
            return s + s1[row - 1];
        } else if (str_path[row][col] == 2) {
            return find_max_str(s1, str_path, row - 1, col);
        } else {
            return find_max_str(s1, str_path, row, col - 1);
        }

    }
};