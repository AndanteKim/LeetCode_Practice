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
    int computeDepth(TreeNode* node){
        /*
        Return the depth in O(d) time.
        */
        
        int d = 0;
        while (node -> left){
            ++d;
            node = node -> left;
        }
        
        return d;
    }
    
    bool exists(int idx, int d, TreeNode* node){
        /*
        Last level nodes are enumerated from 0 to (1 << d) - 1 (left -> right).
        Return true if last level node idx exists.
        Binary search with O(d) complexity
        */
        int left = 0, right = (1 << d) - 1;
        
        for (int i = 0; i < d; ++i){
            int pivot = left + ((right - left) >> 1);
            if (idx <= pivot){
                node = node -> left;
                right = pivot;
            }
            else{
                node = node -> right;
                left = pivot + 1;
            }
        }
        
        return node? true : false;
    }
    
public:
    int countNodes(TreeNode* root) {
        // If the tree is empty
        if (!root)
            return 0;
        
        int d = computeDepth(root);
        // If the tree contains 1 node.
        if (d == 0) return 1;
        
        // Last level nodes are enumerated from 0 to (1 << d) - 1 (left -> right).
        // Perform binary search to check how many nodes exist.
        int left = 1, right = (1 << d) - 1;
        TreeNode* node = root;
        
        while (left <= right){
            int pivot = left + ((right - left) >> 1);
            
            if (exists(pivot, d, root)){
                left = pivot + 1;
            }
            else
                right = pivot - 1;
        }
        
        // The tree contains (1 << d) - 1 nodes on the first (d - 1) levels
        // and left nodes on the last level.
        return ((1 << d) - 1) + left;
    }
};