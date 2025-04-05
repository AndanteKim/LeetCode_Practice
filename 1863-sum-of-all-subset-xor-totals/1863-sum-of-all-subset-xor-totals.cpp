class Solution {
private:
    int ans = 0, n;
    void backtrack(int i, int prev, vector<int>& nums){
        if (i == n) return;

        int curr = prev ^ nums[i];
        ans += curr;
        backtrack(i + 1, prev, nums);
        backtrack(i + 1, curr, nums);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        this -> n = nums.size();
        backtrack(0, 0, nums);
        return ans;
    }
};