class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) ++freq[num];

        int ans = 0;
        for (const auto& [num, cnt] : freq){
            if (freq.count(num - 1) > 0) ans = max(ans, cnt + freq[num - 1]);
            if (freq.count(num + 1) > 0) ans = max(ans, cnt + freq[num + 1]);
        }

        return ans;
    }
};