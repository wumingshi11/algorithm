#include<vector>
#include<deque>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        if (root == nullptr) return vector<vector<int>>();
        auto node_deque = deque<TreeNode*>();
        node_deque.push_back(root);
        node_deque.push_back(nullptr);
        auto result = vector<vector<int>>();
        result.push_back(vector<int>());
        while (node_deque.size() > 1)
        {
            /* code */
            auto currNode = node_deque.front();
            if (currNode == nullptr) {
                result.push_back(vector<int>());
                node_deque.push_back(nullptr);
            } else {
                auto &vec = result.back();
                vec.push_back(currNode->val);
                if (currNode->left != nullptr) {
                    node_deque.push_back(currNode->left);
                }
                if (currNode->right != nullptr) {
                    node_deque.push_back(currNode->right);
                }
            }
            node_deque.pop_front();
        }
        return result;
    }
};