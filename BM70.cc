#include<vector>
#include<stdint.h>
using namespace std;
class Solution {
public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int>& arr, int aim) {
        // write code here
        vector<int> min_(aim + 1, INT32_MAX);
        min_[0] = 0;
        for (int i : arr) {
            for (int j = i; j <= aim; j++) {
                if (min_[j - i] >= 0) {
                    min_[j] = min(min_[j], min_[j - 1] + 1);
                }
            }
        }
        return min_[aim] == INT32_MAX ? -1 : min_[aim];
    }
};