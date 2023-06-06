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
public class Words
{
    public static void main(String args[])
    {
        System.out.println("Enter a five letter word: ");
        Scanner in = new Scanner(System.in);
        String input = in.next();
        for (int i = 0; i < input.length(); i++)
        {
            for (int j = 0; j < input.length(); j++)
            {
                for (int k = 0; k < input.length(); k++)
                {
                    if (i == j || i == k || j == k) continue;
                    char w[]= new char[3];
                    w[0] = input.charAt(i);
                    w[1] = input.charAt(j);
                    w[2] = input.charAt(k);
                    String s = new String(w);
                    System.out.println(s);
                }
            }
        }
    }
}
