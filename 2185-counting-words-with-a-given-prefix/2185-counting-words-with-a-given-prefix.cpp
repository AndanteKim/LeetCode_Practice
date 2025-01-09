class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        for (const string& word : words){
            if (word.find(pref) == 0)
                ++count;    // Found a string with pref as prefix
        }

        return count;
    }
};