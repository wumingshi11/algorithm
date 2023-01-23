#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int rob(vector<int>& nums) {
        auto v1 = vector<int>(nums.begin(), nums.end() - 1);
        auto v2 = vector<int>(nums.begin() + 1, nums.end());
        int max1 = _rob(v1);
        int max2 = _rob(v2);
        if (max1 > max2) return max1;
        return max2;
    }
    int _rob(vector<int>& nums) {
        // write code here
        vector<int> max_(nums.size() + 1);
        max_[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            max_[i] = max(max_[i - 2] + nums[i], max_[i - 1]);
        }
        return max_.back();
    }
};