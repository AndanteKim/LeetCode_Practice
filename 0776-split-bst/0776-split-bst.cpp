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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        // Create dummy nodes to hold the split tree parts
        TreeNode *dummySM = new TreeNode(), *dummyLG = new TreeNode();
        TreeNode *currSM = dummySM, *currLG = dummyLG;
        
        // Start traversal from the root
        TreeNode *curr = root, *nextNode = nullptr;
        
        while (curr){
            if (curr -> val <= target){
                // Attach the current node to the tree with values
                // less than or equal to the target
                currSM -> right = curr;
                currSM = curr;
                
                // Move to the right subtree
                nextNode = curr -> right;
                
                // Clear the right pointer of current node
                currSM -> right = nullptr;
                curr = nextNode;
            }
            else{
                // Attach the current node to the tree with values
                // greater to the target
                currLG -> left = curr;
                currLG = curr;
                
                // Move to the left subtree
                nextNode = curr -> left;
                
                // Clear the left pointer of current node
                currLG -> left = nullptr;
                curr = nextNode;
            }
        }
        
        // Return the split parts as a list.
        return vector<TreeNode*>{dummySM -> right, dummyLG -> left};
    }
};