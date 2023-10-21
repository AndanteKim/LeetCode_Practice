# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.stack = [[nestedList, 0]]
        
    def make_stack_top_an_integer(self) -> None:
        while self.stack:
            
            curr_list = self.stack[-1][0]
            curr_index = self.stack[-1][1]
            
            # If the top list is used up, pop it and its index
            if len(curr_list) == curr_index:
                self.stack.pop()
                continue
                
            # Otherwise, if it's already an integer, we don't need to do anything
            if curr_list[curr_index].isInteger():
                break
            
            # Otherwise, it must be a list. We need to increment the index
            # on the previous list, and add the new list
            new_list = curr_list[curr_index].getList()
            self.stack[-1][1] += 1 # increment old
            self.stack.append([new_list, 0])
    
    def next(self) -> int:
        self.make_stack_top_an_integer()
        curr_list, curr_index = self.stack[-1][0], self.stack[-1][1]
        self.stack[-1][1] += 1
        return curr_list[curr_index].getInteger()
    
    def hasNext(self) -> bool:
        self.make_stack_top_an_integer()
        return len(self.stack) > 0

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())