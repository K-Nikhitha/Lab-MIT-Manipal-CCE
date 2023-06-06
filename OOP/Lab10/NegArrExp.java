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
public class NegArrExp
{
    public static void main(String args[])
    {
      Scanner in = new Scanner(System.in);
      int n;
      System.out.println("Enter array size: ");
      n = in.nextInt();
      try
      {
          int[] arr = new int[n];
      }
      catch(NegativeArraySizeException e)
      {
        System.out.println("Error. Array created with a negative size. \n");
      }
    }
}
