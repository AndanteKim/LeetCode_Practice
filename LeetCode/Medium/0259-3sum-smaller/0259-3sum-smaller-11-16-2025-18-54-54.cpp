class Solution {
private:
    int n;

    int twoSum(vector<int>& nums, int start, int target) {
        int left = start, right = n - 1;
        int total = 0;

        while (left < right) {
            if (nums[left] + nums[right] < target) {
                total += right - (left++);
            }
            else --right;
        }

        return total;
    }

public:
    int threeSumSmaller(vector<int>& nums, int target) {
        this -> n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            ans += twoSum(nums, i + 1,target - nums[i]);
        }

        return ans;
    }
};