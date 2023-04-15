class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
        int length = beginWord.size();
        unordered_map<string, vector<string>> allComboList;
        for (string& word : wordList){
            for (int i = 0; i < word.size(); ++i) allComboList[word.substr(0, i) + '*' + word.substr(i + 1)].\
                push_back(word);
        }
        
        queue<pair<string, int>> queue;
        queue.push({beginWord, 1});
        unordered_set<string> seen;
        seen.insert(beginWord);
        
        while (!queue.empty()){
            auto [currWord, steps] = queue.front();
            queue.pop();
            
            for (int i = 0; i < length; ++i){
                string newWord = currWord.substr(0, i) + '*' + currWord.substr(i + 1);
                for (string& word : allComboList[newWord]){
                    if (word == endWord) return steps + 1;
                    if (seen.find(word) == seen.end()){
                        seen.insert(word);
                        queue.push({word, steps + 1});
                    }
                }
                allComboList[newWord].clear();
            }
        }
        return 0;
    }
};