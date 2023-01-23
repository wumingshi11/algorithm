#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str1 string字符串 
     * @param str2 string字符串 
     * @return int整型
     */
    int editDistance(string str1, string str2) {
        // write code here
        vector<vector<int>> distance(str1.size() + 1, vector<int>(str2.size() + 1));
        for (int i = 0; i <= str1.size(); i++) {
            for (int j = 0; j <= str2.size(); j++) {
                if (i == 0) {
                     distance[i][j] = j;
                     continue;
                }
                if (j == 0) {
                    distance[i][j] = i;
                    continue;
                }
                if (str1[i - 1] == str2[j - 1]) {
                    distance[i][j] = distance[i - 1][j - 1];
                } else {
                    int tmp = min(distance[i - 1][j], distance[i][j - 1]);
                    distance[i][j] = min(tmp, distance[i - 1][j - 1]) + 1;
                }
            }
        }
        return distance[str1.size()][str2.size()];
    }
};