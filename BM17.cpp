#include<vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        auto liter = nums.cbegin(), riter = nums.cend();
        auto miter = liter + (riter - liter)/2;
        while (*miter != target) {
            /* code */
            if (liter >= riter) {
                return -1;
            }
            if (*miter < target) {
                liter = miter + 1;
            } else {
                riter = miter - 1;
            }
            miter = liter + (riter - liter)/2;
        }
        return miter - nums.cbegin();
        
    }
};