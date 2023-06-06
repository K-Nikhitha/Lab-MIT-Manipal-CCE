/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab8;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */
 interface sports
 {
   Scanner in = new Scanner(System.in);
   static String team = "India";
   void getNumberOfGoals();
   void dispTeam();
 }
 class Hockey implements sports
 {
   int goals;
   public void getNumberOfGoals()
   {
     System.out.println("Enter the number of goals in Hockey: ");
     goals = in.nextInt();
   }
   public void dispTeam()
   {
     System.out.println("Hockey Team: "+team);
     System.out.println("Number of Goals: "+goals);
   }
 }
 class Football implements sports
 {
   int goals;
   public void getNumberOfGoals()
   {
     System.out.println("Enter the number of goals in Football: ");
     goals = in.nextInt();
   }
   public void dispTeam()
   {
     System.out.println("Football Team: "+team);
     System.out.println("Number of Goals: "+goals);
   }
 }

 public class SportsInterface
 {
   public static void main(String args[])
   {
     sports s = new Hockey();
     s.getNumberOfGoals();
     s.dispTeam();
     s = new Football();
     s.getNumberOfGoals();
     s.dispTeam();
   }
 }
