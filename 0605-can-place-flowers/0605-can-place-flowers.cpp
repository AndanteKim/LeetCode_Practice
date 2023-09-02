class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        
        for (int i = 0; i < flowerbed.size(); ++i){
            if (!flowerbed[i]){
                bool emptyLeftPlot = (i == 0) || !flowerbed[i - 1];
                bool emptyRightPlot = (i == flowerbed.size() - 1) || !flowerbed[i + 1];
                if (emptyLeftPlot && emptyRightPlot){
                    flowerbed[i] = 1;
                    ++count;
                }
            }
        }
        return count >= n;
    }
};