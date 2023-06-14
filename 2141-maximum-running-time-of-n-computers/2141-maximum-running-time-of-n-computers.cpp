typedef long long ll;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        //int sz = batteries.size();
        ll extra = accumulate(batteries.begin(), batteries.end() - n, 0ll);
        vector<int> live;
        live.insert(live.end(), batteries.end() - n, batteries.end());
        
        for (int i = 0; i < n - 1; ++i){
            if (extra / (i + 1) < live[i + 1] - live[i]) return live[i] + extra / (i + 1);
            extra -= (i + 1) * (live[i + 1] - live[i]);
        }
        return live.back() + extra / n;
    }
};