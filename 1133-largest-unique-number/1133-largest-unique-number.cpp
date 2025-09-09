class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums)
            ++freq[num];

        int ans = -1;
        for (auto& [num, cnt] : freq){
            if (cnt == 1) ans = max(ans, num);
        }

        return ans;
    }
};