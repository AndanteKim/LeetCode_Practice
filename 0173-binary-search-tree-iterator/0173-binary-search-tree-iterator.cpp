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
class BSTIterator {
private:
    // Pointer to the next smallest element in the BST
    int index = -1;
    
    // Array containing all the nodes in the sorted order
    vector<int> nodesSorted;
    
    void inorder(TreeNode* root){
        if (!root) return;
        
        inorder(root -> left);
        nodesSorted.push_back(root -> val);
        inorder(root -> right);
    }
    
public:
    BSTIterator(TreeNode* root) {
        this -> nodesSorted = vector<int>();
        // Call to flatten the input binary search tree
        inorder(root);
    }
    
    int next() {
        /*
        @return the next smallest number 
        */
        return nodesSorted[++index];
    }
    
    bool hasNext() {
        /*
        @return whether we have a next smallest number
        */
        return index + 1 < nodesSorted.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */