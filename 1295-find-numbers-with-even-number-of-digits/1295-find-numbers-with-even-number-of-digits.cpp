class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;

        for (int num : nums){
            int digits = 0;
            while (num > 0){
                num /= 10;
                ++digits;
            }

            if (digits % 2 == 0) ++ans;
        }

        return ans;
    }
};