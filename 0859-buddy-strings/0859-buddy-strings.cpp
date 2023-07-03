class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (goal == s){
            unordered_set<char> l_s;
            for (char& c : s) l_s.insert(c);
            return l_s.size() < s.size();
        }
        
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < n && s[l] == goal[l]) ++l;
        while (r >= 0 && s[r] == goal[r]) --r;
        
        if (l < r){
            vector<char> l_s;
            for (char& c : s) l_s.push_back(c);
            swap(l_s[l], l_s[r]);
        
            string swap_s = "";
            for (char& c: l_s) swap_s += c;
            return swap_s == goal;
        }
        return s == goal;
    }
};