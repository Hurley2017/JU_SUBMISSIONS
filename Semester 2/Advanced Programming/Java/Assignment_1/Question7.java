import java.util.*;
class Main
{
    public static void main(String[] Tusher)
    {
        System.out.println("Question 7 :");
        Scanner buffer = new Scanner(System.in);
        String StudentName;
        int ClassRoll;
        double Score;
        System.out.println("Enter Student name : ");
        StudentName = buffer.nextLine();
        System.out.println("Enter Student roll : ");
        ClassRoll = buffer.nextInt();
        System.out.println("Enter Student Score : ");
        Score = buffer.nextDouble();
        Student S1 = new Student();
        Student S2 = new Student();
        S1.Setters(StudentName, ClassRoll, Score);
        S1.Getters();
        S2 = S1.Copy();
        S2.Getters();
        buffer.close();
    }
}
class Student
{
    String StudentName;
    int ClassRoll;
    double Score;
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
    Student Copy()
    {
        Student Subject = new Student();
        Subject.StudentName = this.StudentName;
        Subject.ClassRoll = this.ClassRoll;
        Subject.Score = this.Score;
        return Subject;
    }
}
