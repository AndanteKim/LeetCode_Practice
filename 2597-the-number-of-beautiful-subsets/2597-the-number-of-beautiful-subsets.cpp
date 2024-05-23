class Solution {
private:
    int n;
    int countBeautifulSubsets(vector<int>& nums, int diff, int i, int mask){
        if (i == n)
            return (mask > 0)? 1 : 0;
        
        bool isBeautiful = true;
        int count = 0;
        for (int j = 0; j < i; ++j){
            if (((1 << j) & mask) == 0 || abs(nums[j] - nums[i]) != diff)
                continue;
            else{
                isBeautiful = false;
                break;
            }
        }
        if (isBeautiful) count = countBeautifulSubsets(nums, diff, i + 1, mask | (1 << i));
        
        int skip = countBeautifulSubsets(nums, diff, i + 1, mask);
        return skip + count;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        this -> n = nums.size();
        return countBeautifulSubsets(nums, k, 0, 0);
    }
};