/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab5;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */
 public class Squaring
 {
   public static float square(float n)
   {
     float sq;
     sq = n*n;
     return sq;
   }
     public static void main(String[] args)
     {
       Scanner in = new Scanner(System.in);
       float n, sq;
       int rep=1;
       while(rep==1)
       {
         System.out.println("Enter value to find its square: ");
         n = in.nextFloat();
         sq = square(n);
         System.out.println("The square of "+ n +": "+sq);
         System.out.println("Continue ? [1/0]: ");
         rep=in.nextInt();
       }
     }
  }
