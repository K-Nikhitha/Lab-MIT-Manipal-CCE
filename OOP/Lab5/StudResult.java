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

class Result
{
    int SubjMarks[][]= new int[3][3];
    int TotMarks[]= new int[3];
    Scanner in = new Scanner(System.in);
    void getInfo()
    {

        System.out.println("Enter Marks of each student in 3 subjects: ");
        for(int i=0; i<3; i++)
        {
            System.out.println("Enter Marks of Student "+ (i+1)+ ": ");
            for(int j=0; j<3; j++)
            {
                System.out.println("Subject "+ (j+1)+": ");
                SubjMarks[i][j]= in.nextInt();
            }
        }
    }
    void calcTot()
    {
        for(int i=0; i<3; i++)
            TotMarks[i]=0;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                TotMarks[i]+=SubjMarks[i][j];
            }
        }
    }
    void HighTot()
    {
        int large, roll;
        roll=0;
        large= TotMarks[0];
        for(int i=0; i<3; i++)
        {
            if(TotMarks[i]>=large)
            {
                large=TotMarks[i];
                roll=i+1;
            }
        }
        System.out.println("Highest Total Marks: "+ large);
        System.out.println("Roll No of Student who secured it: " + roll + "\n");
    }
    void SubTop()
    {
      int large, rn;
      rn = 0;
      for(int i=0; i<3; i++)
      {
        large=SubjMarks[0][i];
        for(int j=0; j<3; j++)
        {
          if(large<=SubjMarks[j][i])
          {
            large=SubjMarks[j][i];
            rn=j+1;
          }
        }
        System.out.println("Highest Marks in Subject "+(i+1)+": "+ large + "\n");
        System.out.println("Roll No of Student who secured it: "+ rn +"\n");
      }
    }

}
public class StudResult
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        Result obj= new Result();
        obj.getInfo();
        obj.calcTot();
        obj.SubTop();
        obj.HighTot();

    }

}
