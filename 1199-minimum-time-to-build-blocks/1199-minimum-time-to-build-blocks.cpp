class Solution {
private:
    bool possible(int limit, vector<int>& blocks, int split){
        int worker = 1;
        
        for (int i = 0; i < blocks.size(); ++i){
            int time = blocks[i];
            // If no worker or no sufficient time
            if (worker <= 0 || time > limit) return false;
            
            // keep splitting and producing workers as long as
            // we are within the limit for this block
            while (time + split <= limit){
                limit -= split;
                worker <<= 1;
                
                // sufficient worker for remaining block
                if (worker >= blocks.size() - 1) return true;
            }
            --worker;
        }
        // all blocks are built
        return true;
    }
    
public:
    int minBuildTime(vector<int>& blocks, int split) {
        
        // sort in descending order
        sort(blocks.begin(), blocks.end(), greater<int>());
        
        // binary search algorithm
        int left = blocks[0], right = split * (ceil(log2(blocks.size()))) + blocks[0];
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (possible(mid, blocks, split)) right = mid;
            else left = mid + 1;
        }
        
        return right;
    }
};