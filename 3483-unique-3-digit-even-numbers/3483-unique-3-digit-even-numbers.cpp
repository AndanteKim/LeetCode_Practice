class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> seen;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i == j || j == k || i == k) continue;

                    int curr = 100 * digits[i] + 10 * digits[j] + digits[k];
                    
                    if (curr >= 100 && curr % 2 == 0)
                        seen.insert(curr);
                }
            }
        }

        return seen.size();
    }
};