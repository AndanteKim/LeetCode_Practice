class Solution:
    def helper(self, half_rods: List[int]) -> Dict[int, int]:
        states = set()
        states.add((0, 0))
        for r in half_rods:
            new_states = set()
            for left, right in states:
                new_states.add((left + r, right))
                new_states.add((left, right + r))
            states |= new_states
        
        dp = dict()
        for left, right in states:
            dp[left - right] = max(dp.get(left - right, 0), left)
        return dp
    
    def tallestBillboard(self, rods: List[int]) -> int:
        n = len(rods)
        first_half = self.helper(rods[: n // 2])
        second_half = self.helper(rods[n // 2:])
        answer = 0
        
        for diff in first_half:
            if -diff in second_half:
                answer = max(answer, first_half[diff] + second_half[-diff])
        
        return answer
        