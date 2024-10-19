class Solution {
public:
    char findKthBit(int n, int k) {
        string sequence = "0";
        
        // Generate the sequence until we've enough elements or reach nth iteration
        for (int i = 1; i < n && k > sequence.size(); ++i){
            sequence.push_back('1');
            
            // Append the inverted and reversed part of the existing sequence
            for (int j = sequence.size() - 2; j >= 0; --j)
                (sequence[j] == '0')? sequence.push_back('1') : sequence.push_back('0');
            
            
        }
        
        // Return the kth bit
        return sequence[k - 1];
    }
};