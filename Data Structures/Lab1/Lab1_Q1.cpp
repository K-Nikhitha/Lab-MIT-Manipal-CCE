#include<iostream>
using namespace std;
int string_length(char *str)
{
    int c=0;
    for(int i=0; str[i]!='\0'; i++)
        c++;
    return c;
}

void concatenate_string(char *str1, char *str2)
{
    char str[50];
    int i=0;
    for(i; str1[i] != '\0'; i++)
        str[i]=str1[i];
    for(int j=0; str2[j] != '\0'; i++, j++)
        str[i]=str2[j];
    str[i]='\0';
    cout<<"Concatenated String: ";
    cout<<str;
    cout<<endl;
}

void string_compare(char *str1, char *str2)
{
    int n1=string_length(str1);
    int n2=string_length(str2);
    int f=0,num;
    if (n1>n2)
    {
        num=n1;
    }
    else
        num=n2;
    for(int i=0; i<num ; i++)
    {
        if (str1[i] != str2[i])
            f++;
    }
    if (f==0)
        cout<<"The two strings are the same."<<endl;
    else
        cout<<"The two strings are not the same."<<endl;
}

void insert_substr(char *str, char *sub_str)
{
    int pos;
    cout<<"Enter the position of the Substring:";
    cin>>pos;
    char newstr[50];
    int i=0;
    for (i; i<pos-1; i++ )
    {
        newstr[i]=str[i];
    }
    for (int j=0; sub_str[j] != '\0'; i++, j++)
    {
        newstr[i]=sub_str[j];
    }
    for ( int k=pos-1; str[k]!= '\0'; i++, k++)
    {
        newstr[i]=str[k];
    }
    newstr[i]='\0';

    cout<<"New String: ";
    cout<<newstr<<endl;

}

void delete_substr(char *str, char *sub_str)
{
  int i, j=0, k=0, n=0, f=0;
  char newstr[50];
  for(i=0; str[i] !='\0'; i++)
  {
    k=i;
    while(str[i]==sub_str[j])
    {
      i++,j++;
      if(j==string_length(sub_str))
        {
          f=1;
          break;
        }
    }
    j=0;
    if(f==0)
      i=k;
    else
      f=0;
    newstr[n++] = str[i];
    newstr[n] ='\0';
  }
  cout<<"New String: ";
  cout<<newstr<<endl;
}
int main()
{
  int ch;
  char rep='y';
  while(rep=='y' || rep=='Y')
  {
    cout<<"Enter choice: \n 1.String Length \n 2.String concatenation \n 3.String comparison \n 4.Insert substring \n 5.Delete substring \n >>";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        int n;
        char str[50];
        cout<<"Enter string to find its length: ";
        cin>>str;
        n=string_length(str);
        cout<<"Length of string : "<<n<<endl;
        break;
      }
      case 2:
      {
        char str1[50], str2[50];
        cout<<"Enter two strings to concatenate: "<<endl;
        cout<<"String 1: ";
        cin>>str1;
        cout<<"String 2: ";
        cin>>str2;
        concatenate_string(str1,str2);
        break;
      }
      case 3:
      {
        char str1[50], str2[50];
        cout<<"Enter two strings to compare: ";
        cout<<"String 1: ";
        cin>>str1;
        cout<<"String 2: ";
        cin>>str2;
        string_compare(str1, str2);
        break;
      }
      case 4:
      {
        char str[50], sub_str[50];
        cout<<"Enter Main String: ";
        cin>>str;
        cout<<"Enter SubString to be inserted : ";
        cin>>sub_str;
        insert_substr(str,sub_str);
        break;
      }
      case 5:
      {
        char str[50], sub_str[50];
        cout<<"Enter String: ";
        cin>>str;
        cout<<"Enter SubString to be deleted : ";
        cin>>sub_str;
        delete_substr(str,sub_str);
        break;
      }
    }
    cout<<"Continue ? [Y/N]: ";
    cin>> rep;
  }
  return 0;
}
