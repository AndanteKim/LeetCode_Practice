/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int left = 0, y = reader.length() - 1;
        
        while (left < y){
            int third = (y - left) / 3;
            int right = left + third, x = y - third;
            
            switch (reader.compareSub(left, right, x, y)){
                case 0:
                    left = right + 1;
                    y = x - 1;
                    break;
                case 1:
                    y = right;
                    break;
                case -1:
                    left = x;
                    break;
            }
        }
        
        return left;
    }
};