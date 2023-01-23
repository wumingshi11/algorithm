#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param n int整型 the n
     * @return int整型
     */
    int result = 0;
    int Nqueen(int n) {
        // write code here
        vector<int> vec(n);
        Nqueen(vec, 0);
        return result;
    }

    void Nqueen(vector<int> &vec, int row) {
        if (row == vec.size()) {
            result++;
            return;
        }
        for (int i = 0; i < vec.size(); i++) {
            if (vaild(vec, row, i)) {
                vec[row] = i;
                Nqueen(vec, row + 1);
            }
        }

    }

    bool vaild(vector<int> &vec, int row, int col) {
        for(int i = 0; i < row; i++) {
            if (vec[i] == col || abs(i - row) == abs(vec[i] - col)) {
                return false;
            }
        }
        return true;        
    }
};