class Solution:
    def maxProfit(self, n: int, present: List[int], future: List[int], hierarchy: List[List[int]], budget: int) -> int:
        def dfs(u: int) -> Tuple[List[int], List[int], int]:
            cost, d_cost = present[u], (present[u] >> 1)

            # dp[u][state][budget]
            # state = 0: Don't purchase parent node, state = 1: Must purchase parent node
            dp0, dp1 = [0] * (budget + 1), [0] * (budget + 1)

            # sub_profit[state][budget]
            # state = 0: discount not available, state = 1: discount available
            sub_profit0, sub_profit1 = [0] * (budget + 1), [0] * (budget + 1)
            u_sz = cost

            for v in g[u]:
                child_dp0, child_dp1, v_sz = dfs(v)
                u_sz += v_sz
                for i in range(budget, -1, -1):
                    for sub in range(min(v_sz, i) + 1):
                        if i - sub >= 0:
                            sub_profit0[i] = max(
                                sub_profit0[i],
                                sub_profit0[i - sub] + child_dp0[sub]
                            )
                            sub_profit1[i] = max(
                                sub_profit1[i],
                                sub_profit1[i - sub] + child_dp1[sub]
                            )

            for i in range(budget + 1):
                dp0[i], dp1[i] = sub_profit0[i], sub_profit0[i]
                if i >= d_cost:
                    dp1[i] = max(
                        sub_profit0[i], sub_profit1[i - d_cost] + future[u] - d_cost
                    )
                
                if i >= cost:
                    dp0[i] = max(
                        sub_profit0[i], sub_profit1[i - cost] + future[u] - cost
                    )
            
            return dp0, dp1, u_sz


        g = [[] for _ in range(n)]
        for e in hierarchy:
            g[e[0] - 1].append(e[1] - 1)

        return dfs(0)[0][budget]