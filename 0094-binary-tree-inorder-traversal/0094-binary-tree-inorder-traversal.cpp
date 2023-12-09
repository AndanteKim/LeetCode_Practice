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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        
        stack<pair<TreeNode*, bool>> st;
        st.push(make_pair(root, false));
        vector<int> ans;
        
        while(!st.empty()){
            auto [node, visited] = st.top();
            st.pop();
            
            if (!visited){
                if (node -> right)
                    st.push({node -> right, false});
                st.push({node, true});
                if (node -> left)
                    st.push({node -> left, false});
            }
            else
                ans.push_back(node -> val);
        }
        
        return ans;
    }
};