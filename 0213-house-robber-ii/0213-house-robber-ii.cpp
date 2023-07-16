class Solution {
private:
    int robSimple(vector<int>& nums){
        int t1 = 0, t2 = 0;
        for (int current : nums){
            int temp = t1;
            t1 = max(current + t2, t1);
            t2 = temp;
        }
        
        return t1;
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> v1 = {nums.begin(), nums.end() - 1}, v2 = {nums.begin() + 1, nums.end()};
        
        return max(robSimple(v1), robSimple(v2));
    }
};