class Solution {
public:
    string clearStars(string s) {
        vector cnt(26, vector<int>{});
        string ans = "";

        for (int i = 0; i < s.size(); ++i){
            if (s[i] != '*'){
                cnt[s[i] - 97].push_back(i);
            }
            else{
                for (int j = 0; j < 26; ++j){
                    if (!cnt[j].empty()){
                        s[cnt[j].back()] = '*';
                        cnt[j].pop_back();
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < s.size(); ++i){
            if (s[i] != '*') ans.push_back(s[i]);
        }

        return ans;
    }
};