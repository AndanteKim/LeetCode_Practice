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
#define ull unsigned long long

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ull ans = 0;
        queue<pair<TreeNode*, ull>> queue;
        queue.push({root, 0});
        
        while (!queue.empty()){
            int sz = queue.size();
            auto [_, levelHeadIndex] = queue.front();
            ull levelLength;
            
            for (int i = 0; i < sz; ++i){
                auto [node, colIndex] = queue.front();
                queue.pop();
                levelLength = colIndex;
                
                if (node -> left) queue.push({node -> left, 2 * colIndex});
                if (node -> right) queue.push({node -> right, 2 * colIndex + 1});
            }
            ans = max(ans, levelLength - levelHeadIndex + 1);
        }
        return ans;
    }
};