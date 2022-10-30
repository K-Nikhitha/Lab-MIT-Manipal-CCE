/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab4;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */
public class MergeArray {
     public static void main(String[] args)
     {
        Scanner in = new Scanner(System.in);
        int n1, n2;
        int[] arr1 = new int[20];
        int[] arr2 = new int[20];
        int[] arr3 = new int[40];
        System.out.println("Enter number of elements of array 1: ");
        n1 = in.nextInt();
        System.out.println("Enter the elements of array 1: ");
        for(int i=0; i< n1; i++)
        {
            arr1[i]= in.nextInt();
        }
        System.out.println("Enter number of elements of array 2: ");
        n2 = in.nextInt();
        System.out.println("Enter the elements of array 2: ");
        for(int i=0; i< n2; i++)
        {
            arr2[i]= in.nextInt();
        }
        int k;
        for(k=0; k< n1; k++)
        {
            arr3[k]=arr1[k];
        }
        for(int j=0; j<n2; j++, k++)
        {
            arr3[k]=arr2[j];
        }
        System.out.println("New Array: ");
        for(int i=0; i<n1+n2; i++)
            System.out.println(arr3[i]);
        int temp;
        for(int i=0; i<n1+n2; i++)
        {
            for(int j=i+1; j<n1+n2; j++)
            {
                if(arr3[i]>arr3[j])
                {
                    temp=arr3[i];
                    arr3[i]=arr3[j];
                    arr3[j]=temp;
                }
            }
        }
        System.out.println("Sorted Array: ");
        for(int i=0; i< n1+n2; i++)
            System.out.println(arr3[i]);
    }

}
