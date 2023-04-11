//Question 8
import java.util.*;
class Main
{
    public static void main(String[] Tusher)
    {
        System.out.println("Question 7 :");
        Scanner buffer = new Scanner(System.in);
        // String StudentName;
        // int ClassRoll;
        // double Score;
        // System.out.println("Enter Student name : ");
        // StudentName = buffer.nextLine();
        // System.out.println("Enter Student roll : ");
        // ClassRoll = buffer.nextInt();
        // System.out.println("Enter Student Score : ");
        // Score = buffer.nextDouble();
        Student one = new Student();
        one.Getters();
        buffer.close();
    }
}
class Student
{
    String StudentName;
    int ClassRoll;
    double Score;
    Student(int ClassRoll)
    {
        this.StudentName = "";
        this.ClassRoll = ClassRoll;
        this.Score = -1;
    }
    Student(String StudentName, int ClassRoll)
    {
        this.StudentName = StudentName;
        this.ClassRoll = ClassRoll;
        this.Score = -1;
    }
    Student(String StudentName, int ClassRoll,  double Score)
    {
        this.StudentName = StudentName;
        this.ClassRoll = ClassRoll;
        this.Score = Score;
    }
    Student()
    {
        this.StudentName = "";
        this.ClassRoll = -1;
        this.Score = -1;
    }
    Student(Student Object)
    {
        this.StudentName = Object.StudentName;
        this.ClassRoll = Object.ClassRoll;
        this.Score = Object.Score;
    }
    void Setters(String StudentName, int ClassRoll, double Score)
    {
        this.StudentName = StudentName;
        this.ClassRoll = ClassRoll;
        this.Score = Score;
    }
    void Getters()
    {
        if(this.StudentName == "")
        {
            System.out.println("Name of the student is not provided!");
        }
        else
        {
            System.out.println("Name of the student is - " + StudentName + ".");
        }
        if(this.ClassRoll == -1)
        {
            System.out.println("Roll of the student is not provided!");
        }
        else
        {
            System.out.println("Roll of the student is - " + ClassRoll + ".");
        }
        if(this.Score == -1)
        {
            System.out.println("Score of the student is not provided!");
        }
        else
        {
            System.out.println("Score of the student is - " + Score + ".");
        }
    }
    void Copy(Student Subject)
    {
        Subject.StudentName = this.StudentName;
        Subject.ClassRoll = this.ClassRoll;
        Subject.Score = this.Score;
    }
}
