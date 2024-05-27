class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> freq(n + 1);
        
        for (int num : nums)
            ++freq[min(n, num)];
        
        int numGreaterThanOrEqual = 0;
        for (int i = n; i >= 0; --i){
            numGreaterThanOrEqual += freq[i];
            if (numGreaterThanOrEqual == i)
                return i;
        }
        
        return -1;
    }
};