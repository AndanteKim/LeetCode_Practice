class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end()), u = 1;

        while (u <= m) u <<= 1;

        vector<bool> one(u), two(u), three(u);
        for (int v : nums) {
            one[v] = true;
            for (int x = 0; x < u; ++x) {
                if (one[x]) two[x ^ v] = true;
            }
        }

        for (int v : nums) {
            for (int x = 0; x < u; ++x) {
                if (two[x]) three[x ^ v] = true;
            }
        }

        return accumulate(three.begin(), three.end(), 0);
    }
};