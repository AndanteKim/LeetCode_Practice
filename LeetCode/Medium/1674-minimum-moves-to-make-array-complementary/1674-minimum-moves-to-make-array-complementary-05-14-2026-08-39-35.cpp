class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2);

        for (int i = 0; i < (n >> 1); ++i) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);
            
            diff[2] += 2;
            --diff[a + 1];
            --diff[a + b];
            ++diff[a + b + 1];
            ++diff[b + limit + 1];
        }

        int minOps = n, currOps = 0;

        for (int c = 2; c <= 2 * limit; ++c) {
            currOps += diff[c];
            minOps = min(minOps, currOps);
        }
        
        return minOps;
    }
};