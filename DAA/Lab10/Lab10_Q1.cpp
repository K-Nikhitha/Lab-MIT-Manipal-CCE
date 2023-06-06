#include<iostream>
 
using namespace std;
 
void binPacking(int *a, int size, int n)
{
    int binCount = 1;
    int s = size;
    for (int i = 0; i < n; i++)
    {
        if (s - *(a + i) > 0)
        {
            s -= *(a + i);
            continue;
        }
        else
        {
            binCount++;
            s = size;
            i--;
        }
    }
 
    cout << "Number of bins required: " << binCount;
}
 
int main(int argc, char **argv)
{
    cout << "BIN - PACKING Algorithm\n";
    cout << "Enter the number of items in Set: ";
    int n;
    cin >> n;
    cout << "Enter " << n << " items:";
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the bin size: ";
    int size;
    cin >> size;
    binPacking(a, size, n);
}
