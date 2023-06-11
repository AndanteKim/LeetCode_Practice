class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> bloomStart, bloomEnd;
        for (vector<int>& flower : flowers){
            bloomStart.push_back(flower[0]);
            bloomEnd.push_back(flower[1]);
        }
        
        sort(bloomStart.begin(), bloomStart.end());
        sort(bloomEnd.begin(), bloomEnd.end());
        
        vector<int> ans(people.size(), 0);
        
        for (int i = 0; i < people.size(); ++i){
            int startIndex = upper_bound(bloomStart.begin(), bloomStart.end(), people[i]) - bloomStart.begin();
            int endIndex = lower_bound(bloomEnd.begin(), bloomEnd.end(), people[i]) - bloomEnd.begin();
            ans[i] = startIndex - endIndex;
        }
        
        return ans;
    }
};