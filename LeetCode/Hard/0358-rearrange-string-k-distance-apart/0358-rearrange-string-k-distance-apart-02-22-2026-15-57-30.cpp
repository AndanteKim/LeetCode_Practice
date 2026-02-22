class Solution {
public:
    string rearrangeString(string s, int k) {
        vector<int> freqs(26);

        // Store the frequencies
        for (int i = 0; i < s.size(); ++i) {
            ++freqs[s[i] - 'a'];
        }

        priority_queue<pair<int, int>> free;

        // Insert the characters with their frequencies
        for (int i = 0; i < 26; ++i) {
            if (freqs[i]) free.push({freqs[i], i});
        }

        // This queue stores the unavailable characters
        queue<pair<int, int>> busy;
        string ans = "";
        while (ans.size() != s.size()) {
            int idx = ans.size();

            if (!busy.empty() && ((idx - busy.front().first) >= k)) {
                auto [_, ch] = busy.front(); busy.pop();
                free.push({freqs[ch], ch});
            }

            // If there's no free, we cannot rearrange the string
            if (free.empty()) return "";

            auto [_, currCh] = free.top(); free.pop();
            ans += currCh + 'a';
            
            // Insert the used character into busy queue with the current index
            --freqs[currCh];

            if (freqs[currCh] > 0) busy.push({idx, currCh});
        }

        return ans;
    }
};