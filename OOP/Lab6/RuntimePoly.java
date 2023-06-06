/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab6;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */
 class Bike
 {
   int speedlimit;
   Bike()
   {
     speedlimit=100;
   }
   void run()
   {
     System.out.println("Speed Limit: "+ speedlimit);
   }
 }
 class Splendor extends Bike
 {
   int speedlimit;
   Splendor()
   {
     speedlimit=85;
   }
   void run()
   {
     System.out.println("Speed Limit: "+ speedlimit);
   }
 }
 public class RuntimePoly
 {
   public static void main(String[] args)
   {
     Bike obj= new Splendor();
     obj.run();
   }
 }
