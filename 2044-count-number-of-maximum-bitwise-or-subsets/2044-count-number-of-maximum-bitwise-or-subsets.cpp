class Solution {
private:
    int ans = 0, n;
    long maxNum = 0;

    void backtrack(int i, long curr, vector<int>& nums){
        if (i == n){
            if (curr == maxNum) ++ans;
            return;
        }

        backtrack(i + 1, curr, nums);
        backtrack(i + 1, curr | nums[i], nums);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        this -> n = nums.size();
        long curr = 0;

        for (int num : nums) maxNum |= num;
        backtrack(0, curr, nums);
        return ans;
    }
};