class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int, int> divisors, divisorsCount;
        int maxNum = *max_element(nums.begin(), nums.end());

        for (int i = 1; i <= maxNum; ++i) {
            long curr = i;
            while (curr <= maxNum) {
                divisors[curr] = divisors[curr] + i;
                ++divisorsCount[curr];
                curr += i;
            }
        }

        int ans = 0;

        for (const int num : nums){
            if (divisorsCount[num] == 4) ans += divisors[num];
        }

        return ans;
    }
};