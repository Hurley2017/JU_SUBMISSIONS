import javax.swing.plaf.synth.SynthSeparatorUI;

class Main 
{
    public static void main(String[] Tusher)
    {
        
    }
}
class Common_Properties
{
    String name, street, city, state, email_id;
    int premise_number, pin, phone_number;
}
class Students extends Common_Properties
{
    int roll;
    String course_of_study;
    void setData(String[] string_package, int[] int_package)
    {
        name = string_package[0];
        street = string_package[1];
        city = string_package[2];
        state = string_package[3];
        email_id = string_package[4];
        course_of_study = string_package[5];
        premise_number = int_package[0];
        pin = int_package[1];
        phone_number = int_package[2];
        roll = int_package[3];
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
}
class Faculty extends Common_Properties
{
    int emp_id;
    String department, specialisation;
    void setData(String[] string_package, int[] int_package)
    {
        name = string_package[0];
        street = string_package[1];
        city = string_package[2];
        state = string_package[3];
        email_id = string_package[4];
        department = string_package[5];
        specialisation = string_package[6];
        premise_number = int_package[0];
        pin = int_package[1];
        phone_number = int_package[2];
        emp_id = int_package[3];
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