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
    TreeNode* helper(int left, int right, vector<int>& nums){
        // Base case
        if (left > right)
            return nullptr;
        
        // Always choose the right middle node as a root
        int mid = (left + right) >> 1;
        
        // Preorder traversal: node -> left -> right
        if ((left + right) % 2)
            ++mid;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = helper(left, mid - 1, nums);
        root -> right = helper(mid + 1, right, nums);
        
        return root;
    }
    
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, nums.size() - 1, nums);
    }
};