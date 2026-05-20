class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freqA, freqB;
        int n = A.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            ++freqA[A[i]];
            ++freqB[B[i]];

            for (const auto& [num, cnt] : freqA) {
                if (freqB.contains(num))
                    ++ans[i];
            }
        }

        return ans;
    }
};