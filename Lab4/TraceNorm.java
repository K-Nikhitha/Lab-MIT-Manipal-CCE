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
public class TraceNorm
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int mx[][]= new int[6][6];
        int r,c;
        System.out.println("Enter number of rows of the matrix: ");
        r= in.nextInt();
        System.out.println("Enter number of colums of the matrix: ");
        c = in.nextInt();
        if (r != c)
            System.out.println("The matrix must  be a square matrix. \n");
        else
        {
            System.out.println("Enter the elements of the matrix: \n");
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c; j++)
                {
                    mx[i][j] = in.nextInt();
                }
            }
            int trace, norm;
            trace=0;
            norm=0;
            for(int i=0; i<r ; i++)
            {
                for(int j=0; j<c; j++)
                {
                    if (i==j)
                        trace+=mx[i][j];
                    norm+= (mx[i][j]*mx[i][j]);
                }
            }
            System.out.println("Trace of the matrix: " + trace);
            System.out.println("Norm of the matrix: " + norm);
        }
    }


}
