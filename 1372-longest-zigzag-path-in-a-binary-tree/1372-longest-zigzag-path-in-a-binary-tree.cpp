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
    int longestZigZag(TreeNode* root) {
        
        // Time Complexity: O(n), Space Complexity: O(n)
        // start from root, None := no direction, length := length of longest connected line
        int ans = 0;
        queue<pair<TreeNode*, pair<int, int>>> queue;
        queue.push({root, {-1, 0}});
        
        // True:= right, False:= left
        while (!queue.empty()){
            auto [node, it] = queue.front();
            auto [dir, length] = it;
            queue.pop();
            
            ans = max(ans, length);
            ++length;
            
            if (node -> left){
                if (dir == -1 || dir == 1)
                    queue.push({node -> left, {0, length}});
                else
                    queue.push({node -> left, {0, 1}});
            }
            
            if (node -> right){
                if (dir == -1 || dir == 0)
                    queue.push({node -> right, {1, length}});
                else
                    queue.push({node -> right, {1, 1}});
            }
        }
        
        return ans;
    }
};