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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) return {};
        
        vector<TreeNode*> forest;
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()){
            TreeNode* curr = queue.front(); queue.pop();
            
            if (curr -> left){
                queue.push(curr -> left);
                
                // Disconnect the left child if it needs to be deleted
                if (toDeleteSet.count(curr -> left -> val))
                    curr -> left = nullptr;
            }
            
            if (curr -> right){
                queue.push(curr -> right);
                
                // Disconnect the right child if it needs to be deleted
                if (toDeleteSet.count(curr -> right -> val))
                    curr -> right = nullptr;
            }
            
            // If the current node needs to be deleted, add its non-null children to the forest
            if (toDeleteSet.count(curr -> val)){
                if (curr -> left)
                    forest.push_back(curr -> left);
                if (curr -> right)
                    forest.push_back(curr -> right);
            }
        }
        
        // Ensure the root is added to the forest if it's not to be deleted
        if (!toDeleteSet.count(root -> val))
            forest.push_back(root);
        
        return forest;
    }
};