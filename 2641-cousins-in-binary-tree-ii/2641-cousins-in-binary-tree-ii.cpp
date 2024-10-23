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
        int prevLevelSum = root -> val;
        queue.push(root);
        
        while (!queue.empty()){
            int size = queue.size();
            int currLevelSum = 0;
            
            for (int i = 0; i < size; ++i){
                TreeNode* node = queue.front(); queue.pop();
                // Update node value to cousin sum
                node -> val = prevLevelSum - node -> val;
                
                // Calculate sibling sum
                int siblingSum = (node -> left? node -> left -> val : 0) + \
                    (node -> right? node -> right -> val : 0);
                
                if (node -> left){
                    // Accumulate current level sum
                    currLevelSum += node -> left -> val;
                    // Update left child's value
                    node -> left -> val = siblingSum;
                    // Add to queue for next level
                    queue.push(node -> left);
                }
                
                if (node -> right){
                    // Accumulate current level sum
                    currLevelSum += node -> right -> val;
                    // Update right child's value
                    node -> right -> val = siblingSum;
                    // Add to queue for next level
                    queue.push(node -> right);
                }
            }
            
            // Update previous level sum for next iteration
            prevLevelSum = currLevelSum;
        }
        
        return root;
    }
};