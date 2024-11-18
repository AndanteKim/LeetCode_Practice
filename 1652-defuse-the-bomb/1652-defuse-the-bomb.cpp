class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        
        // Define the initial window and initial sum
        int start = 1, end = k;
        long currSum = 0;
        
        // If k < 0, the starting point will be the end of the array.
        if (k < 0){
            start = n - abs(k);
            end = n - 1;
        }
        
        for (int i = start; i <= end; ++i) currSum += code[i];
        
        // Scan through the code array as i moving to the right, update the window sum.
        for (int i = 0; i < n; ++i){
            ans[i] = currSum;
            currSum = currSum - code[start % n] + code[(end + 1) % n];
            ++start;
            ++end;
        }
        
        return ans;
    }
};