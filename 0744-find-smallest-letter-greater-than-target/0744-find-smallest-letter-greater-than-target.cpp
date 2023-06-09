class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> alphabets(26, 0);
        char ans = letters[0];
        for (char& letter : letters) ++alphabets[letter - 'a'];
        
        for (int i = target - 'a' + 1; i < 26; ++i){
            if (alphabets[i]) return (char) (i + 'a');
        }
        
        return ans;
    }
};