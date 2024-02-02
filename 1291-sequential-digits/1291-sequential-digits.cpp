class Solution {
private:
    int low, high;
    void backtrack(int curr, int start, int digit, vector<int>& ans){
        if (digit == 0){
            curr += start;
            if (low <= curr && curr <= high)
                ans.push_back(curr);
            return;
        }
        
        backtrack(curr + (start * pow(10, digit)), start + 1, digit - 1, ans);
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        this -> low = low, this -> high = high;
        int lowDigit = 0, highDigit = 0, lowest = low, highest = high;
        
        while (lowest >= 10){
            lowest /= 10;
            ++lowDigit;
        }
        
        while (highest >= 10){
            highest /= 10;
            ++highDigit;
        }
        
        for (int digit = lowDigit; digit <= highDigit; ++digit){
            for (int i = 1; i < 10 - digit; ++i){
                int curr = i * pow(10, digit);
                backtrack(curr, i + 1, digit - 1, ans);
            }
        }
        
        return ans;
    }
};