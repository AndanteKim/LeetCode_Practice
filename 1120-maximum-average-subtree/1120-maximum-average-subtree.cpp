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
    double maximumAverageSubtree(TreeNode* root) {
        double ans = 0.0;
        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});
        unordered_map<TreeNode*, int> descendantSum, descendantLength;
        
        while (!st.empty()){
            auto [node, visited] = st.top();
            
            if (visited){
                descendantSum[node] = descendantSum[node -> left] + descendantSum[node -> right] + node -> val;
                descendantLength[node] = descendantLength[node -> left] + descendantLength[node -> right] + 1;
                ans = max(ans, (double)descendantSum[node] / descendantLength[node]);
                st.pop();
            }
            else{
                st.top().second = true;
                if (node -> right)
                    st.push({node -> right, false});
                if (node -> left)
                    st.push({node -> left, false});
            }
        }
        
        return ans;
    }
};