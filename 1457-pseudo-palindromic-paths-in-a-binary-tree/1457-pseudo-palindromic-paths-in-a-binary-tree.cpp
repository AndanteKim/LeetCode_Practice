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
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        
        while (!st.empty()){
            auto [node, path] = st.top();
            st.pop();
            
            if (node){
                // Compute occurrences of each digit in the corresponding register
                path = path ^ (1 << (node -> val));
                // If it's a leaf, then check if the path is pseudo-palindromic
                if (!(node -> left || node -> right)){
                    // Check if at most one digit has an odd frequency
                    if ((path & (path - 1)) == 0) ++ans;
                }
                else{
                    st.push({node -> right, path});
                    st.push({node -> left, path});
                }
            }
        }
        
        return ans;
    }
};