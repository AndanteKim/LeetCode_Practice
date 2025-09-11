class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<char>> minHeap;
        string vowels = "aeiouAEIOU";

        for (const char& c:s)
            if (vowels.find(c) != string::npos) minHeap.push(c);
        
        int n = s.size();
        for (int i = 0; i < n; ++i){
            if (vowels.find(s[i]) != string::npos) {
                s[i] = minHeap.top();
                minHeap.pop();
            }
        }
        
        return s;
    }
};