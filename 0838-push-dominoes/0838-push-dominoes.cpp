class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = dominoes;
        int n = dominoes.size();
        vector<pair<int, char>> symbols;

        for (int i = 0; i < n; ++i){
            if (dominoes[i] != '.') symbols.push_back({i, dominoes[i]});
        }

        symbols.insert(symbols.begin(), {-1, 'L'});
        symbols.push_back({n, 'R'});

        for (int i = 0; i < symbols.size() - 1; ++i){
            auto [i1, x] = symbols[i]; auto [i2, y] = symbols[i + 1];

            if (x == y){
                for (int k = i1 + 1; k < i2; ++k)
                    ans[k] = x;
            }
            else if (x > y){    // RL case
                string candidates = ".LR";
                for (int k = i1 + 1; k < i2; ++k)
                    ans[k] = (k - i1 == i2 - k)? '.' : (k - i1 > i2 - k)? 'L' : 'R';
            }
        }

        return ans;
    }
};