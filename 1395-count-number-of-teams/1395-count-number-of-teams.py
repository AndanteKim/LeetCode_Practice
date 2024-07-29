class Solution:
    def numTeams(self, rating: List[int]) -> int:
        self.n, teams = len(rating), 0
        inc_cache = [[-1] * 4 for _ in range(self.n)]
        dec_cache = [[-1] * 4 for _ in range(self.n)]
        
        # Calculate total teams by considering each soldier as a starting point
        for start_idx in range(self.n):
            teams += self._cnt_inc_teams(rating, start_idx, 1, inc_cache) + self._cnt_dec_teams(rating, start_idx, 1, dec_cache)
            
        return teams
    
    def _cnt_inc_teams(self, rating: List[int], curr_idx: int, team_sz: int, inc_cache: List[List[int]]) -> int:
        # Base case: reached end of array
        if curr_idx == self.n:
            return 0
        
        # Base case: found a valid team of size 3
        if team_sz == 3:
            return 1
        
        # Return cached result if available
        if inc_cache[curr_idx][team_sz] != -1:
            return inc_cache[curr_idx][team_sz]
        
        valid_teams = 0
        
        # Recursively count teams with increasing ratings
        for nxt_idx in range(curr_idx + 1, self.n):
            if rating[nxt_idx] > rating[curr_idx]:
                valid_teams += self._cnt_inc_teams(rating, nxt_idx, team_sz + 1, inc_cache)
                
        # Cache and return the result
        inc_cache[curr_idx][team_sz] = valid_teams
        return valid_teams
    
    def _cnt_dec_teams(self, rating: List[int], curr_idx: int, team_sz: int, dec_cache: List[List[int]]) -> int:
        # Base case: reached end of array
        if curr_idx == self.n:
            return 0
        
        # Base case: found a valid team of size 3
        if team_sz == 3:
            return 1
        
        # Returned cached result if available
        if dec_cache[curr_idx][team_sz] != -1:
            return dec_cache[curr_idx][team_sz]
        
        valid_teams = 0
        
        # Recursively count teams with decreasing ratings
        for nxt_idx in range(curr_idx + 1, self.n):
            if rating[nxt_idx] < rating[curr_idx]:
                valid_teams += self._cnt_dec_teams(rating, nxt_idx, team_sz + 1, dec_cache)
                
        # Cache and return the result
        dec_cache[curr_idx][team_sz] = valid_teams
        return valid_teams