class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq;

        for (int num : nums){
            ++freq[num];
            if (freq.count(num - 1) > 0) ans = max(ans, freq[num] + freq[num - 1]);
            if (freq.count(num + 1) > 0) ans = max(ans, freq[num] + freq[num + 1]);
        }

        return ans;
    }
};