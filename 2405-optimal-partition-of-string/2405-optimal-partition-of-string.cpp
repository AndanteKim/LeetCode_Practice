class Solution {
public:
    int partitionString(string s) {
        int partitions = 1, charsBitmask = 0;
        
        for (char& c : s){
            int setBit = 1 << (c - 'a');
            if (charsBitmask & setBit){
                ++partitions;
                charsBitmask = 0;
            }
            charsBitmask |= setBit;
        }
        
        return partitions;
    }
};