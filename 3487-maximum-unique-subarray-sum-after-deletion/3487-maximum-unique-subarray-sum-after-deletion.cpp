class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        unordered_set<int> seen;

        for (int num : nums){
            if (seen.count(num)) continue;

            if (num > 0)
                seen.insert(num);
        }

        if (seen.size() == 0) return ans;
        
        ans = 0;
        for (int num : seen) ans += num; 

        return ans;
    }
};