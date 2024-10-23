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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<int> levelSums;
        queue.push(root);
        
        // First BFS: Calculate sum of nodes at each level
        while (!queue.empty()){
            int size = queue.size();
            long levelSum = 0;
            
            for (int i = 0; i < size; ++i){
                TreeNode* node = queue.front(); queue.pop();
                levelSum += node -> val;
                
                if (node -> left) queue.push(node -> left);
                if (node -> right) queue.push(node -> right);
            }
            levelSums.push_back(levelSum);
        }
        
        // Second BFS: Update each node's value to sum of its cousins
        queue.push(root);
        root -> val = 0;    // Root has no cousins
        int levelIndex = 1;
        while (!queue.empty()){
            int size = queue.size();
            for (int i = 0; i < size; ++i){
                TreeNode* node = queue.front(); queue.pop();
                int siblingSum = (node -> left? node -> left -> val : 0) + \
                    (node -> right? node -> right -> val : 0);
                if (node -> left) {
                    node -> left -> val = levelSums[levelIndex] - siblingSum;
                    queue.push(node -> left);
                }
                
                if (node -> right){
                    node -> right -> val = levelSums[levelIndex] - siblingSum;
                    queue.push(node -> right);
                }
            }
            ++levelIndex;
        }
        
        return root;
    }
};