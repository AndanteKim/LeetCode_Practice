class Solution {
private:
    int dfs(int rootPosition, int preSum, unordered_map<int, int>& tree){
        // Find the level and position values from the root position.
        int level = rootPosition / 10, position = rootPosition % 10;
        
        // Find out the left child and right child positions of the tree.
        int left = (level + 1) * 10 + 2 * position - 1, right = (level + 1) * 10 + 2 * position;
        int currSum = preSum + tree[rootPosition];
        
        // If the both left and right child don't exist, return.
        if (!(tree.count(left) || tree.count(right)))
            return currSum;
        
        // Otherwise, iterate through the left and right children recursively
        // using depth first search
        int leftSum = tree.count(left)? dfs(left, currSum, tree) : 0;
        int rightSum = tree.count(right)? dfs(right, currSum, tree) : 0;
        
        return leftSum + rightSum;
    }
    
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        unordered_map<int, int> tree;
        
        // Store the data in a hashmap, with the coordinates as the key and the
        // node value as the value.
        for (int num : nums)
            tree[num / 10] = num % 10; 
        
        return dfs(nums[0] / 10, 0, tree);
    }
};