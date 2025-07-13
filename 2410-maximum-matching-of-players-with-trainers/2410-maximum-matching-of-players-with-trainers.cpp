class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int ans = 0;

        for (int trainer : trainers) minHeap.push(trainer);

        for (int player : players){
            while (!minHeap.empty()){
                int capacity = minHeap.top(); minHeap.pop();
                if (capacity >= player){
                    ++ans;
                    break;
                }
            }
        }

        return ans;  
    }
};