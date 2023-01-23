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
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == nullptr) return true;
        return walk(pRoot->left, pRoot->right);
    }

    bool walk(TreeNode* lhs, TreeNode* rhs) {
        if (lhs == nullptr && rhs == nullptr) return true;
        if (lhs == nullptr || rhs == nullptr) return false;
        if (lhs->val != rhs->val) return false;
        auto result = walk(lhs->left, rhs->right);
        if (!result) return result;
        return walk(lhs->right, rhs->left);
    }

};