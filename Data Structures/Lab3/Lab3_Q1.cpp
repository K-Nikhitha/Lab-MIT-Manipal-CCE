#include<iostream>
using namespace std;
int n;
class Queue
{
  int front, rear;
  int q[10];
  public:
    Queue()
    {
      front=0;
      rear=-1;
    }
    void insert();
    void del();
    void display();
};
void Queue::insert()
{
  if(rear == n-1)
    cout<<endl<<"Queue Overflow. \n";
  else
  {
    rear +=1;
    cout<<"Enter element to be inserted: ";
    cin>>q[rear];
  }
}
  void Queue::del()
  {
    if(front>rear)
    {
      cout<<endl<<"Queue Underflow. \n";
    }
    else
    {
      cout<<"\n The element "<<q[front]<<" is deleted."<<endl;
      front +=1;
    }
  }
  void Queue::display()
  {
    if(front>rear)
    {
      cout<<endl<<"Queue Underflow. \n";
    }
    else
    {
      cout<<"\n The elements in the Queue are: \n";
      for(int i=front; i<=rear; i++)
        cout<<endl<<q[i];
    }
    cout<<endl;
  }
int main()
{
    cout<<"Enter the number of elements: ";
    cin>>n;
    int ch;
    Queue q;
    char rep='y';
    while(rep=='y' || rep=='Y')
    {
        cout<<"Enter Choice: \n 1.Insert \n 2.Delete \n 3.Display \n >> ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                {
                    q.insert();
                    break;
                }
            case 2:
                {
                    q.del();
                    break;
                }
            case 3:
                {
                    q.display();
                    break;
                }
            default:
                {
                    cout<<"Invalid choice."<<endl;
                    break;
                }
        }
        cout<<"Continue ? [Y/N]: ";
        cin>>rep;
    }
    return 0;
}
