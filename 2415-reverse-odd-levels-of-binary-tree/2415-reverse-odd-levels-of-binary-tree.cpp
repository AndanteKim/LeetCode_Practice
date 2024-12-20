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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;     // Return null if the tree is empty.
        
        int level = 0;
        queue<TreeNode*> queue;
        queue.push(root);   // Start BFS with the root node.
        
        while (!queue.empty()){
            int n = queue.size();
            vector<TreeNode*> currentLevelNodes;
            
            // Process all nodes at the current level.
            for (int i = 0; i < n; ++i){
                TreeNode* node = queue.front(); queue.pop();
                currentLevelNodes.push_back(node);
                
                if (node -> left)
                    queue.push(node -> left);
                
                if (node -> right)
                    queue.push(node -> right);
            }
            
            // Reverse node values if the current level is odd.
            if (level % 2){
                int left = 0, right = currentLevelNodes.size() - 1;
                while (left < right){
                    swap(currentLevelNodes[left++] -> val, currentLevelNodes[right--] -> val);
                }
            }
            
            ++level;
        }
        
        return root;    // Return the modified tree root.
    }
};