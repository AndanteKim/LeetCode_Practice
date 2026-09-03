class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;
        int mn = 1'000'000'001;

        for (int num : nums1) {
            mn = min(mn, num);

            if (num & 1) hasOdd = true;
        }

        if (mn & 1) return true;

        return !hasOdd;
    }
};