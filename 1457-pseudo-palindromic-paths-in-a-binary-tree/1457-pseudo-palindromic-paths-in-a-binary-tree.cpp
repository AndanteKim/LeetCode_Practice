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
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        vector<int> cases;
        
        while (!q.empty()){
            auto[node, curr] = q.front();
            q.pop();
            
            curr ^= (1 << (node -> val));
            
            if (!(node -> left || node -> right))
                cases.push_back(curr);
            
            if (node -> left)
                q.push(make_pair(node -> left, curr));
            
            if (node -> right)
                q.push(make_pair(node -> right, curr));
        }
        
        for (int cs:cases){
            bool flag = false, existOdd = false;
            
            for (int i = 1; i < 10; ++i){
                if (cs & (1 << i)){
                    if (existOdd){
                        flag = true;
                        break;
                    }
                    existOdd = true;
                }
            }
            
            if (!flag)
                ++ans;
        }
        
        return ans;
    }
};