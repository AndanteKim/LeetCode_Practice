class Solution {
public:
    int pathSum(vector<int>& nums) {
        // Base case
        if (nums.empty())
            return 0;
        
        // Store the data in a hashmap, with the coordinates as the key and the node value as the value.
        unordered_map<int, int> tree;
        
        for (int num : nums)
            tree[num / 10] = num % 10;
        
        queue<pair<int, int>> queue;
        queue.push({nums[0] / 10, 0});
        int ans = 0;
        
        while (!queue.empty()){
            auto [rootPosition, prevSum] = queue.front(); queue.pop();
            int level = rootPosition / 10, position = rootPosition % 10;
            int currSum = prevSum + tree[rootPosition];
            int left = (level + 1) * 10 + 2 * position - 1, right = (level + 1) * 10 + 2 * position;
            
            if (!(tree.count(left) || tree.count(right))){
                ans += currSum;
                continue;
            }
            
            if (tree.count(left))
                queue.push({left, currSum});
            
            if (tree.count(right))
                queue.push({right, currSum});
        }
        
        return ans;
    }
};