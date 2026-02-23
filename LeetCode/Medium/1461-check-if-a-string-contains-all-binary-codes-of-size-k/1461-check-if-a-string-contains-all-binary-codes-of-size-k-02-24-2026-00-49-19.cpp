class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;
        
        unordered_set<string> ans;
        ans.insert(s.substr(0, k));
        deque<char> dq;
        for (int i = 0; i < k; ++i) dq.push_back(s[i]);

        int n = s.size();
        for (int i = k; i < n; ++i) {
            dq.pop_front();
            dq.push_back(s[i]);
            string curr = "";
            for (int _ = 0; _ < dq.size(); ++_) {
                char c = dq.front();
                dq.pop_front();
                curr.push_back(c);
                dq.push_back(c);
            }
            ans.insert(curr);
        }

        return ans.size() == (1 << k);
    }
};