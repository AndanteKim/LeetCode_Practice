class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";
        
        // dictionary keeping a count of all the unique characters in t.
        unordered_map<char, int> dictT;
        for (char& c:t)
            ++dictT[c];
        
        // number of unique chars in t, nothing to be present in the desired window
        // Formed is used to keep track of how many unique characters in t are present in the current window
        // in its desired frequency e.g. if t is "AABC", then the window must have two A's, one B and one C. Thus, formed would be = 3
        // when all these conditions are met.
        int formed = 0, required = dictT.size();
        
        // Dictionary keeping a count of all the unique characters in the current window
        unordered_map<char, int> countT;
        // ans is array of the form {window length, left, right}
        int ans[3], left = 0;
        ans[0] = INT_MAX;
        
        // Keep expanding the window once we're dong contracting.
        for (int right = 0; right < s.size(); ++right){
            
            // Add one character from the right to the window
            char c = s[right];
            ++countT[c];
            
            // If the frequency of the current character added equals to the desired count in t, then increment the formed count by 1.
            if (dictT.count(c) && countT[c] == dictT[c])
                ++formed;
            
            // Try and contract the window till the point where it ceases to be 'desirable'.
            while (left <= right && formed == required){
                
                // save the smallest window until now.
                if (right - left + 1 < ans[0]){
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }
                
                // The character at the position pointed by the 'left' pointer is no longer a part of the window.
                --countT[s[left]];
                if (countT[s[left]] < dictT[s[left]])
                    --formed;
                
                // move the left pointer ahead, this would be help to look for a new window.
                ++left;
            }
        }
        return ans[0] == INT_MAX? "":s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};