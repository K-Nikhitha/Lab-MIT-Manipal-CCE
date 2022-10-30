/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab5;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */
 class CallByReference
 {
   int a,b;
   CallByReference(int n1, int n2)
   {
     a=n1;
     b=n2;
   }
   void CBRef(CallByReference obj2)
   {
     int temp;
     temp=obj2.a;
     obj2.a = obj2.b;
     obj2.b = temp;
     System.out.println("Values in method(): ");
     System.out.println("Number 1: "+ obj2.a);
     System.out.println("Number 2: " + obj2.b);
   }
 }
 class CallByValue
 {
   int a,b;
   void CBValue(int a, int b)
   {
     int temp;
     temp=a;
     a=b;
     b=temp;
     System.out.println("Values in method(): ");
     System.out.println("Number 1: "+ a);
     System.out.println("Number 2: " + b);
   }
 }

public class SwapTwo
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n1,n2;
        System.out.println("Enter 2 numbers to swap: ");
        System.out.println("Number 1: ");
        n1=in.nextInt();
        System.out.println("Number 2: ");
        n2=in.nextInt();
        System.out.println("\nCall by Value: ");
        CallByValue obj1 = new CallByValue();
        System.out.println("Original Numbers: ");
        System.out.println("Number 1: "+ n1);
        System.out.println("Number 2: " + n2);
        System.out.println("After Swapping:");
        obj1.CBValue(n1,n2);
        System.out.println("Values in main(): ");
        System.out.println("Number 1: "+ n1);
        System.out.println("Number 2: " + n2);


        System.out.println("\nCall my Reference: ");
        CallByReference obj2 = new CallByReference(n1,n2);
        System.out.println("Original Numbers: ");
        System.out.println("Number 1: "+ obj2.a);
        System.out.println("Number 2: " + obj2.b);
        System.out.println("After Swapping:");
        obj2.CBRef(obj2);
        System.out.println("Values in main(): ");
        System.out.println("Number 1: "+ obj2.a);
        System.out.println("Number 2: " + obj2.b);
      }
}
