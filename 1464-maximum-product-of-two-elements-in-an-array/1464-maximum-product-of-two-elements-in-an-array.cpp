class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first = nums.back() - 1, second;
        nums.pop_back();
        second = nums.back() - 1;
        nums.pop_back();
        
        return first * second;
    }
};