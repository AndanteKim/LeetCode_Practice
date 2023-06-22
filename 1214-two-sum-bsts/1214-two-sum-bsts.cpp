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
    bool binarySearch(TreeNode* root2, int target){
        if (!root2) return false;
        if (root2 -> val == target) return true;
        else if (root2 -> val > target) return binarySearch(root2 -> left, target);
        else return binarySearch(root2 -> right, target);
    }
    
    bool dfs(TreeNode* root1, TreeNode* root2, int target){
        if (!root1) return false;
        if (binarySearch(root2, target - root1 -> val)) return true;
        return dfs(root1 -> left, root2, target) || dfs(root1 -> right, root2, target);
    }
    
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return dfs(root1, root2, target);
    }
};