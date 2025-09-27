class Node:
    def __init__(self, name: str, timestamp: int, website: str):
        self.name = name
        self.timestamp = timestamp
        self.website = website

class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        nodes = [
            Node(name, ts, site) for name, ts, site in zip(username, timestamp, website)
        ]

        nodes.sort(key = lambda x: x.timestamp)
        user_visits = defaultdict(list)
        for node in nodes:
            user_visits[node.name].append(node)
        
        route = defaultdict(int)
        for visits in user_visits.values():
            tmp = set()
            for i, j, k in combinations(range(len(visits)), 3):
                path = (visits[i].website, visits[j].website, visits[k].website)
                tmp.add(path)
            
            for path in tmp:
                route[path] += 1
        
        max_count, result = -1, tuple()
        for path, count in route.items():
            if count > max_count or (count == max_count and path < result):
                max_count, result = count, path
        
        return list(result)