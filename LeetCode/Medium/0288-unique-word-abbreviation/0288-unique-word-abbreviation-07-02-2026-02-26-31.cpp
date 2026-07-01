class ValidWordAbbr {
private:
    vector<string> dict;

public:
    ValidWordAbbr(vector<string>& dictionary) {
        dict = dictionary;
    }
    
    bool isUnique(string word) {
        int n = word.size();

        for (const string& s : dict) {
            if (s == word) continue;
            
            int m = s.size();

            if (m == n && s[0] == word[0] && s.back() == word.back()) return false;
        }

        return true;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */