class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = x ^ y, cnt = 0;
        
        while (dist > 0){
            cnt += dist & 1;
            dist >>= 1;
        }
        
        return cnt;
    }
};