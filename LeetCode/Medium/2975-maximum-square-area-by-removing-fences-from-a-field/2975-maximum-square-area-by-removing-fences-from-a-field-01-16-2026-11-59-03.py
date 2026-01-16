class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        def get_edges(fences: List[int], border: int) -> Set[int]:
            points = sorted([1] + fences + [border])
            return {
                points[j] - points[i]
                for i in range(len(points))
                for j in range(i + 1, len(points))
            }
        
        mod = 10 ** 9 + 7

        h_edges = get_edges(hFences, m)
        v_edges = get_edges(vFences, n)

        max_edge = max(h_edges & v_edges, default = 0)
        return (max_edge * max_edge) % mod if max_edge else -1