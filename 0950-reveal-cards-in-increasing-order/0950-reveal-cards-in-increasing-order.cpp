class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        queue<int> q;
        
        // create queue of indices
        for (int i = 0; i < N; ++i) q.push(i);
        
        sort(deck.begin(), deck.end());
        vector<int> ans(N, 0);
        
        // Put cards at correct index in ans 
        for (int card:deck){
            // Reveal card
            ans[q.front()] = card;
            q.pop();
                            
            // Move next card to bottom
            if (!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        
        return ans;
    }
};