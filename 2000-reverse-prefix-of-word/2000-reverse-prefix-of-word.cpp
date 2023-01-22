class Solution {
public:
    string reversePrefix(string word, char ch) {
        int location = word.find(ch), i = 0;
        while (i < location){
            swap(word[i++], word[location--]);
        }
        return word;
    }
};