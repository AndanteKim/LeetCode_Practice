typedef long long ll;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size(), pairsRemain = n >> 1;
        unordered_map<int, int> freq;
        int average = static_cast<int>(accumulate(skill.begin(), skill.end(), 0LL) / pairsRemain);
        ll ans = 0;
        
        for (int s : skill){
            if (freq[average - s] > 0){
                ans += s * (average - s);
                --freq[average - s];
                --pairsRemain;
            }
            else
                ++freq[s];
        }
        
        return (pairsRemain == 0)? ans : -1;
    }
};