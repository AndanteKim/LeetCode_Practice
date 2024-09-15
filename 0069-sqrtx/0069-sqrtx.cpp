class Solution {
public:
    int mySqrt(int x) {
        // Binary search
        if (x < 2)
            return x;
        
        int left = 0, right = x;
        
        while (left <= right){
            int mid = (left + right) >> 1;
            
            if ((long)mid * mid > x)
                right = mid - 1;
            else if ((long)mid * mid < x)
                left = mid + 1;
            else
                return mid;
        }
        
        return right;
    }
};