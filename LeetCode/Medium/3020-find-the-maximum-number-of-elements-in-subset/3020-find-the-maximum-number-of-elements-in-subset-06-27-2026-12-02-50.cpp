class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int num : nums) ++freq[num];

        int oneCnt = freq[1] % 2 == 0? freq[1] - 1 : freq[1];
        int ans = oneCnt;
        freq.erase(1);

        for (const auto& [num, _] : freq) {
            int curr = 0;
            long long x = num;

            for (;freq.contains(x) && freq[x] > 1; x *= x)
                curr += 2;

            ans = max(ans, curr + (freq.contains(x)? 1 : -1));
        }

        return ans;
    }
};