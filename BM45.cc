
#include<queue>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        
        

        
    }
};

int main(int argc, char const *argv[])
{
    auto fn = [](int a, int b){
            return a > b;
        };
    priority_queue<int, deque<int>, decltype(fn)> pri_queue(fn);
    pri_queue.push(1);
    pri_queue.push(2);
    pri_queue.push(3);
    cout << pri_queue.top() << endl;
    return 0;
}
