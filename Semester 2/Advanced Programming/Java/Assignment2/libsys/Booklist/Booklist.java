package libsys.Booklist;
interface Properties
{
    public void setData(int book_id, int available, String name);
    public void getData();
    public boolean purchase();
    public void increase(int incoming);
    public void return_book();
}
public class Booklist implements Properties
{
    int available, purchased, book_id;
    String name;
    public int ret_id()
    {
        return book_id;
    }
    public void setData(int book_id, int available, String name)
    {
        this.book_id = book_id;
        this.available = available;
        this.name = name;
        purchased = 0;        
    }
    public void getData()
    {
        System.out.println("Book information :");
        System.out.println("------------------------");
        System.out.println("Book name : "+name+".");
        System.out.println("Book ID : "+book_id+".");
        System.out.println("Available : "+available+".");
        System.out.println("Purchased : "+purchased+".");
    }
    public boolean purchase()
    {
        if(available - 1 >= 0)
        {
            purchased++;
            available--;
            return true;
        }
        else
        {
            return false;
        }
    }
    public void increase(int incoming)
    {
        available = available + incoming;
    }
    public void return_book()
    {
        available++;
        purchased--;
    }
}
