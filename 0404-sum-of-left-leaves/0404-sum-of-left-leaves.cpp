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
    int sumOfLeftLeaves(TreeNode* root) {
        int total_sum = 0;
        TreeNode* current_node = root, *previous;
        
        while (current_node != NULL){
            if (current_node -> left == NULL) current_node = current_node -> right;
            else{
                previous = current_node -> left;
                if (!(previous -> left || previous -> right)) total_sum += previous -> val;
                
                while (previous -> right != NULL && previous -> right != current_node) previous = previous -> right;
                
                if (previous -> right == NULL){
                    previous -> right = current_node;
                    current_node = current_node -> left;
                }
                else{
                    previous -> right = NULL;
                    current_node = current_node -> right;
                }
            }
        }
        
        return total_sum;
    }
};