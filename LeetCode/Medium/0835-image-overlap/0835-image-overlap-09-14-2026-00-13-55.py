class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        def non_zero_cells(M: List[List[int]]) -> List[int]:
            flat = []
            for x in range(m):
                for y in range(m):
                    if M[x][y]:
                        flat.append((x, y))
            
            return flat
        
        m = len(img1)
        ans, trans_cnt = 0, defaultdict(int)
        
        A, B = non_zero_cells(img1), non_zero_cells(img2)

        for (x_a, y_a) in A:
            for (x_b, y_b) in B:
                vec = (x_b - x_a, y_b - y_a)
                trans_cnt[vec] += 1
                ans = max(ans, trans_cnt[vec])

        return ans