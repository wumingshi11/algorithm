#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        vector<vector<int>> max_vec(str1.size() + 1, vector<int>(str2.size() + 1));
        int max = 0;
        int index = -1;
        for (int i = 1; i <= str1.size(); i++){
            for (int j = 1; j <= str2.size(); j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    max_vec[i][j] = max_vec[i - 1][j -1] + 1;
                    if (max_vec[i][j] > max) {
                        max =  max_vec[i][j];
                        index = i;
                    }
                } else {
                    max_vec[i][j] = 0;
                }
            }
        }
        return str1.substr(index - max, max);
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    auto s = so.LCS("1AB2345CD","12345EF");
    cout << s << endl;
    return 0;
}
