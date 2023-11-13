class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> vowels{{'A',0}, {'E',0}, {'I',0}, {'O', 0}, {'U',0},\
                                        {'a',0}, {'e',0}, {'i',0}, {'o',0}, {'u',0}};
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> minHeap;
        for (char& c : s){
            if (vowels.count(c))
                ++vowels[c];
        }
        for (auto&[ch, val] : vowels){
            if (val > 0)
                minHeap.push({ch, val});
        }
        
        string ans = "";
        for (char& c : s){
            if (vowels.count(c)){
                auto[vowel, freq] = minHeap.top();
                --freq;
                minHeap.pop();
                ans.push_back(vowel);
                if (freq > 0) minHeap.push({vowel, freq});
            }
            else
                ans.push_back(c);
        }
        
        return ans;
    }
};