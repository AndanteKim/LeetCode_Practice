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
    int count = 0;
    void preorder(TreeNode* node, int path){
        
        if (node){
            // compute occurrences of each digit in the corresponding register
            path ^= (1 << (node -> val));
            // If it's a leaf, check if the path is a pseudo-palindromic
            if (!(node -> left || node -> right)){
                
                // check if at most one digit has an odd frequency
                if ((path & (path - 1)) == 0)
                    ++count;
                
            }
            
            preorder(node -> left, path);
            preorder(node -> right, path);
        }
        
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        
        preorder(root, 0);
        return count;
    }
};