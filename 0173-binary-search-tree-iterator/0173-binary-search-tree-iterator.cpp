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
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()){
            TreeNode* node = st.top(); st.pop();
            minHeap.push(node -> val);
            
            if (node -> left)
                st.push(node -> left);
            
            if (node -> right)
                st.push(node -> right);
        }
    }
    
    int next() {
        int nxt = -1;
        if (hasNext()){
            nxt = minHeap.top();
            minHeap.pop();
        }
        return nxt;
    }
    
    bool hasNext() {
        return minHeap.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */