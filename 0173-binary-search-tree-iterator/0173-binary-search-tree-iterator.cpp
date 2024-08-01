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
    // Stack for the recursion simulation
    stack<TreeNode*> st;
    
    void leftmostInorder(TreeNode* root){
        // For a given node, add all the elements in the leftmost branch of the 
        // tree under it to the stack.
        while (root){
            st.push(root);
            root = root -> left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        leftmostInorder(root);
    }
    
    int next() {
        /*
        @ return the smallest number
        */
        // Node at the top of the stack is the next smallest element
        TreeNode* topmostNode = st.top(); st.pop();
        
        // Need to maintain the invariant. If the node has a right child, call
        // the helper function for the right child.
        if (topmostNode -> right)
            leftmostInorder(topmostNode -> right);
        
        return topmostNode -> val;
    }
    
    bool hasNext() {
        /*
        @ return whether we have a next smallest number
        */
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */