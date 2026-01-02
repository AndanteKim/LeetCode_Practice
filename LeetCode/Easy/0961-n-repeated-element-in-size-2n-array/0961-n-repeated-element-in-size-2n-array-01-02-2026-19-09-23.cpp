class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int doubleN = nums.size(), n = doubleN >> 1;
        unordered_map<int, int> counts;

        for (int num : nums)
            ++counts[num];
        
        for (const auto& [val, cnt] : counts)
            if (cnt == n) return val;

        return -1;
    }
};