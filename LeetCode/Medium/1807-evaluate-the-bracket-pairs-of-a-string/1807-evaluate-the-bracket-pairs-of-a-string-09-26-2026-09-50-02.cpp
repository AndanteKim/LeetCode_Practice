class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (auto& kd: knowledge) dict[kd[0]] = kd[1];

        bool addKey = false;
        string key, ans;

        for (char c : s) {
            if (c == '(') addKey = true;
            else if (c == ')') {
                if (dict.count(key) > 0) ans += dict[key];
                else ans.push_back('?');
            
                addKey = false;
                key.clear();
            }
            else if (addKey) key.push_back(c);
            else ans.push_back(c);
        }

        return ans;
    }
};