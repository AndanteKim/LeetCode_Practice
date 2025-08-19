class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;

        for (int num : nums){
            if (num == 0) ++count;
            else {
                ans += (count * (count + 1) >> 1);
                count = 0;
            }
        }

        if (count != 0) ans += (count * (count + 1) >> 1);

        return ans;
    }
};