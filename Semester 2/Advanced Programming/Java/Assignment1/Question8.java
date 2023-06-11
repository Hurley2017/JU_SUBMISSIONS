// Add constructors in the Student class of earlier problems so that objects can be created with 
// i) roll only, 
// ii) roll and name only, 
// iii) roll, name, and score, 
// iv) no value. 
// Also include a copy constructor. Check whether constructors are working or not. 
// Verify, copy constructors result in deep copy or not.

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
        Student S3; // Initializing object S3.
        Student S4; // Initializing object S4.
        Student S5; // Initializing object S5.
        Student S6; // Initializing object S6.
        
        System.out.println("S1 : ");
        S1.Setters(StudentName, ClassRoll, Score); // Setting values for S1.
        S1.Getters(); // Getting values for S1.
        
        System.out.println("S2 : ");
        S1.Copy(S2); // Copying values from S1 to S2.
        S2.Getters(); // Getting values for S2.

        System.out.println("S3 : Creating S3 with only ClassRoll.");
        S3 = new Student(ClassRoll); // Creating object S3 only with ClassRoll.
        S3.Getters(); // Getting values for S3.

        System.out.println("S4 : Creating S4 with ClassRoll and StudentName.");
        S4 = new Student(ClassRoll, StudentName); // Creating object S4 with ClassRoll and StudentName.
        S4.Getters(); // Getting values for S4.

        System.out.println("S5 : Creating S5 with ClassRoll, StudentName and Score.");
        S5 = new Student(ClassRoll, StudentName, Score); // Creating object S5 with ClassRoll, StudentName and Score.
        S5.Getters(); // Getting values for S5.

        System.out.println("S6 : Creating S6 with S5 using copy constructor.");
        S6 = new Student(S5); // Creating object S6 with S5 using copy constructor.
        S6.Getters(); // Getting values for S6.
        
        // Deleting S5 to check if S6 is a deep copy or not.
        System.out.println("Deleting S5 and printing S6 to check if S6 is a deep copy or not.");

        System.out.println("S6 : ");
        S6.Getters(); // Getting values for S6.

        buffer.close(); // Closing Scanner object.
    }
}
class Student
{
    // Class variables.
    String StudentName;
    int ClassRoll;
    double Score;

    // Constructors.
    // Constructor Overloading
    Student()
    {
        StudentName = "";
        ClassRoll = 0;
        Score = 0;
    }
    Student(int ClassRoll)
    {
        this.ClassRoll = ClassRoll;
        this.StudentName = "";
        this.Score = 0;
    }
    Student(int ClassRoll, String StudentName)
    {
        this.ClassRoll = ClassRoll;
        this.StudentName = StudentName;
        this.Score = 0;
    }
    Student(int ClassRoll, String StudentName, double Score)
    {
        this.ClassRoll = ClassRoll;
        this.StudentName = StudentName;
        this.Score = Score;
    }
    // Copy constructor.
    Student(Student Subject)
    {
        this.StudentName = Subject.StudentName;
        this.ClassRoll = Subject.ClassRoll;
        this.Score = Subject.Score;
    }

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