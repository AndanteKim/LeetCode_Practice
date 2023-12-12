class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> counting(pow(10, 3) + 1);
        int i = INT_MIN;
        for (int num : nums){
            i = max(num, i);
            ++counting[num];
        }
        
        long ans = 1;
        int remain = 2;
        for(; i >= 0 && remain > 0; --i){
            while (counting[i] > 0 && remain > 0){
                ans *= i - 1;
                --counting[i];
                --remain;
            }
        }
        
        return ans;
    }
};