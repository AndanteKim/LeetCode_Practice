class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int curr, prev = std::numeric_limits<int>::min(), ans = 0;

        for (int num : nums){
            curr = min(max(prev + 1, num - k), num + k);
            
            if (curr > prev){
                prev = curr;
                ++ans;
            }
        }

        return ans;
    }
};