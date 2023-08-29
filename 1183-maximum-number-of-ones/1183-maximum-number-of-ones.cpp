class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> count;
        for (int r = 0; r < sideLength; ++r){
            for (int c = 0; c < sideLength; ++c){
                int num = (1 + (width - c - 1) / sideLength) * (1 + (height - r - 1) / sideLength);
                count.push_back(num);
            }
        }
        
        sort(count.begin(), count.end(), [](int a, int b) {return a > b;});
        
        return accumulate(count.begin(), count.begin() + maxOnes, 0);
    }
};