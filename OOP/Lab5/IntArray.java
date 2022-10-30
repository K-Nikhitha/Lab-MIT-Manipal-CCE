
import java.util.Scanner;
class ArrayInt
{
  Scanner in = new Scanner(System.in);
  int arr[]= new int[10];
  void getInfo()
  {
    System.out.println("Enter the array elements: ");
    for(int i=0; i<10; i++)
    {
      arr[i]=in.nextInt();
    }
  }
  void display()
  {
    System.out.println("\n Sorted Array elements: ");
    for(int i=0; i<10; i++)
      System.out.println(arr[i]);
  }
  void Largest()
  {
    int large;
    large= arr[0];
    for(int i=0; i<10; i++)
    {
      if(arr[i]>large)
        large=arr[i];
    }
    System.out.println("\n Largest Element in the Array: "+ large);
  }
  void Avg()
  {
    int sum;
    sum=0;
    for(int i=0; i<10; i++)
    {
      sum += arr[i];
    }
    float av;
    av= sum/10;
    System.out.println("\n Average Marks: "+ av);
  }
  void SortArray()
  {
    for(int i=0; i<10; i++)
    {
      for(int j=i+1; j<10; j++)
      {
        int temp=0;
        if(arr[i]>arr[j])
        {
          temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
        }
      }
    }
  }
}
public class IntArray
{
    public static void main(String[] args)
    {
      Scanner in = new Scanner(System.in);
      ArrayInt obj = new ArrayInt();
      obj.getInfo();
      obj.SortArray();
      obj.display();
      obj.Largest();
      obj.Avg();
    }
  }
