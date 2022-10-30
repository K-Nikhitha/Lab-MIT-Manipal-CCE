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
public class PrimeNum
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n, f;
        int[] arr = new int[50];
        System.out.println("Enter no. of array elements: ");
        n= in.nextInt();
        System.out.println("Enter the array elemnts: \n");
        for (int i=0; i<n; i++)
            {
                arr[i]= in.nextInt();
            }
        System.out.println("Prime numbers in the array: ");
        for (int i=0; i<n; i++)
        {
            f=0;
            for( int j=2; j< arr[i]; j++)
            {
                if (arr[i] % j==0)
                {
                    f+=1;
                    break;
                }
            }
            if (f==0 && arr[i] != 1)
                System.out.println(arr[i] + "\t");

        }
    }
}
