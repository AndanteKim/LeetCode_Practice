class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        // Dictionary which keeps a count of all the unique characters in t.
        unordered_map<char, int> mappingT;
        for (char& c:t) ++mappingT[c];
        
        // map which keeps a count of all the unique characters in the current window
        unordered_map<char, int> windowsCount;
        // left and right pointer
        int l = 0, r = 0;
            
        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC", then the window must have two A's, one B and one C/
        // Thus formed would be = 3 when all these conditions are met.
        // Required := Number of unique characters in t, which need to be present in the
        // desired window.
        int formed = 0, required = mappingT.size();
        
        // ans list of the form (window length, left, right)
        vector<int> ans{INT_MAX, 0, 0};
        
        // Keep expanding the window once we're done contracting.
        for (r = 0; r < s.size(); ++r){
            // Add one characters from the right to the window
            char c = s[r];
            ++windowsCount[c];
            
            // If the frequency of the current character added equals to the
            // desired count in t, then increment the formed count by 1.
            if (mappingT.count(c) && windowsCount[c] == mappingT[c]) ++formed;
            
            // Try and contract the window till the point where it ceases to be
            // 'desirable'.
            while (l <= r && formed == required){
                // save the smallest window until now.
                if (r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1; ans[1] = l, ans[2] = r;
                }
                
                // The character at the position pointed by the 'left' pointer
                // is no longer a part of the window.
                // + Move the left pointer ahead, this would help to look for a new window.
                c = s[l++];
                --windowsCount[c];
                if (mappingT.count(c) && windowsCount[c] < mappingT[c]) --formed;
            }
        }
        return ans[0] == INT_MAX? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};