class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = *max_element(heights.begin(), heights.end());
        vector<int> countSort(n + 1);
        for (int height:heights) ++countSort[height];
        
        int curr = 1, ans = 0;
        for (int height : heights){
            while (countSort[curr] == 0) ++curr;
            
            if (height != curr) ++ans;
            --countSort[curr];
        }
        
        return ans;
    }
};