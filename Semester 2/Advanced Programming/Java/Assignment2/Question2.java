import java.util.Scanner;
class Main 
{
    public static void main(String[] Tusher)
    {
        int sw;
        boolean con = true;
        Scanner buffer = new Scanner(System.in);
        Common_Properties details = new Common_Properties();
        System.out.print("Enter your name : ");
        details.name = buffer.nextLine();
        System.out.println("Information - ");
        System.out.print("Phone Number : ");
        details.phone_number = buffer.nextInt();
        buffer.nextLine();
        System.out.print("Email ID : ");
        details.email_id = buffer.nextLine();
        System.out.println("Address - ");
        System.out.print("State : ");
        details.state = buffer.nextLine();
        System.out.print("City : ");
        details.city = buffer.nextLine();
        System.out.print("Pin : ");
        details.pin = buffer.nextInt();
        System.out.print("Premise_number : ");
        details.premise_number = buffer.nextInt();
        buffer.nextLine();
        System.out.print("Street : ");
        details.street = buffer.nextLine();
        System.out.println("Choose from the following : ");
        System.out.println("1) Student");
        System.out.println("2) Teacher");
        System.out.print("Enter choice : ");
        sw = buffer.nextInt();
        while(con)
        {
            switch(sw)
            {
                case 1:
                    Students s1 = new Students();
                    System.out.print("Enter roll : ");
                    s1.roll = buffer.nextInt();
                    buffer.nextLine();
                    System.out.print("Course of Study : ");
                    s1.course_of_study = buffer.nextLine();
                    s1.setData(details);
                    System.out.println("-----------------------");
                    System.out.println("Displaying : ");
                    s1.getData();
                    con = false;
                    break;
                case 2:
                    Faculty member = new Faculty();
                    System.out.print("Enter roll : ");
                    member.emp_id = buffer.nextInt();
                    buffer.nextLine();
                    System.out.print("Specialisation : ");
                    member.specialisation = buffer.nextLine();
                    System.out.print("Department : ");
                    member.department = buffer.nextLine();
                    member.setData(details);
                    System.out.println("-----------------------");
                    System.out.println("Displaying : ");
                    member.getData();
                    con = false;
                    break;
                default:
                    System.out.println("Invalid choice!");
                    break;
            }
        }
        buffer.close();
    }
}
class Common_Properties
{
    public String name, street, city, state, email_id;
    public int premise_number, pin, phone_number;
}
class Students extends Common_Properties
{
    public int roll;
    public String course_of_study;
    void setData(Common_Properties s)
    {
        this.name = s.name;
        this.street = s.street;
        this.city = s.city;
        this.state = s.state;
        this.email_id = s.email_id;
        this.premise_number = s.premise_number;
        this.pin = s.pin;
        this.phone_number = s.phone_number;
    }
    void getData()
    {
        System.out.println("Student Information : ");
        System.out.println("----------------------");
        System.out.println("Name : "+name);
        System.out.println("Phone Number : "+phone_number);
        System.out.println("Email : "+email_id);
        System.out.println("Course of Study : "+course_of_study);
        System.out.println("Roll : "+ roll);
        System.out.println("Address Information");
        System.out.println("-------------------");
        System.out.println("Premise Number : "+premise_number);
        System.out.println("Street : "+street);
        System.out.println("City : "+city);
        System.out.println("State : "+state);
        System.out.println("Pin : "+pin);
    }
    void changeAddress(int index, int[] int_package)
    {
        //try if else then change the data!
    }
    void changeAddress(int index, String[] string_package)
    {

    }
}
class Faculty extends Common_Properties
{
    int emp_id;
    String department, specialisation;
    void setData(Common_Properties f)
    {
        this.name = f.name;
        this.street = f.street;
        this.city = f.city;
        this.state = f.state;
        this.email_id = f.email_id;
        this.premise_number = f.premise_number;
        this.pin = f.pin;
        this.phone_number = f.phone_number;
    }
    void getData()
    {
        System.out.println("Faculty Information : ");
        System.out.println("----------------------");
        System.out.println("Name : "+name);
        System.out.println("Phone Number : "+phone_number);
        System.out.println("Email : "+email_id);
        System.out.println("Department : "+department);
        System.out.println("Specialisation : "+specialisation);
        System.out.println("Employee ID : "+emp_id);
        System.out.println("Address Information");
        System.out.println("-------------------");
        System.out.println("Premise Number : "+premise_number);
        System.out.println("Street : "+street);
        System.out.println("City : "+city);
        System.out.println("State : "+state);
        System.out.println("Pin : "+pin);
    }
}