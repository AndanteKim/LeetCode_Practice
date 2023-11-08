class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int width = abs(fx - sx), height = abs(fy - sy);
        
        if (width == 0 && height == 0 && t == 1)
            return false;
        // Chebyshev Distance
        return t >= max(width, height);
    }
};