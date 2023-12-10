class Solution {
public:
    int hIndex(vector<int>& citations) {
        int highest = *max_element(citations.begin(), citations.end());
        vector<int> counting(highest + 1);
        
        for (int citation : citations){
            for (int i = 0; i <= citation; ++i)
                ++counting[i];
        }
        
        for (int i = highest; i >= 0; --i)
            if(counting[i] >= i)
                return i;
        return 0;
    }
};