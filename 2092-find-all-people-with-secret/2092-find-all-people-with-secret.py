class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        def dfs(person: int, time: int) -> None:
            for t, next_person in graph[person]:
                if t >= time and earliest[next_person] > t:
                    earliest[next_person] = t
                    dfs(next_person, t)
        
        # For every person, store the time and label of the person met.
        graph = defaultdict(list)
        for x, y, t in meetings:
            graph[x].append((t, y))
            graph[y].append((t, x))
            
        # Earliest time at which a person learnt the secret
        # as per current state of knowledge. If due to some new information,
        # the earliest time of knowing the secret changes, we'll update it
        # and again process all the people whom he/she meets after the time
        # at which he/she learnt the secret.
        earliest = [float('inf')] * n
        earliest[0], earliest[firstPerson] = 0, 0
        
        dfs(0, 0)
        dfs(firstPerson, 0)
            
        # Since we visited only those people who know the secret
        # we need to return indices of all visited people
        return [i for i in range(n) if earliest[i] != float('inf')]