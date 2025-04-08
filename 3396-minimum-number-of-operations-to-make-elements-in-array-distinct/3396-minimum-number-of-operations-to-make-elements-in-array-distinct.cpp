class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0, i = 0, n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) ++freq[num];

        while (true){
            int uniqueCount = 0;

            for (auto& [key, val]: freq){
                if (val == 1) ++uniqueCount;
            }

            if (uniqueCount == freq.size()) break;
            
            int left = n - i;
            for (int j = 0; j < min(3, left); ++j){
                --freq[nums[i]];
                
                if (freq[nums[i]] == 0) freq.erase(nums[i]);
                ++i;
            }

            ++ans;
        }

        return ans;
    }
};