class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        if len(s) == 1:
            if '1' <= s[0] and s[0] <= '9':
                return 1
            else:
                return 0
        dp_i_2 = 1
        if '1' <= s[0] and s[0] <= '9':
            dp_i_1 = 1
        else:
            dp_i_1 = 0
        for i in xrange(1, len(s)):
            v = int(s[i - 1: i + 1])
            dp_i = 0
            if 10 <= v and v <= 26:
                dp_i += dp_i_2
            if '1' <= s[i] and s[i] <= '9':
                dp_i += dp_i_1
            dp_i_2 = dp_i_1
            dp_i_1 = dp_i
        return dp_i_1
