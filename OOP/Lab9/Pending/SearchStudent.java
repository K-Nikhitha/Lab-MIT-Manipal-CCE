/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab9;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */
class Student
{
    Scanner in = new Scanner(System.in);
    int Reg;
    String fname, lname, deg;
    void getDetail()
    {
        System.out.println("\nEnter Registration No.: ");
        Reg = in.nextInt();
        System.out.println("Enter First Name: ");
        fname = in.next();
        System.out.println("Enter Last Name: ");
        lname = in.next();
        System.out.println("Enter Degree: ");
        deg = in.next();
    }
    String retFname()
    {
      return fname;
    }
    String retLname()
    {
      return lname;
    }
    void display()
    {
      System.out.println("\nRegistration No.: "+Reg);
      System.out.println("First Name: "+fname);
      System.out.println("Last Name: "+ lname);
      System.out.println("Degree: "+deg);

    }
}
public class SearchStudent
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int n =10;
        Student ob[] = new Student[10];
        System.out.println("Enter Details: ");
        for(int i=0; i<n; i++)
        {
            ob[i] = new Student();
            ob[i].getDetail();
        }
        char rep = 'y';
        while(rep=='y' || rep=='Y')
        {
          System.out.println("Enter choice to search: \n 1.First Name \n 2. Last Name\n ");
          int ch = in.nextInt();
          switch(ch)
          {
            case 1:
            {
              String fn;
              System.out.println("Enter First Name to search: ");
              fn = in.next();
              for(int i=0; i<n; i++)
              {
                if(fn.equals(ob[i].retFname()))
                {
                  ob[i].display();
                }
              }
              break;
            }
            case 2:
            {
              String ln;
              System.out.println("Enter Last Name to search: ");
              ln = in.next();
              for(int i=0; i<n; i++)
              {
                if(ln.equals(ob[i].retLname()))
                {
                  ob[i].display();
                }
              }
              break;
            }
            default:
            {
              System.out.println("Invalid Choice. \n");
            }
          }
          System.out.println("\nContinue? [Y/N]: ");
          rep=in.next().charAt(0);
      }
    }
}
