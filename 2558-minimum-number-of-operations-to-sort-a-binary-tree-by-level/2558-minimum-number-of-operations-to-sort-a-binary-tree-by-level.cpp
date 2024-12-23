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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int ans = 0;
        
        // Process tree level by level using BFS
        while (!queue.empty()){
            int sz = queue.size();
            vector<int> arr;

            // Store values of current level and add children to queue
            for (int i = 0; i < sz; ++i){
                TreeNode* node = queue.front(); queue.pop();
                arr.push_back(node -> val);
                if (node -> left)
                    queue.push(node -> left);
                
                if (node -> right)
                    queue.push(node -> right);
            }

            // Add minimum swaps needed for current level
            ans += getMinSwaps(arr);
        }

        return ans;
    }

private:
    // Calculate minimum swaps needed to sort an array
    int getMinSwaps(vector<int>& arr){
        int swaps = 0;
        vector<int> target = arr;
        sort(target.begin(), target.end());
        
        // Map to track current positions of values
        unordered_map<int, int> pos;
        for (int i = 0; i < arr.size(); ++i)
            pos[arr[i]] = i;
        
        // For each position, swap until correct value is placed
        for (int i = 0; i < arr.size(); ++i){
            if (arr[i] != target[i]){
                ++swaps;
                
                // Update position of swapped values
                int currPos = pos[target[i]];
                pos[arr[i]] = currPos;
                swap(arr[currPos], arr[i]);
            }
        }

        return swaps;
    }
};