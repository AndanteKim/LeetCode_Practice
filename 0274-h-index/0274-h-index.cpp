class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> papers(n + 1);
        
        for (int citation : citations)
            ++papers[min(citation, n)];
        
        int k = n;
        for (int s = papers[n]; k > s; s += papers[k]){
            --k;
        }
        
        return k;
    }
};