class Solution {
public:
    int getLucky(string s, int k) {
        int currSum = 0;
        
        // Convert the string to a number by summing digit values
        for (const auto& c : s){
            int pos = int(c) - 96;
            while (pos > 0){
                currSum += pos % 10;
                pos /= 10;
            }
        }
        
        // Apply digit sum transformations k - 1 times
        for (int i = 1; i < k; ++i){
            int sum = 0;
            while (currSum > 0){
                sum += currSum % 10;
                currSum /= 10;
            }
            currSum = sum;
        }
        
        return currSum;
    }
};