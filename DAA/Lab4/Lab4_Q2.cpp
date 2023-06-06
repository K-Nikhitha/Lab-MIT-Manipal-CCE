#include <iostream>
#include<algorithm>
using namespace std;

class item
{
public:
    int weight;
    int value;
    int id;
    void sortType(item* I,int n,int ch);
    void getI(int i);
    void loadKnapsack(item* I,int n, int cap, int ch);
};
void item:: getI(int i)
{
  id=i;
  cin>>weight>>value;
}
bool sort_weight(item i1, item i2)
{
    return i1.weight<i2.weight;
}

bool sort_value(item i1, item i2)
{
    return i1.value > i2.value;
}

bool sort_density(item i1, item i2)
{
    return i1.value/(float)i1.weight > i2.value/(float)i2.weight;

}

void item::sortType(item* I,int n,int ch)
{
    if(ch==1)
        sort(I,I+n,sort_weight);
    else if(ch==2)
        sort(I,I+n,sort_value);
    else if(ch==3)
        sort(I,I+n,sort_density);
}

void item::loadKnapsack(item* I,int n, int cap, int ch)
{
  sortType(I,n,ch);
    int x[n],wt=0,pt=0;
    for(int i=0;i<n;i++)
      x[i]=0;
    for(int i=0;i<n && I[i].weight<=cap;i++)
    {
      x[I[i].id]=1;
      cap -= I[i].weight;
      wt += I[i].weight;
      pt += I[i].value;
    }
    cout<<"Weight: "<<wt<<"\nProfit: "<<pt<<endl;
    for(int i=0;i<n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}

int main()
{
  int n,cap;
  cout<<"Enter number of items:";
  cin>>n;
  item I[n];
  cout<<"Enter Weight and Value of each Item:"<<endl;
  for(int i=0;i<n;i++)
    I[i].getI(i);
  cout<<"Enter Capacity of Knapsack:";
  cin>>cap;
  cout<<"Greedy Methods:"<<endl;
  cout<<"\nGreedy On Weight:"<<endl;
  I[0].loadKnapsack(I,n,cap,1);
  cout<<"\n\nGreedy On Profit"<<endl;
  I[0].loadKnapsack(I,n,cap,2);
  cout<<"\n\nGreedy On Profit Density"<<endl;
  I[0].loadKnapsack(I,n,cap,3);
}
