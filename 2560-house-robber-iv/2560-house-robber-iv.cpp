class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // Store the maximum nums value in maxReward.
        int n = nums.size(), minReward = 1, maxReward = *max_element(nums.begin(), nums.end());
        
        // Use binary search to find the minimum reward possible.
        while (minReward < maxReward){
            int midReward = minReward + ((maxReward - minReward) >> 1);
            int houseRobbed = 0;

            for (int i = 0; i < n;){
                
                if (nums[i] <= midReward){
                    ++houseRobbed;
                    i += 2; // Skip the next house to maintain the non-adjacent condition
                }
                else
                    i += 1;
            }

            if (houseRobbed >= k)
                maxReward = midReward;
            else
                minReward = midReward + 1;
        }

        return minReward;
    }
};