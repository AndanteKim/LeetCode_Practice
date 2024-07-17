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
    TreeNode* processNode(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest){
        if (!node)
            return nullptr;
        
        node -> left = processNode(node -> left, toDeleteSet, forest);
        node -> right = processNode(node -> right, toDeleteSet, forest);
        
        // Node evaluation: Check if the current node needs to be deleted
        if (toDeleteSet.count(node -> val)){
            if (node -> left)
                forest.push_back(node -> left);
            if (node -> right)
                forest.push_back(node -> right);
            
            // Delete the current node by returning nullptr to its parent
            return nullptr;
        }
        
        return node;
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        root = processNode(root, toDeleteSet, forest);
        
        // IF the root is not deleted, add it to the forest
        if (root)
            forest.push_back(root);
        
        return forest;
    }
};