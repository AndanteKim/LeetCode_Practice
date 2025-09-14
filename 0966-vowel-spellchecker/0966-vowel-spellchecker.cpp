class Solution {
private:
    string devowel(const string& word){
        string newWord = "", vowels = "aeiou";
        for (const char& c : word){
            if (vowels.find(c) != string::npos) newWord.push_back('*');
            else newWord.push_back(c);
        }
        return newWord;
    }

    string lowerCase(const string& word){
        string lowerWord = "";
        for (int i = 0; i < word.size(); ++i) lowerWord.push_back(tolower(word[i]));
        return lowerWord;
    }

    string solve(const string& query, vector<string>& wordList, unordered_set<string>& wordPerfect, unordered_map<string, string>& wordCaps, unordered_map<string, string>& wordVows){
        if (wordPerfect.find(query) != wordPerfect.end()) return query;
        
        string queryLower = lowerCase(query);
        if (wordCaps.find(queryLower) != wordCaps.end()) return wordCaps[queryLower];
        string queryLV = devowel(queryLower);
        if (wordVows.find(queryLV) != wordVows.end()) return wordVows[queryLV];

        return "";
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> wordPerfect(wordlist.begin(), wordlist.end());
        unordered_map<string, string> wordCaps, wordVows;
        
        for (const string& word : wordlist){
            string wordLower = lowerCase(word);
            if (wordCaps.find(wordLower) == wordCaps.end()) wordCaps[wordLower] = word;
            if (wordVows.find(devowel(wordLower)) == wordVows.end()) wordVows[devowel(wordLower)] = word;
        }

        vector<string> ans;
        for (const string& query : queries)
            ans.push_back(solve(query, wordlist, wordPerfect, wordCaps, wordVows));
        
        return ans;
    }
};