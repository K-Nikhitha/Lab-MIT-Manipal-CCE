#include<iostream>
using namespace std;

int* findMinMax(int a[],int l, int r)
{
  int max,min;
  if(l==r)
  {
    max = min = a[l];
  }
  else if(l+1==r)
  {
    if(a[l]<a[r])
    {
      max = a[r];
      min = a[l];
    }
    else
    {
      max = a[l];
      min = a[r];
    }
  }
  else
  {
    int mid = l+(r-l)/2;
    int* leftm = findMinMax(a,l,mid);
    int* rightm = findMinMax(a, mid+1,r);
    if(leftm[0]>rightm[0])
      max = leftm[0];
    else
      max=rightm[0];
      if(leftm[1]<rightm[1])
        min=leftm[1];
      else
        min=rightm[1];
  }
  int* mx = new int[2];
  mx[0]=max;
  mx[1]=min;
  return mx;
}

int main()
{
  int n;
  cout<<"Enter number of array elements: ";
  cin>>n;
  int a[n];
  cout<<"Enter the array elements:\n";
  for(int i=0;i<n;i++)
    cin>>a[i];
  int *mm = findMinMax(a,0,n-1);
cout<<"Max: "<<mm[0]<<"\nMin: "<<mm[1]<<endl;
delete[] mm;
return 0;
}
