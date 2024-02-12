class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, count = 0;
        
        for (int num:nums){
            if (count == 0)
                ans = num;
            (ans == num)? ++count:--count; 
            
        }
        
        return ans;
    }
};