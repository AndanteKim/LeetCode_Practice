class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 0;
        long psum = 0;
        unordered_map<long, int> indices{{0, -1}};

        for (int i = 0; i < n; ++i){
            psum += nums[i];

            if (indices.count(psum - k)) maxLen = max(maxLen, i - indices[psum - k]);

            if (!indices.count(psum)) indices[psum] = i;
        }

        return maxLen;
    }
};