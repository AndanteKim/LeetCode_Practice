class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        
        if (s == goal){
            vector<int> freq(26);
            for (char& c : s){
                ++freq[c - 'a'];
                if (freq[c - 'a'] == 2) return true;
            }
            return false;
        }
        
        int firstIdx = -1, secondIdx = -1;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] != goal[i]){
                if (firstIdx == -1) firstIdx = i;
                else if (secondIdx == -1) secondIdx = i;
                else return false;
            }
        }
        if (secondIdx == -1) return false;
        return s[firstIdx] == goal[secondIdx] && s[secondIdx] == goal[firstIdx];
    }
};