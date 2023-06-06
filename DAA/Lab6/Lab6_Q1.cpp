#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int a[], int left, int right)
{
  int pivot = a[right]; //rightmost element is pivot

  int i = (left - 1);  // pointer for greater element
  for (int j = left; j < right; j++)
  {
    if (a[j] <= pivot) //compare each element in the array with the pivot
    {
      // if element smaller than pivot is found swap it with the greater element pointed by i
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[right]);  // swap pivot with the greater element at i
  return (i + 1);
}

void quickSort(int a[], int left, int right) {
  if (left < right)
  {
    // find the pivot element such that elements smaller than pivot are on left of pivot elements greater than pivot are on righ of pivot
    int pi = partition(a, left, right);
    // recursive call on the left of pivot
    quickSort(a, left, pi - 1);
    // recursive call on the right of pivot
    quickSort(a, pi + 1, right);
  }
}

int main()
{
  int n;
  cout<<"Enter number of elements:";
  cin>>n;
  int a[n];
  cout<<"Enter array elements:";
  for(int i=0;i<n;i++)
    cin>>a[i];
  quickSort(a, 0, n - 1);
  cout << "Array sorted in Ascending Order:";;
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
