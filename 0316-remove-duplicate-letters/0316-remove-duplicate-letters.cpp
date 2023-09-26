class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        // find pos - the index of the leftmost letter in our solution
        // we create a counter and end the iteration once the suffix doesn't have each unique
        // character pos will be the index of the smallest character we encounter before the iteration ends
        unordered_map<char, int> m;
        for (char& c : s)
            ++m[c];
        
        int pos = 0;
        
        for (int i = 0; i < s.size(); ++i){
            if (s[i] < s[pos]) pos = i;
            --m[s[i]];
            if (m[s[i]] == 0)
                break;
        }
        
        // Our answer is the leftmost letter plus the recursive call on the remainder of the string
        // note we have to get rid of further occurrences of s[pos] to ensure that there are no duplicates
        string newS = s.substr(pos);
        newS.erase(remove(newS.begin(), newS.end(), s[pos]), newS.end());
        return !s.empty()? s[pos] + removeDuplicateLetters(newS) : "";
    }
};