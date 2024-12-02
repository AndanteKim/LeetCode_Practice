class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        istringstream iss(sentence);
        string word;
        
        while (iss >> word){
            words.push_back(word);
        }
        
        int n = searchWord.size();
        for (int i = 0; i < words.size(); ++i){
            int j = 0, m = words[i].size();
            bool isPrefix = true;
            if (m < n) continue;
            
            while (j < n){
                if (searchWord[j] != words[i][j]){
                    isPrefix = false;
                    break;
                }
                ++j;
            }
            
            if (isPrefix) return i + 1;
        }
        
        return -1;
    }
};