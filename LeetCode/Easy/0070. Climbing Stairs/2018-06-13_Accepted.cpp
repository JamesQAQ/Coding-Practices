struct Matrix {
	int val[2][2];
	
	Matrix(int a, int b, int c, int d) {
		val[0][0] = a;
		val[0][1] = b;
		val[1][0] = c;
		val[1][1] = d;
	}
	
	Matrix operator * (const Matrix &b) {
		Matrix res = Matrix(0, 0, 0, 0);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					res.val[i][j] += this->val[i][k] * b.val[k][j];
				}
			}
		}
		return res;
	}
};

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        
        n -= 2;
        Matrix res = Matrix(1, 0, 0, 1);
        Matrix t = Matrix(0, 1, 1, 1);
        for (int i = 1 << 30; i > 0; i >>= 1) {
        	res = res * res;
        	if (i & n) {
        		res = res * t;
			}
		}
		
		return res.val[0][0] + res.val[0][1] + res.val[1][0] + res.val[1][1];
    }
};