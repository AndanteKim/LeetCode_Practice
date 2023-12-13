class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        curr_gain, total_gain, ans = 0, 0, 0
        
        for i in range(len(gas)):
            total_gain += gas[i] - cost[i]
            curr_gain += gas[i] - cost[i]
            if curr_gain < 0:
                curr_gain = 0
                ans = i + 1
        
        return -1 if total_gain < 0 else ans