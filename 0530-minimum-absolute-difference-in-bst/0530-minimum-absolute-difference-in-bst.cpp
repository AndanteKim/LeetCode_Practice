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
    int getMinimumDifference(TreeNode* root) {
        TreeNode *prevNode = NULL, *currNode = root;
        int ans = INT_MAX;
        stack<TreeNode*> stack;
        
        while(currNode || !stack.empty()){
            if (currNode){
                stack.push(currNode);
                currNode = currNode -> left;
            }
            else{
                currNode = stack.top();
                stack.pop();
                if (prevNode != nullptr) ans = min(ans, abs(prevNode -> val - currNode -> val));
                prevNode = currNode;
                currNode = currNode -> right;
            }
        }
        return ans;
    }
};