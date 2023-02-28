class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        queue = deque()
        people, bans = [0, 0], [0, 0]
        
        for person in senate:
            x = person == "R"
            people[x] += 1
            queue.append(x)
        
        while all(people):
            x = queue.popleft()
            people[x] -= 1
            if bans[x]:
                bans[x] -= 1
            else:
                bans[x ^ 1] += 1
                queue.append(x)
                people[x] += 1
        
        return "Radiant" if people[1] else "Dire"
            
        
        