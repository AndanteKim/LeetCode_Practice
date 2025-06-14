class Solution {
private:
    int n;
    int countValidPairs(vector<int>& nums, int threshold){
        int index = 0, count = 0;

        // Find the number of valid pairs by greedy approach.
        while (index < n - 1){
            // If a valid pair is found, skip both numbers.
            if (nums[index + 1] - nums[index] <= threshold){
                ++count;
                ++index;
            }
            ++index;
        }

        return count;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];

        while (left < right){
            int mid = left + ((right - left) >> 1);

            // If there are enough pairs, look for a smaller threshold.
            // Otherwise, look for a larger threshold.
            if (countValidPairs(nums, mid) >= p)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};