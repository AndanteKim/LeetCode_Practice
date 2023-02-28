class Solution {
    queue<int> *q;
public:
    string predictPartyVictory(string senate) {
        q = new queue<int>;
        vector<int> people(2, 0), bans(2, 0);
        
        for (const char& person : senate){
            int x = (person == 'R');
            ++people[x];
            q -> push(x);
        }
        
        while(people[0] > 0 && people[1] > 0){
            int x = q -> front();
            q -> pop();
            --people[x];
            
            if (bans[x]) --bans[x];
            else{
                ++bans[x ^ 1];
                ++people[x];
                q -> push(x);
            }
        }
        
        return people[1]? "Radiant" : "Dire";
    }
};