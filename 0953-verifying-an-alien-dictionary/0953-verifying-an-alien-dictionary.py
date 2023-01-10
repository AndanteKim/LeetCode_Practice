class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        lookup_order, prev = {o:idx for idx, o in enumerate(order)}, list()
        for word in words:
            flag, order_match = False, []
            for c in word:
                order_match.append(c)
            if not prev:
                prev = order_match
            else:
                for i in range(min(len(prev), len(order_match))):
                    if lookup_order[prev[i]] < lookup_order[order_match[i]]:
                        flag = True
                        break
                    elif lookup_order[prev[i]] > lookup_order[order_match[i]]:
                        return False
                if not flag and (len(prev) > len(order_match)):
                    return False
            prev = order_match
        
        return True