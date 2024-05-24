class Solution {
private:
    int n;
    
    int backtrack(int i, unordered_map<char, int>& remain, vector<string>& words, vector<int>& score){
        if (i == n)
            return 0;
        
        int totalScore = 0;
        bool used = true;
        unordered_map<char, int> word;
        for (char& c:words[i]) ++word[c];
        
        for (auto& [c, freq] : word)
            if (freq > remain[c]){
                used = false;
                break;
            }
        
        if (used){
            for (auto& [c, freq] : word){
                remain[c] -= freq;
                totalScore += freq * score[c - 97];
            }
            totalScore += backtrack(i + 1, remain, words, score);
            
            for (auto& [c, freq] : word)
                remain[c] += freq;
            
            totalScore = max(totalScore, backtrack(i + 1, remain, words, score));
        }
        else
            totalScore = backtrack(i + 1, remain, words, score);
            
        return totalScore;
    }
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        this -> n = words.size();
        unordered_map<char, int> remain;
        for (char& letter : letters)
            ++remain[letter];
        
        return backtrack(0, remain, words, score);
    }
};