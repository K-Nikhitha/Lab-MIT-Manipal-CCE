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
public class ArrangeAlpha
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int n;
        System.out.println("Enter number of strings:");
        n=in.nextInt();
        String temp;
        String[] str = new String[n];
        System.out.println("Enter the Strings:");
        for(int i=0; i<n; i++)
        {
            str[i] = in.next();
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(str[i].compareTo(str[j])>0)
                {
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
        }
        System.out.println("Strings in sorted order:");
        for(int i=0; i<n; i++)
        {
            System.out.println(str[i]);
        }
    }
}
