class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[(i + k) % n] = nums[i];
        nums = a;
    }
};