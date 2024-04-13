class Solution {
private:
    int n, k, wordLength, substrSize;
    unordered_map<string, int> wordsCount;
    bool check(int i, string& s){
        int wordsUsed = 0;
        // copy the original map to use for this index
        unordered_map<string, int> remaining = wordsCount;
        
        string sub;
        // Each iteration will check for a match in words
        for (int j = i; j < n; j += wordLength){
            sub = s.substr(j, wordLength);
            if (remaining[sub] > 0) {
                --remaining[sub];
                ++wordsUsed;
            }
            else break;
        }
        
        // Valid if we used all the words
        return wordsUsed == k;
    }
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       
        this -> n = s.size(), this -> k = words.size(), this -> wordLength = words[0].size(), this -> substrSize = wordLength * k;
        for (int i = 0; i < k; ++i) ++wordsCount[words[i]];
        
        vector<int> ans;
        for (int i = 0; i <= n - substrSize; ++i){
            if (check(i, s)) ans.push_back(i); 
        }
        
        return ans;
    }
};