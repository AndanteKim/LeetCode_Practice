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
    vector<int> findMode(TreeNode* root) {
        int maxStreak = 0, currStreak = 0, currNum = 0;
        TreeNode *curr = root, *left;
        vector<int> ans;
        
        while (curr){
            if (curr -> left){
                // find the friend
                TreeNode* friendNode = curr -> left;
                while (friendNode -> right)
                    friendNode = friendNode -> right;
                
                friendNode -> right = curr;
                
                // Delete the edge after using it
                left = curr -> left;
                curr -> left = nullptr;
                curr = left;
            }
            else{
                int num = curr -> val;
                if (num == currNum)
                    ++currStreak;
                else{
                    currStreak = 1;
                    currNum = num;
                }
                
                if (currStreak > maxStreak){
                    ans = {};
                    maxStreak = currStreak;
                }
                
                if (currStreak == maxStreak)
                    ans.push_back(num);
                
                curr = curr -> right;
            }
        }
        
        return ans;
    }
};