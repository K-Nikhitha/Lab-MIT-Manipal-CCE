#include <iostream>
using namespace std;
int countR = 0;
int countI = 0;
int BSearchIt(int arr[], int beg, int last, int ele)
{

    while (beg<=last)
    {
        countI++;
        int mid = beg + (last-beg) / 2;
        countI++;
        countI++;
        if (arr[mid] == ele)
        {
            countI++;
            return mid;
        }
        countI++;
        if (arr[mid]<ele)
        {
            countI++;
            beg=mid+1;
        }
        else
        {
            countI++;
            last=mid-1;
        }
    }
    countI++;
    countI++;
    return -1;
}

int BSearchRec(int arr[], int ele, int beg, int last)
{
    countR++;
    if(last>=beg)
    {
        countR++;
        int mid = beg + (last - beg)/2;
        countR++;
        if(arr[mid] == ele)
        {
            countR++;
            return mid;
        }
        countR++;
        if(arr[mid]>ele)
        {
            countR++;
            return BSearchRec(arr,ele,beg,mid-1);
        }
        else
        {
        countR++;
        return BSearchRec(arr,ele,mid+1,last);
        }
    }
    countR++;
    return -1;
}

int main()
{
    int n,ele,ch,result;
    cout<<"Enter No. of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter sorted array elements:";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter element to search:";
    cin>>ele;
    cout<<"Enter Method: \n 1.Iterative\n 2.Recursive\n >>";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        result = BSearchIt(arr, 0, n - 1, ele);
        (result == -1) ? cout << "Element NOT Found" : cout << "Element found at position: " << result+1<<endl;
        cout<<"Step Count: "<<countI<<endl;
        break;
      }
      case 2:
      {
        result = BSearchRec(arr , ele, 0, n-1);
        (result == -1) ? cout << "Element NOT Found" : cout << "Element found at position: " << result+1<<endl;
        cout<<"Step Count: "<<countR<<endl;
        break;
      }
      default:
      {
        cout<<"Invalid Choice:"<<endl;
      }
    }
    return 0;
}
