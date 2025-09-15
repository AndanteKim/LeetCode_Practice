class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> unavailable;

        for (const char& c : brokenLetters) unavailable.insert(c);

        vector<string> words;
        istringstream ss(text);
        string w;

        while (ss >> w) words.push_back(w);

        int ans = 0;
        for (const string& word : words){
            bool available = true;
            for (const char& c : word){
                if (unavailable.find(c) != unavailable.end()) {
                    available = false;
                    break;
                }
            }

            if (available) ++ans;
        }
        
        return ans;
    }
};