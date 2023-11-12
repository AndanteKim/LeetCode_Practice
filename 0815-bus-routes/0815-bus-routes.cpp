class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;
        
        unordered_map<int, vector<int>> adjList;
        // Create a map from the bus stop to all the route that include this stop
        for (int route = 0; route < routes.size(); ++route){
            for (int stop : routes[route])
                adjList[stop].push_back(route);
        }
        
        queue<int> queue;
        unordered_set<int> visited;
        // Insert all the routes in the queue having the source stop
        for (int route : adjList[source]){
            queue.push(route);
            visited.insert(route);
        }
        
        int busCount = 1;
        
        while (!queue.empty()){
            int size = queue.size();
            
            for (int i = 0; i < size; ++i){
                int currRoute = queue.front();
                queue.pop();
                // Iterate over the stops in the current route
                for (int stop : routes[currRoute]){
                    // return the current count if the target is found
                    if (stop == target)
                        return busCount;
                    
                    // Iterate over the next possible routes from the current stop
                    for (int nextRoute : adjList[stop]){
                        if (visited.count(nextRoute) == 0){
                            visited.insert(nextRoute);
                            queue.push(nextRoute);
                        }
                    }
                }
            }
            ++busCount;
        }
        
        return -1;
    }
};