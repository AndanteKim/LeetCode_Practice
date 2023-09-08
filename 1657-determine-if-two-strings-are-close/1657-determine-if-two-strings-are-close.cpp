class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count1(26), count2(26);
        for (const char& c : word1) ++count1[c - 'a'];
        for (const char& c : word2) {
            if (!count1[c - 'a']) return false;
            ++count2[c - 'a'];
        }
        
        sort(count1.begin(), count1.end(), greater<int>());
        sort(count2.begin(), count2.end(), greater<int>());
        for (int i = 0; i < 26; ++i){
            if (count1[i] != count2[i]) return false;
        }
        return true;
    }
};