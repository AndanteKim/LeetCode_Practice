class Solution {
private:
    int n;

    int binarySearch(int num, vector<int>& nums, int left, int target){
        int right = n - 1;
        while (left <= right){
            int mid = left + ((right - left) >> 1);

            if (nums[mid] < target - num)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return right;
    }

public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        this -> n = nums.size();
        int ans = 0;
        for (int left = 0; left < n - 1; ++left){
            int right = binarySearch(nums[left], nums, left + 1, target);
            ans += right - left;
        }

        return ans;
    }
};