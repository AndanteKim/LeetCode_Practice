class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort pairs in ascending order based on the second element.
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){return a[1] < b[1];});
        int ans = 0, curr = INT_MIN;
        
        for (const vector<int>& p : pairs){
            if (curr < p[0]){
                ++ans;
                curr = p[1];
            }
        }
        
        return ans;
    }
};