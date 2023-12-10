class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), i = 0;
        
        while (i < n && citations[n - 1 - i] > i)
            ++i;
        return i;
    }
};