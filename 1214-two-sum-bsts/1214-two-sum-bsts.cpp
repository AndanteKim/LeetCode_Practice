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
private:
    void inorder(unordered_set<int>& seen, TreeNode* root){
        if (!root) return;
        inorder(seen, root -> left);
        seen.insert(root -> val);
        inorder(seen, root -> right);
    }
    
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> seen1, seen2;
        inorder(seen1, root1);
        inorder(seen2, root2);
        for (int n1: seen1){
            if (seen2.find(target - n1) != seen2.end()) return true;
        }
        return false;
    }
};