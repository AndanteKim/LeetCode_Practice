class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int sz = nums.size();
        nums.resize(sz * 2);
        for (int i = sz; i < sz * 2; ++i)
            nums[i] = nums[i % sz];
        return nums;
    }
};