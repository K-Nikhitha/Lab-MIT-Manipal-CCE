/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab2;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */
public class TernaryOp {
    public static void main(String[] args) {
    int a , b, c;
    int sm, la;
    Scanner in = new Scanner(System.in);
    System.out.println("Enter number 1: ");
    a=in.nextInt();
    System.out.println("Enter number 2: ");
    b=in.nextInt();
    System.out.println("Enter number 3: ");
    c=in.nextInt();
    la= a>b ? (a>c ? a :c) : (b>c ? b : c);
    sm= a<b ? (a<c ? a :c) : (b<c ? b : c);
    System.out.println("Largest: "+ la);
    System.out.println("Smallest: "+ sm);
}
}
