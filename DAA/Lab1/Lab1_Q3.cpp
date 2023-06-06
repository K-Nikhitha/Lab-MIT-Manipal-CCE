#include<iostream>
using namespace std;
int count=0;
void SelectionSort(int a[], int n)
{
    for(int i=n;i>1;i--)
    {
        count++;
        count++;
        int j=0,temp;
        for(int k=1;k<i;k++)
        {
            count++;
            count++;
            if(a[j]<a[k])
            {
                count++;
                j=k;
            }
        }
        count++;
        temp = a[j];
        a[j]=a[i-1];
        a[i-1]=temp;
        count++;
        count++;
        count++;
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
    SelectionSort(a,n);
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
        cout<<a[i];
    cout<<"\nStep Count: "<<count<<endl;
    return 0;
}
