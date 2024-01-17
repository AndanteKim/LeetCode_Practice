class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int ans = 0, prev = 0;
        unordered_map<char, int> keyboardIdx;
        
        for (int i = 0; i < keyboard.size(); ++i)
            keyboardIdx[keyboard[i]] = i;
        
        for (char& c:word){
            ans += abs(keyboardIdx[c] - prev);
            prev = keyboardIdx[c];
        }
        
        return ans;
    }
};