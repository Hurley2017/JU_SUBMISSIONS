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
        name = buffer.nextLine();
        System.out.print("Roll : ");
        roll = buffer.nextInt();
        System.out.print("Score : ");
        score = buffer.nextDouble();
        Student s1 = new Student();
        try
        {
            s1.setData(name, roll, score);
            s1.getData();
        }
        catch(Exception e)
        {   
            System.out.println(e.getMessage());
        }
        finally
        {
            buffer.close();
        }
    }
}
class Student
{
    String name;
    int roll;
    double score;
    Student()
    {
        name = "";
        roll = -1;
        score = 0.0;
    }
    void setData(String name, int roll, double score)
    {
        if(score > 100 || score < 0)
        {
            throw new ArithmeticException("score cannot be less that zero or greater than 100");
        }
        this.name = name;
        this.roll = roll;
        this.score = score;
    }
    void getData()
    {
        System.out.println("Name : "+name);
        System.out.println("Roll : "+roll);
        System.out.println("Score : "+score);
    }
}
