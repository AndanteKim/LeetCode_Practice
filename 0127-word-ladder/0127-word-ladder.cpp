class Solution {
    int length = 0;
    unordered_map<string, vector<string>> allComboDict;
    
    int visitWordNode(queue<string>& q, unordered_map<string, int>& visited, unordered_map\
                     <string, int>& otherVisited){
        int qSize = q.size();
        for (int _ = 0; _ < qSize; ++_){
            string currentWord = q.front();
            q.pop();
            for (int i = 0; i < length; ++i){
                string newWord = currentWord.substr(0, i) + '*' + currentWord.substr(i+1);
                
                for (string& word : allComboDict[newWord]){
                    if (otherVisited.find(word) != otherVisited.end())
                        return visited[currentWord] + otherVisited[word];
                    if (visited.find(word) == visited.end()){
                        visited[word] = visited[currentWord] + 1;
                        q.push(word);
                    }
                }
            }
        }
        return NULL;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        length = beginWord.size();
        
        for (string& word : wordList){
            for (int i = 0; i < length; ++i)
                allComboDict[word.substr(0, i) + '*' + word.substr(i+1)].push_back(word);
        }
        
        queue<string> qBegin, qEnd;
        qBegin.push(beginWord);
        qEnd.push(endWord);
        
        unordered_map<string, int> visitedBegin{{beginWord, 1}}, visitedEnd{{endWord, 1}};
        int ans = 0;
        while (!qBegin.empty() && !qEnd.empty()){
            if (qBegin.size() <= qEnd.size()){
                ans = visitWordNode(qBegin, visitedBegin, visitedEnd);
            }
            else{
                ans = visitWordNode(qEnd, visitedEnd, visitedBegin);
            }
            
            if (ans != 0) return ans;
        }
        
        return ans;
    }
};