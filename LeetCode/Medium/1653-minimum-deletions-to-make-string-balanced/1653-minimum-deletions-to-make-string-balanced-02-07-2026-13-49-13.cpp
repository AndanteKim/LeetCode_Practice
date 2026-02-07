class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> aCnt(n), bCnt(n);
        aCnt.back() = (s[n - 1] == 'a')? 1 : 0;
        bCnt[0] = (s[0] == 'b')? 1 : 0;

        for (int i = 1; i < n; ++i){
            if (s[i]== 'b'){
                bCnt[i] = bCnt[i - 1] + 1;
            }
            else
                bCnt[i] = bCnt[i - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == 'a') {
                aCnt[i] = aCnt[i + 1] + 1;
            }
            else
                aCnt[i] = aCnt[i + 1];
        }

        int ans = min(aCnt[0], bCnt[n - 1]);

        for (int i = 0; i < n - 1; ++i) {
            ans = min(ans, aCnt[i + 1] + bCnt[i]);
        }

        return ans;
    }
};