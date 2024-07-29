class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n, teams = len(rating), 0
        
        # Tables for increasing and decreasing sequences
        inc_teams, dec_teams = [[0] * 4 for _ in range(n)], [[0] * 4 for _ in range(n)]
        for i in range(n):
            inc_teams[i][1] = 1
            dec_teams[i][1] = 1
        
        # Fill the tables
        for count in range(2, 4):
            for i in range(n):
                for j in range(i + 1, n):
                    # Increasing
                    if rating[j] > rating[i]:
                        inc_teams[j][count] += inc_teams[i][count - 1]
                    
                    # Decreasing
                    if rating[j] < rating[i]:
                        dec_teams[j][count] += dec_teams[i][count - 1]
        
        # Sum up the results (All sequences of length 3)
        for i in range(n):
            teams += inc_teams[i][3] + dec_teams[i][3]
            
        return teams