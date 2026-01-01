class Leaderboard {
private:
    map<int, int> scores;

public:
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        scores[playerId] += score;
    }
    
    int top(int K) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (const auto& [id, score] : scores) {
            minHeap.push(score);

            if (minHeap.size() > K) minHeap.pop();
        }

        int ans = 0;
        while (!minHeap.empty()) {
            ans += minHeap.top(); minHeap.pop();
        }
        return ans;
    }
    
    void reset(int playerId) {
        scores[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */