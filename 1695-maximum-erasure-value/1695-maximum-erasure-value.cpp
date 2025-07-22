class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, curr = 0, ans = 0;

        for (int right = 0; right < nums.size(); ++right){
            while (seen.count(nums[right])){
                seen.erase(nums[left]);
                curr -= nums[left++];
            }

            seen.insert(nums[right]);
            curr += nums[right];
            ans = max(ans, curr);
        }

        return ans;
    }
};