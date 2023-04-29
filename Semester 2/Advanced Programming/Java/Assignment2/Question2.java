class Main 
{
    public static void main(String[] Tusher)
    {
        
    }
    void takeS_input()
    {

    }
}
class Common_Properties
{
    public String name, street, city, state, email_id;
    public int premise_number, pin, phone_number;
}
class Students extends Common_Properties
{
    int roll;
    String course_of_study;
    void setData(int roll, String course_of_study, Common_Properties s)
    {
        this.name = s.name;
        this.street = s.street;
        this.city = s.city;
        this.state = s.state;
        this.email_id = s.email_id;
        this.course_of_study = course_of_study;
        this.premise_number = s.premise_number;
        this.pin = s.pin;
        this.phone_number = s.phone_number;
        this.roll = roll;
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
    void setData(int emp_id, String department, String specialisation,  Common_Properties f)
    {
        this.name = f.name;
        this.street = f.street;
        this.city = f.city;
        this.state = f.state;
        this.email_id = f.email_id;
        this.department = department;
        this.specialisation = specialisation;
        this.premise_number = f.premise_number;
        this.pin = f.pin;
        this.phone_number = f.phone_number;
        this.emp_id = emp_id;
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