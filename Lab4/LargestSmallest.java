import java.util.Scanner;
public class LargestSmallest
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n, small, large;
        int[] arr = new int[50];
        System.out.println("Enter no. of array elements: ");
        n= in.nextInt();
        System.out.println("Enter the array elements: \n");
        for (int i=0; i<n; i++)
            {
                arr[i]= in.nextInt();
            }
        small= arr[0];
        large= arr[0];
        for(int i=1; i<n; i++)
        {
            if(arr[i]>=large)
                large=arr[i];

            if(arr[i]<=small)
                small=arr[i];
        }
        System.out.println("Smallest element in the array: " + small);
        System.out.println("Largest element in the array: " + large);
    }

}
