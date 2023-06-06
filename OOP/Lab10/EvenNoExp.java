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
 class EvenNumberException extends Exception
 {
   int num;
   EvenNumberException(int n)
   {
     num = n;
   }
    public String toString()
    {
        return "Error. Even Number.";
    }
}

public class EvenNoExp
{
  static void compute(int n) throws EvenNumberException
  {
    if (n%2==0)
      throw new EvenNumberException(n);
    else
    System.out.println("No Error. Odd Number.");
  }
    public static void main(String args[])
    {
      Scanner in = new Scanner(System.in);
      int n;
      System.out.println("Enter a number.");
      n = in.nextInt();
      try
      {
        compute(n);
      }
      catch(EvenNumberException e)
      {
          System.out.println(e);
      }
    }
}
