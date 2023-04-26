import java.util.*;

class Main
{    public static void main(String[] Tusher)
    {
        String instrucor_name, title, authorname, publisher, course_name, garbage;
        long phone_number;
        Scanner buffer = new Scanner(System.in);
        Instructor i = new Instructor();
        System.out.println("\nSetting data for Instructor Class : ");
        System.out.print("Enter instructor_name : ");
        instrucor_name = buffer.nextLine();
        System.out.print("Enter the phone number : ");
        phone_number = buffer.nextLong();
        garbage = buffer.nextLine();
        i.setData(instrucor_name, phone_number);
        System.out.println("\nPrinting from the Instructor Class : ");
        i.getData();
        Textbook t = new Textbook();
        System.out.println("\n\nSetting data for Textbook Class : ");
        System.out.print("Enter the title of the text book : ");
        title = buffer.nextLine();
        System.out.print("Enter the name of the author : ");
        authorname = buffer.nextLine();
        System.out.print("Enter the name of the publisher : ");
        publisher = buffer.nextLine();
        t.setData(title, authorname, publisher);
        System.out.println("\nPrinting from the Textbook Class : ");
        t.getData();
        Courses c = new Courses();
        System.out.println("\n\nSetting data of Courses Class : ");
        System.out.print("Enter the name of the course : ");
        course_name = buffer.nextLine();
        c.setData(course_name, i, t);
        System.out.println("\nPrinting from the Courses Class : ");
        c.getData();
        System.out.println(garbage);
        buffer.close();
    }
}
class Instructor
{
    String instructor_name;
    long phone_number;
    Instructor()
    {
        instructor_name = "";
        phone_number = 0;
    }
    Instructor(Instructor Object)
    {
        this.instructor_name = Object.instructor_name;
        this.phone_number = Object.phone_number;
    }
    void setData(String instructor_name, long phone_number)
    {
        this.instructor_name = instructor_name;
        this.phone_number = phone_number;
    }
    void getData()
    {
        System.out.println("The instuctor name is "+instructor_name+".");
        System.out.println("The phone number of the instructor is "+phone_number+".");
    }
}
class Textbook
{
    String title, authorname, publisher;
    Textbook()
    {
        title = "";
        authorname = "";
        publisher = "";
    }
    Textbook(Textbook Object)
    {
        this.authorname = Object.authorname;
        this.publisher = Object.publisher;
        this.title = Object.title;
    }
    void setData(String title, String authorname, String publisher)
    {
        this.authorname = authorname;
        this.publisher = publisher;
        this.title = title;
    }
    void getData()
    {
        System.out.println("The author's name is "+authorname+".");
        System.out.println("The publisher's name is "+publisher+".");
        System.out.println("The title of the book is "+title+".");
    }
}  
class Courses
{
    String course_name;
    Instructor i;
    Textbook t;
    void setData(String course_name, Instructor i, Textbook t)
    {
        this.course_name = course_name;
        this.i = new Instructor(i);
        this.t = new Textbook(t);
    }
    void getData()
    {
        System.out.println("The name of thew course is "+course_name+".");
        i.getData();
        t.getData();
    }
}