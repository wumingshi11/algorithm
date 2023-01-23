#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param cost int整型vector 
     * @return int整型
     */
    int minCostClimbingStairs(vector<int>& cost) {
        // write code here
        vector<int> min_cost(cost);
        min_cost.push_back(0);
        min_cost[0] = 0;
        min_cost[1] = 0;
        for (int i =2; i <= cost.size(); i++) {
            min_cost[i] = min(min_cost[i - 2] + cost[i - 2], min_cost[i - 1] + cost[i - 1]);
        }
        return min_cost.back();
    }
};