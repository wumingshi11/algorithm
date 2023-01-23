#include<vector>
#include<string>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0) return nullptr;
        auto result = buildSubTree(pre,0,pre.size()-1,vin,0,vin.size()-1);
        return result;
    }

    TreeNode* buildSubTree(vector<int> &pre, int pre_start, int pre_end, vector<int> &vin, int vin_start, int vin_end) {
        if (pre_start < pre_end) return nullptr;
        TreeNode* currNode = new TreeNode(pre[pre_start]);
        if (pre_start == pre_end) return currNode;
        int mid = vin_start;
        for (; mid <= vin_end; mid++) {
            if (vin[mid] == pre[pre_start]) break;
        }
        
        currNode->left = buildSubTree(pre, pre_start + 1, pre_start + mid - vin_start, vin, vin_start, mid - 1);
        currNode->right = buildSubTree(pre, pre_start + mid - vin_start + 1, pre_end, vin, mid + 1, vin_end);
        return currNode;
    }
};