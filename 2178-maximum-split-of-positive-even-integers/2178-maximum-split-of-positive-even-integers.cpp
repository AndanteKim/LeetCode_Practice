typedef long long ll;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2) return {};
        vector<ll> ans;
        ll i = 2;
        while (i <= finalSum){
            ans.push_back(i);
            finalSum -= i;
            i += 2;
        }
        ans.back() += finalSum; 
        return ans;
    }
};