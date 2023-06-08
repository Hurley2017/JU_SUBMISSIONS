package libsys.Transaction;
interface Properties
{
    public void setData(int member_id, int book_id);
    public int getMemberId();
    public int getBookId();
    public void changeMember();
}
public class Transaction implements Properties
{
    int book_id;
    String member_id;
    public void setData(int member_id, int book_id)
    {
        this.member_id = String.valueOf(member_id);
        this.book_id = book_id;
    }
    public int getMemberId()
    {
        return Integer.valueOf(member_id);
    }
    public int getBookId()
    {
        return book_id;
    }
    public void changeMember()
    {
        this.member_id = "xxxx";
    }    
}
