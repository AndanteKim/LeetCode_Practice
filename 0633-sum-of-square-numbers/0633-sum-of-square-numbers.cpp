class Solution {
private:
    bool binarySearch(int start, int end, int target){
        if (start > end) return false;
        
        int mid = start + ((end - start) >> 1);
        if ((long long)mid * mid == target) return true;
        
        if ((long long)mid * mid > target)
            return binarySearch(start, mid - 1, target);
        
        return binarySearch(mid + 1, end, target);
    }
    
public:
    bool judgeSquareSum(int c) {
        
        for (long long a = 0; a * a <= c; ++a){
            int b = c - (int)a * a;
            if (binarySearch(0, b, b))
                return true;
        }
        
        return false;
    }
};