class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = count(data.begin(), data.end(), 1), left = 0, maxOne = 0, countOne = 0;

        for (int right = 0; right < data.size(); ++right){
            // Updating the number of 1's by adding the new element
            countOne += data[right];

            // Maintain the length of the window to ones
            if (right - left >= ones){
                // Updating the number of 1's by removing the oldest element
                countOne -= data[left++];
            }

            // Record the maximum number of 1's in the window
            maxOne = max(maxOne, countOne);
        }

        return ones - maxOne;
    }
};