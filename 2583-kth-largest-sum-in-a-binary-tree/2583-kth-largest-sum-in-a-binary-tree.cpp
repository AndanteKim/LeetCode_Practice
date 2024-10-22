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
typedef long long ll;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Use queue and min heap to find the kth largest level sum
        queue<TreeNode*> queue;
        queue.push(root);
        priority_queue<ll, vector<ll>, greater<ll>> kLargestSums;
        
        while (!queue.empty()){
            int sz = queue.size();
            ll currSum = 0;
            for (int i = 0; i < sz; ++i){
                TreeNode* node = queue.front(); queue.pop();
                currSum += node -> val;
                
                if (node -> left) queue.push(node -> left);
                if (node -> right) queue.push(node -> right);
            }
            
            // If the size of kLargestSums is larger or equal to k
            if (kLargestSums.size() >= k){
                // Swap the lowest sum of min heap and current level sum
                if (currSum > kLargestSums.top()){
                    kLargestSums.pop();
                    kLargestSums.push(currSum);
                }
            }
            else
                kLargestSums.push(currSum);
        }
        
        return (kLargestSums.size() != k)? -1 : kLargestSums.top();
    }
};