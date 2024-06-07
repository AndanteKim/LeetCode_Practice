class Solution {
private:
    string shortestRoot(string& word, unordered_set<string>& mapSet){
        string sub;
        
        for (int i = 0; i < word.size(); ++i){
            sub = word.substr(0, i);
            if (mapSet.find(sub) != mapSet.end())
                return sub;
        }
        
        return word;
    }
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> mapSet(dictionary.begin(), dictionary.end());
        vector<string> words;
        string s;
        stringstream ss(sentence);
        while (ss >> s)
            words.push_back(s);
        
        for (int word = 0; word < words.size(); ++word){
            words[word] = shortestRoot(words[word], mapSet);
        }
        
        string ans = "";
        for (string& word:words)
            ans += word + ' ';
        
        return ans.substr(0, ans.size() - 1);
    }
};