import re

class Solution(object):
    def reverseWords(self, s):
        s = re.sub(r'\s+', ' ', s)
        s = re.sub(r'^\s+', '', s)
        s = re.sub(r'\s+$', '', s)
        return ' '.join(s.split(' ')[::-1])
