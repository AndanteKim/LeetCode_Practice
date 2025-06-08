class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int currNum = 1;

        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i){
            ans.push_back(currNum);

            // If multiplying the current number by 10 is within the limit, do it.
            if (currNum * 10 <= n)
                currNum *= 10;
            else{
                // Adjust the current number by moving up one digit
                while (currNum % 10 == 9 || currNum >= n)
                    currNum /= 10;     // Remove the last digit
                ++currNum;      // Increment the number
            }
        }

        return ans;
    }
};