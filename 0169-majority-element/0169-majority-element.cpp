class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, count = 0;
        
        for (int num:nums){
            if (ans != num){
                if (count == 0){
                    ans = num;
                    ++count;
                }
                else --count;
            }
            else
                ++count;
                
        }
        
        return ans;
    }
};