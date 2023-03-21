class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0;
        vector<int> arr_0;
        
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 0) {
                arr_0.push_back(0);
                if (i == nums.size() - 1) {
                    total += (arr_0.size() * (arr_0.size() + 1)) / 2;
                    arr_0.clear();
                }
            }
            else{
                total += (arr_0.size() * (arr_0.size() + 1)) / 2;
                arr_0.clear();
            }
        }
        
        return total;
    }
};