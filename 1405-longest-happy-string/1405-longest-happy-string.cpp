class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Maximum total iterations possible is given by the sum of a, b, and c.
        int totalIteration = a + b + c, currA = 0, currB = 0, currC = 0;
        string ans = "";
        
        for (int i = 0; i < totalIteration; ++i){
            // If 'a' is the maximum and its streak is less than 2, or if streak of 'b' or 'c' is 2, then 'a' will be
            // the next character.
            if ((a >= max(b, c) && currA < 2) || (a > 0 && (currB == 2 || currC == 2))){
                ans.push_back('a');
                --a;
                ++currA;
                currB = 0, currC = 0;
            }
            // If 'b' is the maximum and its streak is less than 2, or if streak of 'a' or 'c' is 2, then 'b' will be
            // the next character.
            else if ((b >= max(a, c) && currB < 2) || (b > 0 && (currA == 2 || currC == 2))){
                ans.push_back('b');
                --b;
                ++currB;
                currA = 0, currC = 0;
            }
            
            // If 'c' is the maximum and its streak is less than 2, or if streak of 'a' or 'b' is 2, then 'c' will be
            // the next character.
            else if ((c >= max(a, b) && currC < 2) || (c > 0 && (currA == 2 || currB == 2))){
                ans.push_back('c');
                --c;
                ++currC;
                currA = 0, currB = 0;
            }
        }
        
        return ans;
    }
};