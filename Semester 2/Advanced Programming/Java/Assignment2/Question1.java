import java.util.*;
class Main
{
    public static void main(String[] Tusher)
    {
        Console console = new Console();
        Customer c = new Customer();
        console.out(c.get_credit_limit());
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
    void out(String Object)
    {
        System.out.println(Object);
    }
    void out(int Object)
    {
        System.out.println(Object);
    }
    void out(double Object)
    {
        System.out.println(Object);
    }
    void out(long Object)
    {
        System.out.println(Object);
    }
    void out(boolean Object)
    {
        System.out.println(Object);
    }
}