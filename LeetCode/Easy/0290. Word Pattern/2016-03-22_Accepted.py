class Solution(object):
    def wordPattern(self, pattern, str):
        mapping = {} # a -> dog
        mapping_back = {} # dog -> a
        word_set = str.split(' ')
        if len(pattern) != len(word_set):
            return False
        for i in range(len(pattern)):
            if not pattern[i] in mapping:
                if word_set[i] in mapping_back:
                    return False
                mapping[pattern[i]] = word_set[i]
                mapping_back[word_set[i]] = pattern[i]
            if mapping[pattern[i]] != word_set[i]:
                return False
        return True
