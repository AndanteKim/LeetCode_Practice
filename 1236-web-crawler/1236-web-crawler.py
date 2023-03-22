# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        ans = [startUrl]
        queue = deque([startUrl])
        
        while queue:
            parse = queue.popleft()
            derived = htmlParser.getUrls(parse)
            
            for directory in derived:
                if parse.split('/')[2] == directory.split('/')[2] and directory not in ans:
                    ans.append(directory)
                    queue.append(directory)
        
        return ans