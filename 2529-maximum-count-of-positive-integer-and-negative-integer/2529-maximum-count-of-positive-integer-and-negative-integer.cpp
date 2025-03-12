class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0;

        for (int num : nums){
            if (num < 0) ++neg;
            else if (num > 0) ++pos;
        }

        return max(pos, neg);
    }
};