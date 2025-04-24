class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> unique;

        for (int num : nums)
            unique.insert(num);

        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i){
            unordered_map<int, int> seen;
            for (int j = i; j < n; ++j){
                ++seen[nums[j]];
                
                if (unique.size() == seen.size()) ++ans;
            }
        }

        return ans;
    }
};