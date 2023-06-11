// Design a student class with roll, name, and score. 
// Support must be there to set the score. 
// Score is non-negative and cannot exceed 100. 
// For invalid score an exception has to be raised. 
// Users of the set score method will decide about the measures to deal with the exception.

import java.util.Scanner;

class Main 
{
    public static void main(String[] Tusher)
    {
        Scanner buffer = new Scanner(System.in);

        String name;
        int roll;
        double score;
        
        System.out.print("Enter name : ");
        name = buffer.nextLine(); // Taking the name as input
        
        System.out.print("Roll : ");
        roll = buffer.nextInt(); // Taking the roll as input
        
        System.out.print("Score : ");
        score = buffer.nextDouble(); // Taking the score as input
        
        Student s1 = new Student(); // creating an object of Student class
        
        // try and catch block to handle exception
        try
        {
            s1.setData(name, roll, score);
            s1.getData();
        }
        // catch block to handle thrown exception
        catch(Exception e)
        {   
            System.out.println(e.getMessage()); // printing the exception message
        }
        // this finally block is executed whether the exception is thrown or not
        finally
        {
            buffer.close();
        }
    }
}
class Student
{
    // instance variables
    String name;
    int roll;
    double score;

    // method to set data
    void setData(String name, int roll, double score)
    {
        if(score > 100 || score < 0)
        {
            //throwing exception
            throw new ArithmeticException("score cannot be less than zero or greater than 100");
        }
        this.name = name;
        this.roll = roll;
        this.score = score;
    }

    // method to get data
    void getData()
    {
        System.out.println("Name : "+name);
        System.out.println("Roll : "+roll);
        System.out.println("Score : "+score);
    }
}
