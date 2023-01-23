#include<stack>
using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);     
    }

    int pop() {
        if (stack2.size() == 0) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }   
        }
        int tmp = stack2.top();
        stack2.pop();
        return tmp;        
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};