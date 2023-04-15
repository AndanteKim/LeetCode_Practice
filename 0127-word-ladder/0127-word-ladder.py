class Solution:
    def __init__(self):
        self.length = 0
        self.all_combo_dict = defaultdict(list)
        
    def visitWordNode(self, queue: Deque[str], visited: Dict[str, int], \
                      others_visited: Dict[str, int]) -> int:
        queue_size = len(queue)
        for _ in range(queue_size):
            current_word = queue.popleft()
            for i in range(self.length):
                new_word = current_word[:i] + "*" + current_word[i+1:]
                
                for word in self.all_combo_dict[new_word]:
                    if word in others_visited:
                        return visited[current_word] + others_visited[word]
                    if word not in visited:
                        visited[word] = visited[current_word] + 1
                        queue.append(word)
        return None
    
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        
        self.length = len(beginWord)
        
        for word in wordList:
            for i in range(self.length):
                self.all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)
        
        queue_begin = deque([beginWord])
        queue_end = deque([endWord])
        
        
        visited_begin = {beginWord : 1}
        visited_end = {endWord : 1}
        ans = None
        
        while queue_begin and queue_end:
            if len(queue_begin) <= len(queue_end):
                ans = self.visitWordNode(queue_begin, visited_begin, visited_end)
            else:
                ans = self.visitWordNode(queue_end, visited_end, visited_begin)
            if ans:
                return ans
        return 0