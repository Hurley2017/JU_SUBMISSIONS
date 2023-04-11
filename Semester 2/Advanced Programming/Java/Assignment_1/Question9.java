//Question 9
import java.util.*;
class Main 
{
    public static void main(String[] Tusher)
    {
        double NewInterestRate;
        int year;
        Scanner buffer = new Scanner(System.in);
        BankAcct One = new BankAcct(44152221, 500);
        One.Getters();
        System.out.print("Enter total number of year : ");
        year = buffer.nextInt();
        System.out.println("The interest rate is " + One.GetInterst());
        System.out.println("The total interest is " + One.calculateInterest(year));
        System.out.print("Enter new interest rate : ");
        NewInterestRate = buffer.nextDouble();
        One.ChangeInterest(NewInterestRate);
        System.out.println("The interest rate is " + One.GetInterst());
        System.out.println("The total interest is " + One.calculateInterest(year));
        buffer.close();
    }
}
class BankAcct
{
    long AccountNumber;
    double AccountBalance;
    double InterestRate;
    BankAcct(long AccountNumber, double AccountBalance)
    {
        this.AccountNumber = AccountNumber;
        this.AccountBalance = AccountBalance;
        this.InterestRate = 2.7;
    }
    void Setters(long AccountNumber, double AccountBalance)
    {
        this.AccountNumber = AccountNumber;
        this.AccountBalance = AccountBalance;
        this.InterestRate = 2.7;
    }
    void Getters()
    {
        System.out.println("Account Number is - " + AccountNumber);
        System.out.println("Account Balance is - " + AccountBalance);
        System.out.println("Interest Rate is - " + InterestRate);
    }
    double GetInterst()
    {
        return InterestRate;
    }
    void ChangeInterest(double NewInterestRate)
    {
        this.InterestRate = NewInterestRate;
    }
    double calculateInterest(int Month)
    {
        return Month*(AccountBalance/100)*InterestRate;
    }
}
