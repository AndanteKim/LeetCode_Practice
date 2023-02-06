class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int firstNum, secondNum;
        for (int i = n ; i < 2 * n; ++i){
            secondNum = nums[i] << 10;
            nums[i - n] |= secondNum;
        }
        
        int allOnes = int(pow(2, 10)) - 1;
        
        for (int i = n - 1; i >= 0; --i){
            firstNum = nums[i] & allOnes;
            secondNum = nums[i] >> 10;
            
            nums[2 * i] = firstNum;
            nums[2 * i + 1] = secondNum;
        }
        
        return nums;
    }
};