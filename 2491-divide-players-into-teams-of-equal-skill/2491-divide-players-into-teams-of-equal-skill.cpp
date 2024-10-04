typedef long long ll;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size(), pairsRemain = n >> 1;
        unordered_map<int, int> freq;
        int targetSkill = static_cast<int>(accumulate(skill.begin(), skill.end(), 0LL) / pairsRemain);
        ll ans = 0;
        
        for (int currentSkill : skill){
            int partnerSkill = targetSkill - currentSkill;
            if (freq[partnerSkill] > 0){
                ans += currentSkill * partnerSkill;
                --freq[partnerSkill];
                --pairsRemain;
            }
            else
                ++freq[currentSkill];
        }
        
        // If all pairs match
        return (pairsRemain == 0)? ans : -1;
    }
};