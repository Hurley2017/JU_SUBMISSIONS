// Design and implement Student class with roll, name and score as attributes. 
// It will have methods to set attributes ( attribute values passed as arguments), display the attributes, copy ( that copies the content of invoking object to another object passed as argument ). 
// Verify that methods are working properly.

import java.util.*;

class Main
{
    public static void main(String[] Tusher)
    {
        Scanner buffer = new Scanner(System.in); // Scanner object

        String StudentName;
        int ClassRoll;
        double Score;
    
        // Taking input for S1.
        System.out.println("Enter Student name : ");
        StudentName = buffer.nextLine();  
        
        System.out.println("Enter Student roll : ");
        ClassRoll = buffer.nextInt();
        
        System.out.println("Enter Student Score : ");
        Score = buffer.nextDouble();
        
        Student S1 = new Student(); // Creating object S1.
        Student S2 = new Student(); // Creating object S2.
        
        S1.Setters(StudentName, ClassRoll, Score); // Setting values for S1.
        S1.Getters(); // Getting values for S1.
         
        S1.Copy(S2); // Copying values from S1 to S2.
        S2.Getters(); // Getting values for S2.
        
        buffer.close(); // Closing Scanner object.
    }
}
class Student
{
    // Class variables.
    String StudentName;
    int ClassRoll;
    double Score;

    // Setters and Getters.
    void Setters(String StudentName, int ClassRoll, double Score)
    {
        this.StudentName = StudentName;
        this.ClassRoll = ClassRoll;
        this.Score = Score;
    }
    void Getters()
    {
        System.out.println("Name of the student is - " + StudentName + ".");
        System.out.println("Roll of the student is - " + ClassRoll + ".");
        System.out.println("Score of the student is - " + Score + ".");
    }

    // Copy method that copies content of the invoking object to the passed object.
    void Copy(Student Subject)
    {
        Subject.StudentName = this.StudentName;
        Subject.ClassRoll = this.ClassRoll;
        Subject.Score = this.Score;
    }
}
