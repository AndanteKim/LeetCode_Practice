class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3);
        
        for (int num:nums)
            ++colors[num];
        
        int color = 0;
        for (int i = 0; i < nums.size(); ++i){
            while (colors[color] == 0) ++color;
            
            nums[i] = color;
            --colors[color];
        }
    }
};