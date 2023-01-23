//注意string和char*的转换 +1
//注意子树的建立

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
    char* Serialize(TreeNode *root) {   
        string result("");
        dfs(root, result);
        char *res = new char[result.size() + 1];
        snprintf(res, result.size(), "%s", result.c_str());   
        return res;
    }
    void dfs(TreeNode *root, string &result) {
        if (root == nullptr) {
            result += "#,";
            return;
        }
        result += to_string(root->val);
        result += ",";
        dfs(root->left, result);
        dfs(root->right, result);
    }
    vector<string> split(string &str, const string &pattern) {
        vector<string> strs;
        auto pos = str.find(pattern);
        while (pos != str.npos) {
            /* code */
            string tmp = str.substr(0, pos);
            strs.push_back(tmp);
            str = str.substr(pos + 1, str.size());
            pos = str.find(pattern);
        }
        return strs;
        
    }
    TreeNode* Deserialize(char *str) {
        string tree_str(str);
        auto strs = split(tree_str, ",");
        if (strs.size() == 1) return nullptr;
        int first_val = stoi(strs[0]);
        TreeNode* head = new TreeNode(first_val);
        int n = buildLeftSubTree(head, strs, 1);
        buildRightSubTree(head, strs, n);
        return head;
    
    
    }
    int buildLeftSubTree(TreeNode* root, vector<string> &strs, int next) {
       if (strs[next] == "#") return ++next;
       int val = stoi(strs[next++]);
       root->left = new TreeNode(val);
       next = buildLeftSubTree(root->left, strs, next);
       next = buildRightSubTree(root->left, strs, next);
       return next;
    }

    int buildRightSubTree(TreeNode* root, vector<string> &strs, int next) {
       if (strs[next] == "#") return ++next;
       int val = stoi(strs[next++]);
       root->right = new TreeNode(val);
       next = buildLeftSubTree(root->right, strs, next);
       next = buildRightSubTree(root->right, strs, next);
       return next;
    }

};