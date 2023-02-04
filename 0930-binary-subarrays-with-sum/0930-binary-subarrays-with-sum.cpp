class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int ans = 0, curr = 0;
        
        for (const int& num : nums){
            curr += num;
            ans += counts[curr - goal];
            ++counts[curr];
        }
        
        return ans;
    }
};