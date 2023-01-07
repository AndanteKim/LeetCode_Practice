class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0, n = arr.size(), left, right;
        
        for (int i = 0; i < n; ++i){
            left = i;
            right = n - i - 1;
            
            ans += (arr[i] * (left/2 + 1) * (right/2 + 1));
            ans += (arr[i] * ((left+1) / 2) * ((right+1)/2));
        }
        
        return ans;
    }
};