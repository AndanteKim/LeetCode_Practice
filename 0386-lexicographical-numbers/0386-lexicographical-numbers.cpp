class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int curr = 1;
        
        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i){
            ans.push_back(curr);
            
            // If multiplying the current number by 10 is within the limit, do it.
            if (curr * 10 <= n)
                curr *= 10;
            else{
                // Adjust the current number by moving up one digit
                while (curr % 10 == 9 || curr >= n)
                    curr /= 10;     // Remove the last digit
                
                ++curr;     // Increment the number
            }
        }
        
        
        return ans;
    }
};