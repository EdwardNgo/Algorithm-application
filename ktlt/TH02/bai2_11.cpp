#include <iostream>

using namespace std;
typedef struct
{
	int n;
	int *a;
} Dathuc;
void Nhap(Dathuc &A)
{
	cin >> A.n;
	A.a = new int[A.n + 1];
	for (int i = 0; i <= A.n; i++)
	{
		cin >> A.a[i];
	}
}

Dathuc Tich(Dathuc P, Dathuc Q)
{
	Dathuc R;
	R.n = P.n + Q.n;
	R.a = new int[R.n + 1];
	for (int i = 0; i <= R.n; i++)
	{
		R.a[i] = 0;
		for (int j = 0; j <= P.n; j++)
			if (i >= j && i - j <= Q.n)
				R.a[i] += P.a[j] * Q.a[i - j];
	}
	return R;
}
void Xuat(Dathuc A)
{
	cout << A.a[0];
	for (int i = 1; i <= A.n; i++)
	{
		if (A.a[i] > 0)
			cout << "+";
		cout << A.a[i];
		cout << "*x^" << i;
	}
}
int main()
{
	Dathuc P, Q, R, S;
	Nhap(P);
	Nhap(Q);
	// Tich(P,Q,S);
	// Xuat(S);
	S = Tich(P, Q);
	int heso = S.n;
	int res = 0;
	for (int i = 0; i <= heso; i++)
	{
		res = res ^ S.a[i];
	}
	cout << res;
}