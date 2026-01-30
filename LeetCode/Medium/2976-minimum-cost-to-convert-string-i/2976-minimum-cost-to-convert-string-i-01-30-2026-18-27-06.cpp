typedef long long ll;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Initialize a 2D vector to store the minimum transformation cost
        vector minCost(26, vector<ll>(26, std::numeric_limits<int>::max()));
        int m = source.size(), n = original.size();
        for (int i = 0; i < n; ++i) {
            int orig = original[i] - 'a', chg = changed[i] - 'a';
            minCost[orig][chg] = min(minCost[orig][chg], 1LL * cost[i]);
        }

        // Floyd-Warshall algorithm
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }

        // Calculate the total minimum cost
        ll ans = 0;
        for (int i = 0; i < m; ++i) {
            if (source[i] == target[i]) continue;

            int sourceCh = source[i] - 'a', targetCh = target[i] - 'a';
            if (minCost[sourceCh][targetCh] >= std::numeric_limits<int>::max()) return -1;
            ans += minCost[sourceCh][targetCh];
        }

        return ans;
    }
};