class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int curPlantTime = 0, ans = 0;
        vector<int> indices(plantTime.size(), 0);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int x_1, int x_2){return growTime[x_1] > growTime[x_2];});
        
        for (int index: indices){
            curPlantTime += plantTime[index];
            ans = max(ans, curPlantTime + growTime[index]);
        }
        
        return ans;
    }
};