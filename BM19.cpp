#include<vector>
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
    int findPeakElement(vector<int>& nums) {
        // write code here
        if (nums.size() == 1) return 0;
        if (*nums.begin() > *(nums.begin() + 1)) return 0;
        if (*nums.end() - 1 > *(nums.end() - 2)) return nums.size() - 1;

        auto liter = nums.cbegin(), riter = nums.cend();
        auto miter = liter + (riter - liter)/2;
        while ( !(*miter > *(miter - 1) && *miter > *(miter + 1)) ) {
            if (*miter < *(miter - 1)) {
                riter = miter;
            } else {
                liter = miter;
            }
            miter = liter + (riter - liter)/2;
        }

        return miter - nums.begin();
    }
};