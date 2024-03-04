class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
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
        
        # Stack for DFS. It'll store (person, time of knowing the secret)
        stack = [(0, 0), (firstPerson, 0)]
        
        # Do DFS
        while stack:
            person, time = stack.pop()
            for t, next_person in graph[person]:
                if t >= time and earliest[next_person] > t:
                    earliest[next_person] = t
                    stack.append((next_person, t))
                    
        # Since we visited only those people who know the secret
        # we need to return indices of all visited people
        return [i for i in range(n) if earliest[i] != float('inf')]