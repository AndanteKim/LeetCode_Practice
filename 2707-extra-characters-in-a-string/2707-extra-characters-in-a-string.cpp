class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        unordered_map<int, int> memo;
        
        function<int(int)> dp = [&](int start){
            if (start == n) return 0;
            if (memo.count(start)) return memo[start];
            
            // To count this character as a left over character
            // move to index 'start + 1'
            int ans = dp(start + 1) + 1;
            for (int end = start; end < n; ++end){
                string curr = s.substr(start, end - start + 1);
                if (dictSet.count(curr)) ans = min(ans, dp(end + 1));
            }
            
            return memo[start] = ans;
        };
        
        return dp(0);
    }
};