class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        vector<int> force(n, 0);
        int f = 0;
        // Populate forces going from left to right
        for (int i = 0; i < n; ++i){
            if (dominoes[i] == 'R') f = n;
            else if (dominoes[i] == 'L') f = 0;
            else f = max(f - 1, 0);
            force[i] += f;
        }

        f = 0;
        // Populate forces going from right to left
        for (int i = n - 1; i >= 0; --i){
            if (dominoes[i] == 'L') f = n;
            else if (dominoes[i] == 'R') f = 0;
            else f = max(f - 1, 0);
            force[i] -= f;
        }

        string ans = "";
        for (int f : force){
            if (f == 0) ans.push_back('.');
            else if (f > 0) ans.push_back('R');
            else ans.push_back('L');
        }

        return ans;
    }
};