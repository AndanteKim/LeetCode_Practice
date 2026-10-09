class Solution:
    def minimumCost(
        self, n: int, highways: List[List[int]], discounts: int
    ) -> int:
        # Construct the graph from the given highways array
        graph = [[] for _ in range(n)]
        for highway in highways:
            u, v, toll = highway
            graph[u].append((v, toll))
            graph[v].append((u, toll))

        # Min-heap priority queue to store tuples of (cost, city, discounts used)
        pq = [(0, 0, 0)]  # Start from city 0 with cost 0 and 0 discounts used

        # 2D array to track minimum distance to each city with a given number of discounts used
        dist = [[float("inf")] * (discounts + 1) for _ in range(n)]
        dist[0][0] = 0

        while pq:
            current_cost, city, discounts_used = heapq.heappop(pq)

            # If this cost is already higher than the known minimum, skip it
            if current_cost > dist[city][discounts_used]:
                continue

            # Explore all neighbors of the current city
            for neighbor, toll in graph[city]:
                # Case 1: Move to the neighbor without using a discount
                if current_cost + toll < dist[neighbor][discounts_used]:
                    dist[neighbor][discounts_used] = current_cost + toll
                    heapq.heappush(
                        pq,
                        (
                            dist[neighbor][discounts_used],
                            neighbor,
                            discounts_used,
                        ),
                    )

                # Case 2: Move to the neighbor using a discount if available
                if discounts_used < discounts:
                    new_cost_with_discount = current_cost + toll // 2
                    if (
                        new_cost_with_discount
                        < dist[neighbor][discounts_used + 1]
                    ):
                        dist[neighbor][
                            discounts_used + 1
                        ] = new_cost_with_discount
                        heapq.heappush(
                            pq,
                            (
                                new_cost_with_discount,
                                neighbor,
                                discounts_used + 1,
                            ),
                        )

        # Find the minimum cost to reach city n-1 with any number of discounts used
        min_cost = min(dist[n - 1])
        return -1 if min_cost == float("inf") else min_cost