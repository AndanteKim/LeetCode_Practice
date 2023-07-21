class Solution {
private:
    void calculateDp(int i, vector<int>& nums, vector<int>& length, vector<int>& count){
        if (length[i]) return;
        
        length[i] = 1, count[i] = 1;
        for (int j = 0; j < i; ++j){
            if (nums[j] < nums[i]){
                calculateDp(j, nums, length, count);
                if (length[j] + 1 > length[i]){
                    length[i] = length[j] + 1;
                    count[i] = 0;
                }
            
                if (length[j] + 1 == length[i]){
                    count[i] += count[j];
                }
            }
        }
    }
    
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0, maxLength = 0;
        vector<int> length(n, 0), count(n, 0);
        
        for (int i = 0; i < n; ++i){
            calculateDp(i, nums, length, count);
            maxLength = max(maxLength, length[i]);
        }
        
        for (int i = 0; i < n; ++i){
            if (length[i] == maxLength){
                ans += count[i];
            }
        }
        
        return ans;
    }
};