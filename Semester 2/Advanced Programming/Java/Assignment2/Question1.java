import java.util.*;
class Main
{
    static void SystemClear()
    {
        System.out.print("\033[H\033[2J");  
        System.out.flush();  
    }
    static void UI_Statements()
    {
        Console print = new Console();
        print.outln("Choose from the following : ");
        print.outln("1) Bank account information");
        print.outln("2) Check Credit Limit ");
        print.outln("3) Check Current Loan Amount ");
        print.outln("4) Update Kyc Details ");
        print.outln("5) Apply for Loan ");
        print.outln("6) Clear Screen ");
        print.outln("7) Exit");
        print.out("Choose a number : ");
    }
    public static void main(String[] Tusher)
    {
        Console print = new Console();
        int choice;
        String cust_name, clear;
        long cust_id, phone_number, loan_amt;
        boolean special, whilecon=true;
        Scanner buffer = new Scanner(System.in);
        Customer c;
        print.out("Enter the name of the customer : ");
        cust_name = buffer.nextLine();
        print.out("Enter the customer id : ");
        cust_id = buffer.nextLong();
        print.out("Enter the phone number of the customer : ");
        phone_number = buffer.nextLong();
        clear = buffer.nextLine();
        print.out("Is this customer a VIP? [Y for yes, any other key for no]");
        clear = buffer.nextLine();
        if(clear.equals("Y"))
        {
            special = true;
        }
        else
        {
            special = false;
        }
        c = new Customer(cust_name, cust_id, phone_number, special);
        SystemClear();
        while(whilecon)
        {
            UI_Statements();
            choice = buffer.nextInt();
            switch(choice)
            {
                case 1:
                    c.get_cust_info();
                    break;
                case 2:
                    print.outln("Credit Limit is : "+ c.get_credit_limit()+".");
                    break;
                case 3:
                    print.outln("Current Loan Ammount is : "+c.get_cur_loan_amt()+".");
                    break;
                case 4:
                    clear = buffer.nextLine();
                    print.out("Enter New Name : ");
                    cust_name = buffer.nextLine();
                    print.out("Enter New Phone Number : ");
                    phone_number = buffer.nextLong();
                    c.update_kyc(cust_name, phone_number);
                    break;
                case 5:
                    print.out("Enter Loan Amount : ");
                    loan_amt = buffer.nextLong();
                    if(c.take_loan(loan_amt))
                    {
                        print.outln("Loan sanctioned!!");
                    }
                    else 
                    {
                        print.outln("Application Rejected!!");
                    }
                    break;
                case 6:
                    SystemClear();
                    break;
                case 7:
                    whilecon = false;
                    break;
                default:
                    print.outln("Invalid Choice!");
                    break;
            }
        }
        buffer.close();
    }
}
class Customer
{
    private String cust_name;
    private long cust_id, phone_number;
    private double cur_loan_amt, credit_limit;
    private boolean special;
    Customer()
    {
        cust_name = "";
        cust_id = -1;
        phone_number = -1;
        cur_loan_amt = 0;
        credit_limit = 500000;
        special = false;
    }
    Customer(String cust_name, long cust_id, long phone_number, boolean special)
    {
        this.cust_name = cust_name;
        this.cust_id = cust_id;
        this.phone_number = phone_number;
        this.special = special;
        if(special)
        {
            credit_limit = 1000000;
        }
        else
        {
            credit_limit = 500000;
        }
        cur_loan_amt = 0;
    }
    void get_cust_info()
    {
        Console print = new Console();
        if(special)
        {
            print.outln("This is a  VIP Customer : ");
        }
        print.outln("Customer ID : "+cust_id+".");
        print.outln("Name of the customer is : '" + cust_name + "'.");
        print.outln("Phone number of the customer is : "+phone_number+".");
    }
    void update_kyc(String new_cust_name, long new_phone_number)
    {
        this.cust_name = new_cust_name;
        this.phone_number = new_phone_number;
        System.out.println("Details updated!");
    }
    double get_cur_loan_amt()
    {
        return cur_loan_amt;
    }
    double get_credit_limit()
    {
        return credit_limit;
    }
    double seek_loan_amt()
    {
        return credit_limit - cur_loan_amt;
    }
    boolean take_loan(double seek_amt)
    {
        if(seek_amt + cur_loan_amt >= credit_limit)
        {
            return false;
        }
        else
        {
            cur_loan_amt = cur_loan_amt + seek_amt;
            credit_limit = credit_limit - seek_amt;
            return true;
        }
    }
}
class Console
{
    void outln()
    {
        System.out.println("");
    }
    void outln(String Object)
    {
        System.out.println(Object);
    }
    void outln(int Object)
    {
        System.out.println(Object);
    }
    void outln(double Object)
    {
        System.out.println(Object);
    }
    void outln(long Object)
    {
        System.out.println(Object);
    }
    void outln(boolean Object)
    {
        System.out.println(Object);
    }
    void out(String Object)
    {
        System.out.print(Object);
    }
    void out(int Object)
    {
        System.out.print(Object);
    }
    void out(double Object)
    {
        System.out.print(Object);
    }
    void out(long Object)
    {
        System.out.print(Object);
    }
    void out(boolean Object)
    {
        System.out.print(Object);
    }
}