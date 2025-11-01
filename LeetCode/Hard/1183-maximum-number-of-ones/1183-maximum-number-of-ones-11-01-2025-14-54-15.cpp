class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int ans = maxOnes * ((height / sideLength) * (width / sideLength)), remain = maxOnes;
        
        int cnt1 = min(remain, (width % sideLength) * (height % sideLength));
        ans += ((width / sideLength) + (height / sideLength) + 1) * cnt1;
        remain -= cnt1;

        if ((height / sideLength) > (width / sideLength)) {
            int cnt2 = min(remain, ((width % sideLength) * sideLength) - ((width % sideLength) * (height % sideLength)));
            ans += (height / sideLength) * cnt2;
            remain -= cnt2;

            int cnt3 = min(remain, ((height % sideLength) * sideLength) - ((width % sideLength) * (height % sideLength)));
            ans += (width / sideLength) * cnt3;
            remain -= cnt3;
        }
        else {
            int cnt2 = min(remain, ((height % sideLength) * sideLength) - ((width % sideLength) * (height % sideLength)));
            ans += (width / sideLength) * cnt2;
            remain -= cnt2;

            int cnt3 = min(remain, ((width % sideLength) * sideLength) - ((width % sideLength) * (height % sideLength)));
            ans += (height / sideLength) * cnt3;
            remain -= cnt3;
        }
    
        return ans;
    }
};