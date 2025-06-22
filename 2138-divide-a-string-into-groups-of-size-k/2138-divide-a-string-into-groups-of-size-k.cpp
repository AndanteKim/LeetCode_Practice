class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;     // Grouped string
        int curr = 0, n = s.size(); // Starting index of each group
        
        // Split string
        while (curr < n){
            ans.push_back(s.substr(curr, k));
            curr += k;
        }

        // Try to fill in the last group
        ans.back() += string(k - ans.back().size(), fill);

        return ans;
    }
};