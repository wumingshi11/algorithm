#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        // write code here
        vector<int> left_max(arr.size());
        vector<int> right_max(arr.size());
        int tmp = 0;
        for (int i = 0; i < arr.size(); i++) {
            left_max[i] = tmp;
            if (arr[i] > tmp) tmp = arr[i];
        }
        tmp = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            right_max[i] = tmp;
            if (arr[i] > tmp) tmp = arr[i];
        }
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            int min_ = min(left_max[i], right_max[i]);
            if (min_ <= arr[i]) continue;
            sum += (min_ - arr[i]);
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    string s = "1101";
    int n = stoi(s, 0, 2);
    cout << n << endl;

    return 0;
}
