class Solution {
private:
    void count(vector<int>& ans, const string& word){
        for (const char& c : word){
            ++ans[c - 'a'];
        }
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> w2MaxFreq(26, 0);
        for (const string& w2 : words2){
            vector<int> w2Freq(26, 0);
            count(w2Freq, w2);
            for (int i = 0; i < 26; ++i)
                w2MaxFreq[i] = max(w2MaxFreq[i], w2Freq[i]);
        }

        vector<string> ans;
        for (const string& w1 : words1) {
            bool available = true;
            vector<int> w1Freq(26, 0);
            count(w1Freq, w1);
            for (int i = 0; i < 26; ++i){
                if (w1Freq[i] < w2MaxFreq[i]){
                    available = false;
                    break;
                }
            }
            if (available) ans.push_back(w1);
        }
        return ans;
    }
};