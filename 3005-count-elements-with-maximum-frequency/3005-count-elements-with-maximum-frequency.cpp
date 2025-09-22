class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0, maxFreq = 0;
        unordered_map<int, int> freq;

        for (int num : nums){
            ++freq[num];
            maxFreq = max(maxFreq, freq[num]);
        }

        for (const auto& [_, f] : freq)
            if (maxFreq == f) ans += f;
        
        return ans;
    }
};