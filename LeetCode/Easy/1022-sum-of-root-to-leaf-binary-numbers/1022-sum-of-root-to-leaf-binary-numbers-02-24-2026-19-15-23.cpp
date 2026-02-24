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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});

        while (!st.empty()) {
            auto [node, curr] = st.top(); st.pop();

            if (node) {
                if (!(node -> left || node -> right)) ans += ((curr << 1) | node -> val);
                else {
                    st.push({node -> right, ((curr << 1) | node -> val)});
                    st.push({node -> left, ((curr << 1) | node -> val)});
                }
            }
        }

        return ans;
    }
};