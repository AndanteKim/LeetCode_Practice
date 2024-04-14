class Solution {
private:
    int n, k, wordLength, substrSize;
    unordered_map<string, int> wordCount;
    void slidingWindow(int left, string& s, vector<int>& ans){
        unordered_map<string, int> wordsFound;
        bool excessWord = false;
        int wordsUsed = 0;
        
        // Do the same iteration pattern as the previous approach iterate
        // wordLength at n time, and at each iteration we focus on one word
        for (int right = left; right < n; right += wordLength){
            if (right + wordLength > n) break;
            
            string sub = s.substr(right, wordLength);
            if (wordCount.find(sub) == wordCount.end()){
                // Mismatched word - reset the window
                wordsFound.clear();
                wordsUsed = 0, excessWord = false;
                left = right + wordLength; // Retry at the next index
            }
            else{
                // If we reached max window size or have an excess word
                while (right - left == substrSize || excessWord){
                    // Move the left bound over continuously
                    string leftmostWord = s.substr(left, wordLength);
                    left += wordLength;
                    --wordsFound[leftmostWord];
                    
                    if (wordsFound[leftmostWord] == wordCount[leftmostWord]){
                        // This word was the excess word
                        excessWord = false;
                    }
                    else{
                        // Otherwise we actually needed it.
                        --wordsUsed;
                    }
                }
                
                // keep track of how many times this word occurs in the window
                ++wordsFound[sub];
                if (wordsFound[sub] <= wordCount[sub]){
                    ++wordsUsed;
                }
                else{
                    // Found too many instances already
                    excessWord = true;
                }
                
                if (wordsUsed == k && !excessWord){
                    // Found a valid substring
                    ans.push_back(left);
                }
            }
        }
    }
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        this -> n = s.size(), this -> k = words.size();
        this -> wordLength = words[0].size(), this -> substrSize = k * wordLength;
        for (int i = 0; i < k; ++i) ++wordCount[words[i]];
        
        vector<int> ans;
        for (int i = 0; i < wordLength; ++i)
            slidingWindow(i, s, ans);
        
        return ans;
    }
};