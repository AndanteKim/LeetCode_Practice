class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int m = height, n = width;
        int ans = maxOnes * (m / sideLength) * (n / sideLength), rest = maxOnes;
        
        int use1 = min((m % sideLength) * (n % sideLength), rest);
        ans += ((m / sideLength) + (n / sideLength) + 1) * use1;
        rest -= use1;
        if (m / sideLength > n / sideLength){
            int use2 = min((n % sideLength) * sideLength - (m % sideLength) * (n % sideLength), rest);
            ans += ((m / sideLength) * use2);
            rest -= use2;
            int use3 = min((m % sideLength) * sideLength - (m % sideLength) * (n % sideLength), rest);
            ans += ((n / sideLength) * use3);
            rest -= use3;
        }
        else{
            int use2 = min((m % sideLength) * sideLength - (m % sideLength) * (n % sideLength), rest);
            ans += ((n / sideLength) * use2);
            rest -= use2;
            int use3 = min((n % sideLength) * sideLength - (m % sideLength) * (n % sideLength), rest);
            ans += ((m / sideLength) * use3);
            rest -= use3;
        }
        
        return ans;
    }
};