class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int i = 0; i < n - 1; ++i) {
            unordered_map<int, int> oddFreq, evenFreq;
            for (int j = i; j < n; ++j) {
                if (nums[j] & 1) ++oddFreq[nums[j]];
                else ++evenFreq[nums[j]];
            
                if (oddFreq.size() == evenFreq.size()) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};