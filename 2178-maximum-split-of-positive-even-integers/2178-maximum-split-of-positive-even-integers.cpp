typedef long long ll;

class Solution {
private:
    vector<ll> ans;
    bool backtrack(ll target, ll currSum, vector<ll>& path, ll start){
        if (currSum == target){
            if (path.size() > ans.size()) {
                ans = path;
            }
            return true;
        }
        
        for (ll i = start; i <= target; i += 2){
            if (i + currSum > target) break;
            path.push_back(i);
            if (backtrack(target, currSum + i, path, start + 2)) return true;
            path.pop_back();
        }
        return false;
    }
    
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum & 1) return {};
        vector<ll> path{};
        backtrack(finalSum, 0, path, 2);
        return ans;
    }
};