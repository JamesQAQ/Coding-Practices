class Solution {
public:
    string addBinary(string a, string b) {
        if (b.length() > a.length()) {
        	string tmp = a;
        	a = b;
        	b = tmp;
		}
		for (int i = 0; i < b.length(); i++) {
			int val = b[i] - '0';
			a[a.size() - b.length() + i] += val;
		}
		for (int i = a.length() - 1; i > 0; i--) {
			if (a[i] >= '2') {
				a[i] -= 2;
				a[i - 1]++;
			}
		}
		if (a[0] >= '2') {
			a[0] -= 2;
			a = "1" + a;
		}
		return a;
    }
};