class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> firstMap, secondMap;
        
        // Add all elements of nums to sexond_map
        for (int i = 0; i < n; ++i) ++secondMap[nums[i]];

        for (int i = 0; i < n; ++i){
            // Create split at current index
            --secondMap[nums[i]];
            ++firstMap[nums[i]];

            // Check if valid split
            if (firstMap[nums[i]] * 2 > i + 1 && secondMap[nums[i]] * 2 > n - i - 1)
                return i;
        }

        // No valid split exists
        return -1;
    }
};