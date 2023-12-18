class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        email_set = {}
        for email in emails:
            username, domain = email.split('@')
            username = username.split('+')[0]
            username = username.replace('.', '')
            email = username + '@' + domain
            email_set[email] = True
        return len(email_set)
        