class Solution {
public:
    string predictPartyVictory(string senate) {
        // Two queues
        int n = senate.size();
        queue<int> rQueue, dQueue;
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') rQueue.push(i);
            else dQueue.push(i);
        }
        
        while (!rQueue.empty() && !dQueue.empty()){
            int rTurn = rQueue.front(), dTurn = dQueue.front();
            rQueue.pop();
            dQueue.pop();
            if (rTurn < dTurn) rQueue.push(rTurn + n);
            else dQueue.push(dTurn + n);
        }
        
        return !rQueue.empty()? "Radiant" : "Dire";
    }
};