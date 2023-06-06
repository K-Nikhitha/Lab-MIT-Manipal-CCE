#include<iostream>
using namespace std;
class Container
{
  int id,weight;
  void heapify(Container *c, int n, int i);
public:
  void getC(int d);
  void heapSort(Container *c, int n);
  void containerLoading(Container* c,int cap, int n, int* x);
};
void Container::getC(int d)
{
  id=d;
  cin>>weight;
}
void Container::heapify(Container *c, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && c[left].weight > c[largest].weight)
      largest = left;
    if (right < n && c[right].weight > c[largest].weight)
      largest = right;
    if (largest != i)
    {
      swap(c[i], c[largest]);
      heapify(c, n, largest);
    }
}
void Container::heapSort(Container *c, int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(c, n, i);
  for (int i = n - 1; i >= 0; i--)
  {
    swap(c[0], c[i]);
    heapify(c, i, 0);
  }
}

void Container::containerLoading(Container* c,int cap, int n, int* x)
{
  heapSort(c,n);
  for(int i=0;i<n;i++)
    x[i]=0;
  int w=0;
  for(int i=0;i<n && c[i].weight<=cap; i++)
  {
    x[c[i].id]=1;
    cap -= c[i].weight;
    w+=c[i].weight;
  }
  for(int i=0;i<n;i++)
    cout<<x[i]<<" ";
  cout<<"\n"<<w<<endl;
}
int main()
{
  int cap,n;
  cout<<"Enter No. of Containers: ";
  cin>>n;
  int x[n];
  Container c[n];
  cout<<"Enter Weight of Each Container: "<<endl;
  for(int i=0;i<n;i++)
  {
    c[i].getC(i);
  }
  cout<<"Enter Capacity:";
  cin>>cap;
  cout<<"x and Weight:"<<endl;
  c[0].containerLoading(c,cap,n,x);
}
