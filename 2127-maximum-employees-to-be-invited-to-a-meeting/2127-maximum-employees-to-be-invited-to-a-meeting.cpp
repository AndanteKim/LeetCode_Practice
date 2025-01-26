class Solution {
private:
    int n;

    // Helper function for BFS
    int bfs(int startNode, unordered_set<int>& visitedNodes, vector<vector<int>>& reversedGraph){
        queue<pair<int, int>> q;
        q.push({startNode, 0});
        int maxDistance = 0;

        while (!q.empty()){
            auto [currPerson, currDistance] = q.front(); q.pop();
            for (int neighbor : reversedGraph[currPerson]){
                if (!visitedNodes.count(neighbor)){
                    visitedNodes.insert(neighbor);
                    q.push({neighbor, currDistance + 1});
                    maxDistance = max(maxDistance, currDistance + 1);
                }
            }
        }
        return maxDistance;
    }

public:
    int maximumInvitations(vector<int>& favorite) {
        this -> n = favorite.size();
        vector reversedGraph(n, vector<int>());
        
        for (int person = 0; person < n; ++person)
            reversedGraph[favorite[person]].push_back(person);

        int longestCycle = 0, twoCyclesInvitations = 0;
        vector<bool> visited(n, false);

        // Find all cycles
        for (int person = 0; person < n; ++person){
            if (!visited[person]){
                int currPerson = person, dist = 0;
                unordered_map<int, int> visitedPeople;
                while (true){
                    if (visited[currPerson])
                        break;
                    
                    visited[currPerson] = true;
                    visitedPeople[currPerson] = dist++;
                    int nextPerson = favorite[currPerson];

                    // Cycle detected
                    if (visitedPeople.count(nextPerson)){
                        int cycleLength = dist - visitedPeople[nextPerson];
                        longestCycle = max(longestCycle, cycleLength);
                        
                        // Handle cycles of length 2
                        if (cycleLength == 2){
                            unordered_set<int> visitedNodes{currPerson, nextPerson};
                            twoCyclesInvitations += 2 + bfs(nextPerson, visitedNodes, reversedGraph)\
                             + bfs(currPerson, visitedNodes, reversedGraph);
                        }
                        break;
                    }
                    currPerson = nextPerson;
                }
            }
        }

        return max(longestCycle, twoCyclesInvitations);
    }
};