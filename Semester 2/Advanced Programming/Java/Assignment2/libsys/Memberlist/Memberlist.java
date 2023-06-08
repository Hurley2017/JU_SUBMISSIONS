package libsys.Memberlist;
interface Properties
{
    public void setData(int member_id, String name);
    public void getData();
    public int ret_id();
    public boolean request_book();
    public boolean return_book();
}
public class Memberlist implements Properties
{
    int member_id, issued_number_of_books, max_issued_books;
    String name;
    public void setData(int member_id, String name)
    {
        this.name = name;
        this.member_id = member_id;
        issued_number_of_books = 0;
        max_issued_books = 20;
    }
    public void getData()
    {
        System.out.println("Member information :");
        System.out.println("------------------------");
        System.out.println("Member name : "+name+".");
        System.out.println("Member ID : "+member_id+".");
        System.out.println("Number of issued books : "+issued_number_of_books+".");
        System.out.println("Max issued books : "+max_issued_books+".");   
    }
    public int ret_id()
    {
        return member_id;
    }
    public boolean request_book()
    {
        if(issued_number_of_books+1 <= max_issued_books)
        {
            issued_number_of_books++;
            return true;
        }
        return false;
    }
    public boolean return_book()
    {
        if(issued_number_of_books == 0)
        {
            return false;
        }
        else
        {
            issued_number_of_books--;
            return true;
        }
    }    
}
