class Solution {
private:
    int n;
    int expand(int left, int right, string& s){
        while (left >= 0 && right < n && s[left] == s[right]){
            --left;
            ++right;
        }
        
        return right - left - 1;
    }
    
public:
    string longestPalindrome(string s) {
        this -> n = s.size();
        pair<int, int> ans;
        
        for (int i = 0; i < n; ++i){
            int oddLength = expand(i, i, s);
            if (oddLength > ans.second - ans.first + 1){
                int dist = oddLength >> 1;
                ans.first = i - dist, ans.second = i + dist;
            }
            
            int evenLength = expand(i, i + 1, s);
            if (evenLength > ans.second - ans.first + 1){
                int dist = (evenLength >> 1) - 1;
                ans.first = i - dist, ans.second = i + dist + 1;
            }
        }
        
        return s.substr(ans.first, ans.second - ans.first + 1);
    }
};