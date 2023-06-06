#include <iostream>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int a[], int p, int q, int r)
{
  //L = A[p..q] and M = A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = a[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = a[q + 1 + j];

  //Current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2)
  {
    if (L[i] <= M[j])
    {
      a[k] = L[i];
      i++;
    }
    else
    {
      a[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1)
  {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    a[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int a[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2; //m is the point of division
    mergeSort(a, l, m); //recursive call to the left of m
    mergeSort(a, m + 1, r); //recursive call to the right of m
    merge(a, l, m, r); // merge two subarrays
  }
}

// Driver program
int main()
{
  int n;
  cout<<"Enter number of elements:";
  cin>>n;
  cout<<"Enter array elements:";
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  mergeSort(a, 0, n - 1);
  cout<<"Sorted Array: ";
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  return 0;
}
