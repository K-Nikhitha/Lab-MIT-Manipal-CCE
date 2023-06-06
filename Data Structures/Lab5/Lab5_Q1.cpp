#include<iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    Node()
    {
      data = 0;
      next = NULL;
    }
    Node(int x)
    {
      data = x;
      next = NULL;
    }
};

class LinkedList
{
  Node *head;
  public:
    LinkedList()
    {
      head = NULL;
    }
    void insertBeg(int ele);
    void insertEnd(int ele);
    void insertBef(int x, int ele);
    void insertAf(int x, int ele);
    void delEle(int ele);
    void display();
};

void LinkedList :: insertBeg(int ele)
{
  Node *newNode = new Node(ele);
  Node *temp = head;
  head = newNode;
  newNode->next = temp;
}
void LinkedList :: insertEnd(int ele)
{
  Node *newNode = new Node(ele);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
    temp->next = newNode;
}
void LinkedList :: insertBef(int x, int ele)
{
  Node *newNode = new Node(ele);
  Node *temp = head;
  Node *tempPrev = NULL;
  if (head == NULL)
  {
    cout << "Empty List." << endl;
    return;
  }
  while (temp != NULL)
  {
    if ((temp->data == x) && (temp == head))
    {
      insertBeg(ele);
    }
    else if (temp->data == x)
    {
      tempPrev->next = newNode;
      newNode->next = temp;
      break;
    }
    else
    {
      tempPrev = temp;
      temp = temp->next;
    }
  }
}

void LinkedList :: insertAf(int x, int ele)
{
  Node *newNode = new Node(ele);
  Node *temp = head;
  Node *tempPrev = temp;
  if (head == NULL)
  {
      cout << "Empty List" << endl;
      return;
  }
  while (temp != NULL)
  {
    if ((temp->data == x) && (temp == head))
    {
      insertBeg(ele);
    }
    else if (tempPrev->data == x)
    {
      tempPrev->next = newNode;
      newNode->next = temp;
      break;
    }
    else
    {
      tempPrev = temp;
      temp = temp->next;
    }
  }
}
void LinkedList :: delEle(int ele)
{
  Node *temp = head;
  Node *tempPrev = temp;
  if (head == NULL)
  {
    cout << "Empty List. " << endl;
    return;
  }
  while (temp != NULL)
  {
    if ((temp->data == ele) && (temp == head))
    {
      head = temp->next;
      delete temp;
    }
    else if (temp->data == ele)
    {
      tempPrev->next = temp->next;
      delete temp;
      break;
    }
    else
    {
      tempPrev = temp;
      temp = temp->next;
    }
  }
}
void LinkedList :: display()
{
  Node *temp = head;
  if (head == NULL)
  {
    cout << "Empty list." << endl;
    return;
  }
  while (temp != NULL)
  {
    cout << temp->data<<" ";
    temp = temp->next;
    if (temp == NULL)
    {
      break;
    }
  }
  cout << endl;
}

int main()
{
  LinkedList L;
  int ch;
  char rep = 'y';
    cout<<"Enter Choice: "<<endl;
    cout<<"1. Insert an element at the beginning of the list. "<<endl;
    cout<<"2. Insert an element at the end of the list. "<<endl;
    cout<<"3. Insert an element before another element in the existing list."<<endl;
    cout<<"4. Insert an element after another element in the existing list."<<endl;
    cout<<"5. Delete a given element from the list."<<endl;
    cout<<"6. Print the list: "<<endl;
  while(rep =='y' || rep =='Y')
  {
    cout<<"Choice >>";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        int ele;
        cout<<"Enter element to be inserted: ";
        cin>>ele;
        L.insertBeg(ele);
        break;
      }
      case 2:
      {
        int ele;
        cout<<"Enter element to be inserted: ";
        cin>>ele;
        L.insertEnd(ele);
        break;
      }
      case 3:
      {
        int ele, x;
        cout<<"Enter element to be inserted: ";
        cin>>ele;
        cout<<"Enter the element before which it is to be inserted: ";
        cin>>x;
        L.insertBef(x, ele);
        break;
      }
      case 4:
      {
        int ele, x;
        cout<<"Enter element to be inserted: ";
        cin>>ele;
        cout<<"Enter the element after which it is to be inserted: ";
        cin>>x;
        L.insertAf(x, ele);
        break;
      }
      case 5:
      {
        int ele;
        cout<<"Enter element to be deleted: ";
        cin>>ele;
        L.delEle(ele);
        break;
      }
      case 6:
      {
        L.display();
        break;
      }
      default:
      {
        cout<<"Invalid Choice. "<<endl;
        break;
      }
    }
    cout<<"Continue? [Y/N]: ";
    cin>>rep;
  }
}
