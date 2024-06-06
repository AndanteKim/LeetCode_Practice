class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int handSize = hand.size();
        if (handSize % groupSize != 0) return false;
        
        unordered_map<int, int> freq;
        for (int h:hand) ++freq[h];
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (auto& [k, _] : freq) minHeap.push(k);
        
        while (!minHeap.empty()){
            int curr = minHeap.top();
            
            
            for (int i = 0; i < groupSize; ++i){
                int next = curr + i;
                
                if (freq[next] == 0)
                    return false;
                --freq[next];
                
                if (freq[next] == 0){
                    if (next != minHeap.top())
                        return false;
                    minHeap.pop();
                }
            }
        }
        
        return true;
    }
};