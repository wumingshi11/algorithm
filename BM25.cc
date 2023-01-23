
#include<vector>
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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型vector
     */
    vector<int> postorderTraversal(TreeNode* root) {
        // write code here
        auto result = vector<int>();
        walk_tree(root, result);
        return result;
    }

    void walk_tree(TreeNode* curr, vector<int>& result) {
        if (curr == nullptr) return;
        walk_tree(curr->left, result);       
        walk_tree(curr->right, result);
        result.push_back(curr->val);
    }
};