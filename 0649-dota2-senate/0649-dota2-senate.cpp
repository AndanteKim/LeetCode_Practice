class Solution {
public:
    string predictPartyVictory(string senate) {
        int rCount = count(senate.begin(), senate.end(), 'R');
        int dCount = senate.size() - rCount, rBan = 0, dBan = 0;
        
        queue<char> queue;
        for (char& c : senate) queue.push(c);
        
        while (rCount && dCount){
            int curr = queue.front();
            queue.pop();
            
            if (curr == 'D'){
                if (dBan){
                    --dBan;
                    --dCount;
                }
                else{
                    ++rBan;
                    queue.push(curr);
                }
            }
            else{
                if (rBan){
                    --rBan;
                    --rCount;
                }
                else{
                    ++dBan;
                    queue.push(curr);
                }
            }
        }
        
        return rCount? "Radiant" : "Dire";
    }
};