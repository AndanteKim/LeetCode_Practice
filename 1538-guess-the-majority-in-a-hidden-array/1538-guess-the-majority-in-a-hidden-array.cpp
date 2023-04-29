/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
    int cntEqual = 1, cntDiffer = 0, indexDiffer = -1;
    void f(bool equal, int i){
        if (equal) ++cntEqual;
        else{
            ++cntDiffer;
            indexDiffer = i;
        }
    }
    
public:
    int guessMajority(ArrayReader &reader) {
        int n = reader.length();
        int query0123 = reader.query(0, 1, 2, 3);
        int query1234 = reader.query(1, 2, 3, 4);
        f(reader.query(1, 2, 3, 4) == query0123, 4);
        
        for (int i = 5; i < n; ++i) f(reader.query(1, 2, 3, i) == query0123, i);
        f(reader.query(0, 2, 3, 4) == query1234, 1);
        f(reader.query(0, 1, 3, 4) == query1234, 2);
        f(reader.query(0, 1, 2, 4) == query1234, 3);
        
        return cntEqual > cntDiffer? 0 : (cntDiffer > cntEqual)? indexDiffer : -1;
    }
};