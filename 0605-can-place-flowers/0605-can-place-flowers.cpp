class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, lastOne = -1;
        
        for (int i = 0; i < flowerbed.size(); ++i){
            if (!flowerbed[i]) ++count;
            else{
                n -= (count - (lastOne != -1)) / 2;
                count = 0;
                lastOne = i;
            }
        }
        n -= (count + (lastOne == -1)) / 2;
        
        return n <= 0;
    }
};