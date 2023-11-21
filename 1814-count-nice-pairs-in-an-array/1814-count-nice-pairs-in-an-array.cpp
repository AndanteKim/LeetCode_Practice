class Solution {
private:
    int MOD = 1'000'000'007;
    int rev(int num){
        int res = 0;
        while (num > 0){
            res = res * 10 + num % 10;
            num /= 10;
        }
        
        return res;
    }
    
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> arr;
        for (int num : nums)
            arr.push_back(num - rev(num));
        
        int ans = 0;
        unordered_map<int, int> pairs;
        for (int num : arr){
            ans = (ans + pairs[num]) % MOD;
            ++pairs[num];
        }
        
        return ans;
    }
};