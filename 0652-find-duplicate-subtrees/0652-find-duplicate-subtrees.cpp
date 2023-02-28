/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> cnt;
        vector<TreeNode*> res;
        function<string(TreeNode*)> traverse = [&cnt, &res, &traverse](TreeNode* node) -> string{
            if (node == nullptr) return "";
            string representation = "(" + traverse(node -> left) + ")" + to_string(node -> val) + "(" + \
                                    traverse(node -> right) + ")";
            ++cnt[representation];
            if (cnt[representation] == 2) res.push_back(node);
            return representation;
        };
        
        traverse(root);
        return res;
    }
};