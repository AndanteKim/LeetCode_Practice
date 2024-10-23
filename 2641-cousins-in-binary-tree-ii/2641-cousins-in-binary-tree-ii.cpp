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
    vector<int> levelSums;
    void calculateSumLevel(TreeNode* node, int level){
        // Base case
        if (!node) return;
        
        // Accumulate sum at the current level
        if (levelSums.size() == level)
            levelSums.push_back(node -> val);
        else
            levelSums[level] += node -> val;
        calculateSumLevel(node -> left, level + 1);
        calculateSumLevel(node -> right, level + 1);
    }
    
    void replaceInternal(TreeNode* node, int siblingSum, int level){
        if (!node) return;
        
        int leftChildVal = (node -> left? node -> left -> val : 0);
        int rightChildVal = (node -> right? node -> right -> val : 0);
        
        if (level == 0 || level == 1)
            node -> val = 0;
        else
            node -> val = levelSums[level] - node -> val - siblingSum;
        replaceInternal(node -> left, rightChildVal, level + 1);
        replaceInternal(node -> right, leftChildVal, level + 1);
    }
    
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        calculateSumLevel(root, 0);
        replaceInternal(root, 0, 0);
        return root;
    }
};