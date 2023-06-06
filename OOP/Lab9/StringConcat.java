/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab9;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class StringConcat
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        String s1, s2, s3, s4, s5;
        String s= null;
        System.out.println("Enter String 1:");
        s1 = in.nextLine();
        System.out.println("Enter String 2:");
        s2 = in.nextLine();
        System.out.println("Enter String 3:");
        s3 = in.nextLine();
        System.out.println("Enter String 4:");
        s4 = in.nextLine();
        System.out.println("Enter String 5:");
        s5 = in.nextLine();
        s = s1.concat(s2);
        s = s.concat(s3);
        s = s.concat(s4);
        s = s.concat(s5);
        System.out.println("Concatenated String: "+ s);

    }

}
