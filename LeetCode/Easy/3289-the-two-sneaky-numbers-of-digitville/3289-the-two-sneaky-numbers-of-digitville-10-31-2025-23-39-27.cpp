class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2, y = 0;
        
        for (int num : nums)
            y ^= num;

        for (int i = 0; i < n; ++i) y ^= i;

        int lowBit = y & (-y);
        int x1 = 0, x2 = 0;

        for (int num : nums){
            if (num & lowBit) x1 ^= num;
            else x2 ^= num;
        }

        for (int i = 0; i < n; ++i){
            if (i & lowBit) x1 ^= i;
            else x2 ^= i;
        }

        return vector<int>{x1, x2};
    }
};