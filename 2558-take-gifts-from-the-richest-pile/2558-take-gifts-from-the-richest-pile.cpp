class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;
        for (int gift : gifts) maxHeap.push(gift);
        
        for (int i = 0; i < k; ++i){
            if (!maxHeap.empty()){
                int first = maxHeap.top(); maxHeap.pop();
                maxHeap.push(sqrt(first));
            }
        }
        
        long long ans = 0;
        while (!maxHeap.empty()){
            ans += maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};