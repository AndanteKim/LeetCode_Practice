class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_val = 0, total = 0;
        
        for (const int &num: nums){
            total += num;
            min_val = min(min_val, total);
        }
        
        return -min_val + 1;
    }
};