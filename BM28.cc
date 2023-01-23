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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) return nullptr;
        TreeNode head = TreeNode(0);
        walk(pRootOfTree, &head);
        head.right->left = nullptr;
        return head.right;    
    }

    TreeNode* walk(TreeNode *currNode, TreeNode *lastNode) {
        if (currNode->left != nullptr) {
            lastNode = walk(currNode->left, lastNode);
        }
        lastNode->right = currNode;
        currNode->left = lastNode;
        lastNode = currNode;
        if (currNode->right != nullptr) {
            lastNode = walk(currNode->right, lastNode);
        }
        return lastNode; 
    }
};
