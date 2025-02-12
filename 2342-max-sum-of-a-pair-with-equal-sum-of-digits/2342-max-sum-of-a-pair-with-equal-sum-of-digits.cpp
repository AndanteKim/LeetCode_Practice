class Solution {
private:
    // Helper function to compute the sum of digits of a number
    int calculateDigitSum(int num){
        int digitSum = 0;
        while (num > 0){
            digitSum += num % 10;
            num /= 10;
        }

        return digitSum;
    }

public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> digitSumPairs;

        // Store numbers with their digit sums as pairs
        for (int num: nums){
            int digitSum = calculateDigitSum(num);
            digitSumPairs.push_back({digitSum, num});
        }

        // Sort based on digit sums, and if equal, by number value
        sort(digitSumPairs.begin(), digitSumPairs.end());

        int ans = -1;

        // Iterate through the sorted array to find the maximum sum of pairs
        for (int index = 1; index < digitSumPairs.size(); ++index){
            int currDigitSum = digitSumPairs[index].first, prevDigitSum = digitSumPairs[index - 1].first;

            // If two consecutive numbers have the same digit sum
            if (currDigitSum == prevDigitSum){
                int currSum = digitSumPairs[index].second + digitSumPairs[index - 1].second;

                ans = max(ans, currSum);
            }
        }
        
        return ans;
    }
};