class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        return total % 2 == 0? nums.size() - 1 : 0;
    }
};