class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        
        string cur = "1";
        char tmp_str[16];
        for (int i = 1; i < n; i++) {
        	string tmp = "";
        	char cur_char = cur[0];
        	int cnt = 1;
        	for (int j = 1; j < cur.length(); j++) {
        		if (cur[j] != cur_char) {
        			sprintf(tmp_str, "%d%c", cnt, cur_char);
        			tmp += string(tmp_str);
        			cur_char = cur[j];
        			cnt = 0;
				}
				cnt++;
			}
			sprintf(tmp_str, "%d%c", cnt, cur_char);
        	tmp += string(tmp_str);
        	cur = tmp;
		}
		return cur;
    }
};