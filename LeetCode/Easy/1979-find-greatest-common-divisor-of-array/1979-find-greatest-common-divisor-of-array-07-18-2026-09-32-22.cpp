class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = std::numeric_limits<int>::max(), mx = std::numeric_limits<int>::min();

        for (int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }

        return gcd(mx, mn);
    }
};