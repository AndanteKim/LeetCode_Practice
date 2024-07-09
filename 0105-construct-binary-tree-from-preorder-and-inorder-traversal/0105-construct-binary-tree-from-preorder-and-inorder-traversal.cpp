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
    int preorderIndex = 0;
    TreeNode* arrayToTree(int left, int right, unordered_map<int, int>& inorderIndexMap, vector<int>& preorder){
        // Base case: if there are no elements to construct the tree
        if (left > right)
            return nullptr;
        
        // select the preorderIndex element as the root and increment it
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        // build left and right subtree
        // excluding inorderIndexMap[rootVal] element because it's the root 
        root -> left = arrayToTree(left, inorderIndexMap[rootVal] - 1, inorderIndexMap, preorder);
        root -> right = arrayToTree(inorderIndexMap[rootVal] + 1, right, inorderIndexMap, preorder);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndexMap;
        

        // Build a hashmap to store value -> its index relations
        for (int i = 0; i < inorder.size(); ++i)
            inorderIndexMap[inorder[i]] = i;
        
        return arrayToTree(0, preorder.size() - 1, inorderIndexMap, preorder);
    }
};