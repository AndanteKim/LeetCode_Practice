class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        // Base case
        for (int i = 1; i < n; ++i){
            if (complexity[i] <= complexity[0]) return 0;
        }

        int ans = 1, mod = 1'000'000'007;

        for (int i = 2; i < n; ++i) {
            ans = static_cast<int>(((long long)ans * i) % mod);
        }

        return ans;
    }
};