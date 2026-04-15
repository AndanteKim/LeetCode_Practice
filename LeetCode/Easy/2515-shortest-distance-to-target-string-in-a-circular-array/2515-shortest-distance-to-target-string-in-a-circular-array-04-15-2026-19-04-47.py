class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        def find_dist(idx: int, di: int) -> int:
            end = idx + n if di > 0 else idx - n
            for i in range(idx, end, di):
                if target == words[i % n]:
                    return abs(idx - i)

            return -1


        n = len(words)
        left_dist, right_dist = find_dist(startIndex, -1), find_dist(startIndex, 1)

        return min(left_dist, right_dist)