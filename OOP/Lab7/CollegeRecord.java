/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab7;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */

class MIT
{
    static class Student_Detail
    {
        String name;
        long id;
        String college_name = "MIT";
        void display_details()
        {
            System.out.println("\nName: "+ name);
            System.out.println("ID: " + id);
            System.out.println("College Name: " + college_name);
        }
    }
    Student_Detail[] dets = new Student_Detail[25];
}

public class CollegeRecord
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        MIT mit = new MIT();
        System.out.println("Enter the number of student: ");
        int n = in.nextInt();
        System.out.println("Enter Student Details:");
        for(int i = 0; i<n ; i++)
        {
            mit.dets[i] = new MIT.Student_Detail();
            System.out.println("\nEnter Name: ");
            mit.dets[i].name= in.next();
            System.out.println("Enter ID:");
            mit.dets[i].id = in.nextLong();
        }
        System.out.println("\nStudent Details:\n");
        for(int i =0; i<n; i++)
        {
            mit.dets[i].display_details();
        }
    }

}
