/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab10;

import java.util.Scanner;

/**
 *
 * @author student
 */
 class MarkOutofBoundsException extends Exception
 {
    public String toString()
    {
        return "Maximum marks is 100 only..";
    }
}

class student
{
  int marks;
  String name;
}


public class MarkExp
{
    public static void main(String args[])
    {
        int m;
        String nm;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter Name: ");
        name = in.next();
        System.out.println("Enter Marks: ")
        marks = in.nextInt();
        student s = new Student(nm, m);
    }
}
