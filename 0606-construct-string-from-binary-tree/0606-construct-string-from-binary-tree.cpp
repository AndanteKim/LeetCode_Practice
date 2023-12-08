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
    string tree2str(TreeNode* root) {
        stack<TreeNode*> st{{root}};
        set<TreeNode*> visited;
        string ans = "";
        
        while (!st.empty()){
            TreeNode* node = st.top();
            if (visited.count(node)){
                st.pop();
                ans.push_back(')');
            }
            else{
                visited.insert(node);
                ans.push_back('(');
                ans += to_string(node -> val);
                if (!node -> left && node -> right)
                    ans += "()";
                if (node -> right)
                    st.push(node -> right);
                if (node -> left)
                    st.push(node -> left);
            }
        }
        
        return ans.substr(1, ans.size() - 2);
    }
};