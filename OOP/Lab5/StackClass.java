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
 class Stack
 {
   private int n;
   private int[] s;
   private int top;
   public Stack (int size)
   {
     n = size;
     s = new int[n];
     top=-1;
   }
   public void push()
   {
     Scanner in = new Scanner(System.in);
     if (top==n-1)
        System.out.println("Stack Overflow. \n");
    else
    {
      top +=1;
      System.out.println("Enter the element to be inserted: ");
      s[top]=in.nextInt();
    }
   }
   public void pop()
   {
     if(top==-1)
        System.out.println("Stack Underflow. \n");
    else
    {
      System.out.println("The element "+ s[top]+ " is deleted.\n");
      top -=1;
    }
   }
   public void display()
   {
     if(top==-1)
        System.out.println("Stack is Empty. \n");
    else
    {
      System.out.println("The elements in the stack are: ");
      for(int i=top; i>=0; i--)
          System.out.println(s[i]);
    }
   }
 }
 public class StackClass
 {
     public static void main(String[] args)
     {
       Scanner in = new Scanner(System.in);
       int size,ch;
       System.out.println("Enter size of stack: ");
       size= in.nextInt();
       Stack s = new Stack(size);
       int rep=1;
       while(rep==1)
       {
         System.out.println("Enter Choice: \n 1.Push \n 2.Pop \n 3.Display \n >> ");
         ch = in.nextInt();
         switch(ch)
         {
           case 1:
           {
             s.push();
             break;
           }
           case 2:
           {
             s.pop();
             break;
           }
           case 3:
           {
             s.display();
             break;
           }
           default:
           {
             System.out.println("Invalid Choice. \n");
             break;
           }
         }
         System.out.println("Continue ? [1/0]: ");
         rep=in.nextInt();
       }
     }
  }
