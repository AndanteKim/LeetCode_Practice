class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> count{{0, 0}, {1, 0}, {2, 0}};
        int n = nums.size();
        for (int num : nums) ++count[num];

        for (int i = 0; i < n; ++i){
            if (count[0] > 0){
                --count[0];
                nums[i] = 0;
            }
            else if (count[1] > 0){
                --count[1];
                nums[i] = 1;
            }
            else{
                nums[i] = 2;
                --count[2];
            }
        }
        
    }
};