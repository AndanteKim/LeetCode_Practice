class Solution {
public:
    bool check(vector<int> &pref, int maxCost, int mid){
        int l = 0, r = mid;
        bool flag = false;
        while (r < pref.size()){
            int sum = pref[r] - pref[l];
            if (sum <= maxCost) {
                flag = true;
                break;
            }
            ++l;
            ++r;
        }
        return flag;
    }
    
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> pref(n+1, 0);
        for (int i = 1; i < pref.size(); ++i)
            pref[i] = pref[i-1] + abs((s[i-1] - 'a') - (t[i-1] - 'a'));
        int l = 0, h = s.size()+1, ans = 0, mid;
        while (l <= h){
            mid = l + ((h - l) >> 1);
            if (check(pref, maxCost, mid)){
                ans = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        
        return ans;
    }
};