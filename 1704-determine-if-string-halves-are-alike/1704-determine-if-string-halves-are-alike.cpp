class Solution {
private:
    int countVowels(int start, int end, string& s){
        string vowels = "aeiouAEIOU";
        int ans = 0;
        
        for (int i = start; i < end; ++i){
            if (vowels.find(s[i]) != string::npos)
                ++ans;
        }
        
        return ans;
    }
    
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        return countVowels(0, n / 2, s) == countVowels(n / 2, n, s);
    }
};