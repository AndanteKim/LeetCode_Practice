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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> bfs;
        bfs.push({nullptr, root});
        bool isOdd = false;
        
        while (!bfs.empty()){
            int n = bfs.size();
            
            if (isOdd){
                stack<int> st;
                for (int i = 0; i < n; ++i){
                    auto [parent, child] = bfs.front(); bfs.pop();
                    st.push(child -> val);
                    bfs.push({parent, child});
                }
                
                for (int i = 0; i < n; ++i){
                    auto [parent, child] = bfs.front(); bfs.pop();
                    child -> val = st.top(); st.pop();
                    bfs.push({parent, child});
                }
            } 
                
            for (int i = 0; i < n; ++i){
                auto [parent, child] = bfs.front(); bfs.pop();
                if (child -> left && child -> right){
                    bfs.push({child, child -> left});
                    bfs.push({child, child -> right});
                }
            }
            
            isOdd = !isOdd;
        }
        
        return root;
    }
};