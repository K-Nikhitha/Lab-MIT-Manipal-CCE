/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
// package lab4;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */
public class SearchMatrix
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int mx[][]= new int[6][6];
        int r,c,ele, count=0;
        System.out.println("Enter number of rows of the matrix: ");
        r= in.nextInt();
        System.out.println("Enter number of colums of the matrix: ");
        c = in.nextInt();
        System.out.println("Enter the elements of the matrix: \n");
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                mx[i][j] = in.nextInt();
            }
        }
        System.out.println("Enter element to count its occurence: ");
        ele = in.nextInt();
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if( mx[i][j]== ele)
                    count+=1;
            }
        }
        System.out.println("Number of occurences of the element is: " + count);
    }
}
