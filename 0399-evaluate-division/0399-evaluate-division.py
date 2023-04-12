class Solution:
    def find(self, node_id: str) -> Tuple[str, float]:
        if node_id not in self.gid_weight:
            self.gid_weight[node_id] = (node_id, 1)
        group_id, node_weight = self.gid_weight[node_id]
        
        if group_id != node_id:
            new_group_id, group_weight = self.find(group_id)
            self.gid_weight[node_id] = (new_group_id, node_weight * group_weight)
        return self.gid_weight[node_id]
    
    def union(self, dividend: str, divisor: str, value: float) -> None:
        dividend_gid, dividend_weight = self.find(dividend)
        divisor_gid, divisor_weight = self.find(divisor)
        if dividend_gid != divisor_gid:
            self.gid_weight[dividend_gid] = (divisor_gid, divisor_weight * value / dividend_weight)
        
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        self.gid_weight = dict()
            
        for (dividend, divisor), value in zip(equations, values):
            self.union(dividend, divisor, value)
        
        ans = []
        
        for (dividend, divisor) in queries:
            if dividend not in self.gid_weight or divisor not in self.gid_weight:
                ans.append(-1.0)
            else:
                dividend_gid, dividend_weight = self.find(dividend)
                divisor_gid, divisor_weight = self.find(divisor)
                if dividend_gid != divisor_gid:
                    ans.append(-1.0)
                else:
                    ans.append(dividend_weight / divisor_weight)
        return ans