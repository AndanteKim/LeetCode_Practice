class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int x = 0;

        for (int num : nums) x = ((x << 1) | num);

        if (x == 0 || k == 0) return true;

        while ((x & 1) == 0) x >>= 1;

        while (x != 1) {
            int count = 0;
            x >>= 1;

            while ((x & 1) == 0) {
                ++count;
                x >>= 1;
            }

            if (count < k) return false;
        }

        return true;
    }
};