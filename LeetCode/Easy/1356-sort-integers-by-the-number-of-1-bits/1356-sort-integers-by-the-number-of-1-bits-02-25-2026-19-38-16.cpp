class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = __builtin_popcount(a), countB = __builtin_popcount(b);
            return (countA == countB)? a < b : countA < countB;
        });

        return arr;
    }
};