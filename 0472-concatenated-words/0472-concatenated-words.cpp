class Solution {
    struct trie{
        struct trie* arr[26];
        bool end = false;
        trie(){
            memset(arr, 0, sizeof(arr));
            end = false;
        }
    };
    
    trie* root;
    
    void insert(string &s){
        trie* node = root;
        
        for (int i = s.size()-1; i >= 0; --i){
            char ch = s[i];
            if (!node -> arr[ch - 'a']) node -> arr[ch - 'a'] = new trie();
            
            node = node -> arr[ch - 'a'];
        }
        node -> end = true;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &w1, string &w2) {return w1.size() < w2.size();});
        
        vector<string> ret;
        root = new trie();
        for (string w: words){
            if (w.size() == 0) continue;
            
            vector<bool> dp(w.size()+1);
            dp[0] = true;
            
            for (int i = 0; i < w.size(); ++i){
                trie *node = root;
                for (int j = i; j >= 0; --j){
                    if (node -> arr[w[j] - 'a'] == NULL) break;
                    node = node -> arr[w[j] - 'a'];
                    if (dp[j] && node -> end) {
                        dp[i+1] = true;
                        break;
                    }
                }
            }
            
            if (dp[w.size()]) ret.push_back(w);
            insert(w);
        }
        
        return ret;
    }
};