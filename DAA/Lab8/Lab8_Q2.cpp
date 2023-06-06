#include <iostream>
using namespace std;

void OptimalOrder(int i, int j, int n, int* bracket, char& name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    OptimalOrder(i, *((bracket + i * n) + j), n, bracket, name);
    OptimalOrder(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    cout << ")"<<endl;
}

void matrixChainOrder(int a[], int n)
{

    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i <n; i++)
        m[i][i] = 0;
    for (int L = 2; L <n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    cout << "Optimal Order is : ";
    OptimalOrder(1, n - 1, n, (int*)bracket, name);
}

int main()
{
  int n;
  cout<<"Enter number of matrices:";
  cin>>n;
  cout<<"Enter Dimensions(include common dimension only once):\n";
  int a[n+1];
  for(int i=0;i<n+1;i++)
    cin>>a[i];
  matrixChainOrder(a, n+1);
  return 0;
}
