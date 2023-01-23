#include<vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0 || array[0].size() == 0) return false;
        int raw = array.size() - 1, line = array[0].size() - 1;
        int currRaw = raw, currLine = 0;
        while (currRaw != 0 && currLine != line)
        {
            /* code */
            if (array[currRaw][currLine] == target) {
                return true;
            } else if (array[currRaw][currLine] < target) {
                currLine++;
            } else {
                currRaw--;
            }           
        }

        if (array[currRaw][currLine] == target) {
                return true;
        }; 
        return false;    
    }
};