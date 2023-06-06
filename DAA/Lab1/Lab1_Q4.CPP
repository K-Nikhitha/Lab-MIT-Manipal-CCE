#include<iostream>
using namespace std;
int count = 0;
void InsertionSort(int a[], int n)
{
  for(int i=1;i<n;i++)
  {
    count++;
    count++;
    int t= a[i],j=i-1;
    for(j;j>=0 && t<a[j]; j--)
    {
      count++;
      count++;
      a[j+1]=a[j];
    }
    count++;
    count++;
    a[j+1]=t;
  }
  count++;
}

int main()
{
  int n;
  cout<<"Enter No. of elements: ";
  cin>>n;
  int a[n];
  cout<<"Enter array elements: ";
  for(int i=0;i<n;i++)
      cin>>a[i];
  InsertionSort(a,n);
  cout<<"Sorted Array: ";
  for(int i=0;i<n;i++)
      cout<<a[i];
  cout<<"\nStep Count: "<<count<<endl;
  return 0;
}
