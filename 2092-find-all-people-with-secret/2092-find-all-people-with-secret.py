class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        # For every person, store the time and laberl of the person met.
        graph = defaultdict(list)
        
        for x, y, t in meetings:
            graph[x].append((t, y))
            graph[y].append((t, x))
            
        # Priority Queue for BFS. It stores (time secret learned, person)
        # It pops the person with the minimum time of knowing the secret.
        pq = []
        heappush(pq, (0, 0))
        heappush(pq, (0, firstPerson))
        
        # Visited arraay to mark if a person is visited or not.
        # We'll mark a person as visited after it's dequeued
        # from the queue.
        visited = [False] * n
        
        # Do BFS, but pop minimum
        while pq:
            time, person = heappop(pq)
            if visited[person]:
                continue
            
            visited[person] = True
            
            for t, next_person in graph[person]:
                if not visited[next_person] and t >= time:
                    heappush(pq, (t, next_person))
        
        # Since we visited only those people who know the secret
        # we need to return indices of all visited people
        return [i for i in range(n) if visited[i]]