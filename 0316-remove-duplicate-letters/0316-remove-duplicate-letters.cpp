class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        unordered_set<char> seen;
        unordered_map<char, int> lastOccurrence;
        for (int i = 0; i < s.size(); ++i)
            lastOccurrence[s[i]] = i;
        
        for (int i = 0; i < s.size(); ++i){
            if (seen.find(s[i]) == seen.end()){
                // If the last letter in our solution,
                // 1. exists, 2. > s[i], so removing it will make the string smaller, 3. It's not the last occurrence
                while (!ans.empty() && s[i] < ans.back() && i < lastOccurrence[ans.back()]){
                    seen.erase(ans.back());
                    ans.pop_back();
                }
                seen.insert(s[i]);
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};