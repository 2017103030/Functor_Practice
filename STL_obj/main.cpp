#include <iostream>
using namespace std;
//Matrix Multiply Functor
//return M by N Matrix A  x  N by K Matrix B
//Example :
//A = {1,1,1,1}, B = {1,1,1,1}, M = 2, N = 2, K = 2
//return {2,2,2,2}
struct MatMultiply {
	template<typename T>
	int* operator()(const T* A, const T* B, int M, int N, int K) const {
		T* Result = new int[M * K];
		int cnt = 0;
		for (int m = 0; m < M; m++) { // Read m_th rows A 
			for (int k = 0; k < K; k++) {// Read k_th cols B
				T tmp = 0;
				for (int n = 0; n < N; n++) { // Read n_th cols A / Read n_th row of B
					tmp += *(A + N * m + n) * *(B + K * n + k);
				}
				*(Result + cnt) = tmp;
				cnt++;

			}

		}
		return Result;
	}
};

//Matrix Print Functor
//Prinit M by N Matrix
//Exapmle :
//A = {1,2,3,4}, M = 2, N =2
//result :
// 1 2
// 3 4
struct PrintMat {
	template<typename T>
	void operator()(T* Mat, int M, int N) {
		for (int m = 0; m < M ; m++) {
			for (int n = 0; n < N; n++) {
				cout << *(Mat + N * m + n) << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	MatMultiply mat_mul;
	PrintMat mat_print;
	int* A;
	int* B;
	A = new int[4];
	B = new int[4];
	for (int i = 0; i < 4; i++) {
		A[i] = i + 1;
		B[i] = 4 - i;
	}
	int* ans = mat_mul(A, B, 2, 2, 2);
	mat_print(ans,2,2);
	return 0;
}