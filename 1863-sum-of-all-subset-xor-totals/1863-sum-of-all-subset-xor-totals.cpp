class Solution {
private:
    int ans = 0, n;
    
    void backtrack(int i, int curr, vector<int>& nums){
        // base case
        if (i == n){
            ans += curr;
            return;
        }
        
        backtrack(i + 1, curr ^ nums[i], nums);
        backtrack(i + 1, curr, nums);
    }
    
public:
    int subsetXORSum(vector<int>& nums) {
        this -> n = nums.size();
        backtrack(0, 0, nums);
     
        return ans;
    }       
};