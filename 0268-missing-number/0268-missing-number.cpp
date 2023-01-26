class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> seen(nums.begin(), nums.end());
        
        for (int i = 0; i <= nums.size(); ++i) if (seen.find(i) == seen.end()) return i;
        
        return -1;
    }
};