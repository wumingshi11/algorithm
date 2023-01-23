#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    int longestValidParentheses(string s) {
        // write code here
        vector<int> lengths(s.size(), 0);
        int max = 0, curr = 0, sig = 0;
        for (char c : s) {
            switch (c)
            {
            case '(':
                /* code */
                sig++;
                break;
            case ')' :
                sig--;
                if (sig >= 0) {
                    curr += 2;
                    if (curr > max) max = curr;
                } else {
                    sig = 0;
                    curr = 0;
                }
                break;
            
            default:
                break;
            }
        }
        return max;
    }
};