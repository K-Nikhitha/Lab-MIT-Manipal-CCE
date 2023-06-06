#include<iostream>
 using namespace std;
class Student
{
	char name[100];
	int rollno;
	char grade;

public:

	void read(Student s[],int n);
	void display(Student s[],int n);
	void sort(Student s[],int n);
};

void Student::read(Student s[],int n)
{
	for(int i=0;i<n;i++)
	{
	    cout<<endl;
		cout<<"Enter Name: ";
		cin>>s[i].name;
    cout<<"Enter Roll no.: ";
		cin>>s[i].rollno;
    cout<<"Enter Grade: ";
		cin>>s[i].grade;
	}
}

void Student::display(Student s[],int n)
{
	for(int i=0;i<n;i++)
	{
	    cout<<endl;
		cout<<"Name: "<<s[i].name<<endl;
		cout<<"Roll No: "<<s[i].rollno<<endl;
		cout<<"Grade: "<<s[i].grade<<endl;
	}
}

void Student::sort(Student s[],int n)
{
	Student temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(s[j].rollno>s[j+1].rollno)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
}



int main()
{
	int n;
	Student s[20];
	cout<<"Enter the number of students: ";
	cin>>n;
	cout<<endl<<"Enter details of all the students: "<<endl;
	Student().read(s,n);
	Student().sort(s,n);
	cout<<endl<<"List of Students sorted wrt Roll No: \n"<<endl;
	Student().display(s,n);
	return 0;
}
