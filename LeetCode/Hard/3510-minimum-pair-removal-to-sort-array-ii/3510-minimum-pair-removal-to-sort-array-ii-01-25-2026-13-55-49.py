class Node:
    def __init__(self, val: int, left: int):
        self.val = val
        self.left = left
        self.prev = None
        self.next = None

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        class PQItem:
            def __init__(self, first: 'Node', second: 'Node', cost: int):
                self.first = first
                self.second = second
                self.cost = cost

            def __lt__(self, other: 'Node') -> bool:
                if self.cost == other.cost:
                    return self.first.left < other.first.left
                return self.cost < other.cost

        pq, head = [], Node(nums[0], 0)
        curr = head
        merged = [False] * len(nums)
        dec_cnt, cnt = 0, 0

        for i in range(1, len(nums)):
            new_node = Node(nums[i], i)
            curr.next = new_node
            new_node.prev = curr
            heappush(pq, PQItem(curr, new_node, curr.val + new_node.val))
        
            if nums[i - 1] > nums[i]:
                dec_cnt += 1
            
            curr = new_node
        
        while dec_cnt > 0:
            item = heappop(pq)
            first, second, cost = item.first, item.second, item.cost

            if (
                merged[first.left]
                or merged[second.left]
                or first.val + second.val != cost
            ):
                continue
            
            cnt += 1

            if first.val > second.val:
                dec_cnt -= 1

            prev_node = first.prev
            next_node = second.next
            first.next = next_node
            if next_node:
                next_node.prev = first
            
            if prev_node:
                if prev_node.val > first.val and prev_node.val <= cost:
                    dec_cnt -= 1
                elif prev_node.val <= first.val and prev_node.val > cost:
                    dec_cnt += 1
                
                heappush(pq, PQItem(prev_node, first, prev_node.val + cost))
            
            if next_node:
                if second.val > next_node.val and cost <= next_node.val:
                    dec_cnt -= 1
                elif second.val <= next_node.val and cost > next_node.val:
                    dec_cnt += 1
                
                heappush(pq, PQItem(first, next_node, cost + next_node.val))

            first.val = cost
            merged[second.left] = True

        return cnt