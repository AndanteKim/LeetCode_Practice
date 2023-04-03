/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int k;
    int dfs(TreeNode* node, vector<int>& ans, TreeNode* target){
        if (!node) return -1;
        else if (node == target){
            subtree_add(node, 0, ans);
            return 1;
        }
        else{
            int L = dfs(node -> left, ans, target), R = dfs(node -> right, ans, target);
            if (L != -1){
                if (L == this -> k) ans.push_back(node -> val);
                subtree_add(node -> right, L + 1, ans);
                return L + 1;
            }
            else if (R != -1){
                if (R == this -> k) ans.push_back(node -> val);
                subtree_add(node -> left, R + 1, ans);
                return R + 1;
            }
            else return -1;
        }
    }
    
    void subtree_add(TreeNode* node, int dist, vector<int>& ans){
        if (!node) return;
        else if (dist == this -> k) ans.push_back(node -> val);
        else{
            subtree_add(node -> left, dist + 1, ans);
            subtree_add(node -> right, dist + 1, ans);
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        this -> k = k;
        dfs(root, ans, target);
        return ans;
    }
};