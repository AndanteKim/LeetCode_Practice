class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> count;

        for (int elem : power) ++count[elem];
        
        vector<pair<int, int>> spells{{-1e9, 0}};

        for (auto& p : count) spells.push_back(p);

        int n = spells.size();
        long long maxDamage = 0;
        vector<long long> f(n, 0);
        for (int i = 1, j = 1; i < n; ++i){

            while (j < i && spells[j].first < spells[i].first - 2)
                maxDamage = max(maxDamage, f[j++]);

            f[i] = maxDamage + 1LL * spells[i].first * spells[i].second;
        }

        return *max_element(f.begin(), f.end());
    }

};