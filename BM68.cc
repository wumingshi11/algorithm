#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> min_cost(row + 1, vector<int>(col + 1, INT32_MAX));
        min_cost[0][1] = 0;

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                min_cost[i][j] = min(min_cost[i - 1][j], min_cost[i][j - 1]) + matrix[i - 1][j - 1];
            }
        }
        return min_cost[row][col];
    }
};