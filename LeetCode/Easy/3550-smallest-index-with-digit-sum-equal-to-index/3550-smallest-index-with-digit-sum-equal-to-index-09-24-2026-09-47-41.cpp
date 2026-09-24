class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int curr = 0, num = nums[i];
            while (num > 0) {
                curr += num % 10;
                num /= 10;
            }

            if (i == curr) return i;
        }

        return -1;
    }
};