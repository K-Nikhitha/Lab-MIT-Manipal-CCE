#include<iostream>
using namespace std;
int count = 0;
 void Bubble(int a[],int n)
 {
     for(int i=n;i>1;i--)
     {
       count++;
       for(int j=0;j<i-1;j++)
       {
         count++;
         count++;
         if(a[j]>a[j+1])
         {
           int temp = a[j];
           a[j] = a[j+1];
           a[j+1] = temp;
           count++;
           count++;
           count++;
         }
       }
       count++;
     }
     count++;
 }
 int main()
 {
     int n;
     cout<<"Enter number of elements:";
     cin>>n;
     int arr[n];
     cout<<"Enter array elements:";
     for(int i=0;i<n;i++)
        cin>>arr[i];
    Bubble(arr,n);
    cout<<"Sorted Array: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl<<"Step Count: "<<count<<endl;
 }
