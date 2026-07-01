class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> dict;

    string toAbbr(const string& s) {
        return s.size() <= 2? s : string(s[0] + to_string(s.size() - 2) + s.back());
    }

public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (const string& s : dictionary) {
            string abbr = toAbbr(s);
            dict[abbr].insert(s);
        }
    }
    
    bool isUnique(string word) {
        string abbr = toAbbr(word);

        return dict[abbr] == unordered_set<string>{} || (dict[abbr].contains(word) && dict[abbr].size() == 1);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */