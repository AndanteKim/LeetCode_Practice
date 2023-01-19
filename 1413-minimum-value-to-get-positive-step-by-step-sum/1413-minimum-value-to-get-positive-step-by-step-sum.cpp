class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size(), m = 100;
        int left = 1, right = n * m + 1;
        while (left < right){
            int mid = (left + right) >> 1;
            int total = mid;
            bool is_valid = true;
            
            for (const int &num : nums){
                total += num;
                if (total < 1) is_valid = false;
            }
            
            if (is_valid) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};