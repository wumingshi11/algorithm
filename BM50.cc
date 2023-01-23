#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        vector<int> index(numbers.size());
        vector<int> result(2);
        for (int i = 0; i < numbers.size(); i++) {
            index.push_back(i);
        }
        auto fn = [&numbers](int a, int b){
            return numbers[a] < numbers[b];    
        };
        sort(index.begin(), index.end(), fn);
        auto index_left = index.cbegin(), index_right = index.cend() - 1;
        while (index_left < index_right) {
            if (numbers[*index_left] + numbers[*index_right] == target) {
                result.push_back(*index_left + 1);
                result.push_back(*index_right + 1);
                return result;
            } else if(numbers[*index_left] + numbers[*index_right] > target) {
                index_right--;
            } else {
                index_left++;
            }
        }
        return result;
        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec{1,2,3,4,5};
    auto fn = [](int a, int b) { return a > b;};
    sort(vec.begin(), vec.end(), fn);
    for(int n : vec) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
