import java.util.Scanner;
interface Properties 
{
    public void add_book();
    public void search_book();
    public void view_all_book();
    public void add_member();
    public void search_member();
    public void view_all_member();
    public void issued_book();
    public void return_book();
}
class Main implements Properties
{
    public static void main(String[] Tusher)
    {
        Scanner buffer = new Scanner(System.in);
        int flag_logged_member = 0, member_flag = 0, book_id, member_id, sw, book_count = 1, member_count = 1, transaction_count = 1;
        Booklist[] books = new Booklist[100];
        Memberlist[] members = new Memberlist[100];
        Transaction[] transactions = new Transaction[100];
        boolean con = true;
        for(int i=0; i<100; i++)
        {
            books[i] = new Booklist();
            transactions[i] = new Transaction();
            members[i] = new Memberlist();
        }
        while(con)
        {
            UI_Statements();
            sw = buffer.nextInt();
            switch(sw)
            {
                case 1:
                    int id, number;
                    String book_name;
                    System.out.print("Enter book id :");
                    id = buffer.nextInt();
                    System.out.print("Total number to be added : ");
                    number = buffer.nextInt();
                    System.out.print("Name : ");
                    buffer.next();
                    book_name = buffer.nextLine();
                    books[book_count-1].setData(id, number, book_name);
                    System.out.println("Book successfully added!");
                    book_count++;
                    break;
                case 2:
                    System.out.print("Enter book id : ");
                    book_id = buffer.nextInt();
                    boolean hit = false;
                    for(int i=0; i<book_count; i++)
                    {
                        if(book_id == books[i].ret_id())
                        {
                            System.out.print("How many books to add? ");
                            int more_books = buffer.nextInt();
                            books[i].increase(more_books);
                            hit = true;
                            break;
                        }
                    }
                    if(hit)
                    {
                        System.out.println("Successfully added copies of books.");
                    }
                    else 
                    {
                        System.out.println("Book not found");
                    }
                    hit = false;
                    break;
                case 3:
                    System.out.print("Enter book id : ");
                    book_id = buffer.nextInt();
                    boolean hit2 = false;
                    for(int i=0; i<book_count; i++)
                    {
                        if(book_id == books[i].ret_id())
                        {
                            books[i].getData();
                            hit2 = true;
                            break;
                        }
                    }
                    if(hit2)
                    {
                        System.out.println("Successfully displayed.");
                    }
                    else 
                    {
                        System.out.println("Book not found");
                    }
                    hit2 = false;
                    break;
                case 4:
                    System.out.println("Showing all the books : ");
                    for(int i=0; i<book_count; i++)
                    {
                        books[i].getData();
                    }
                    break;
                case 5:
                    int m_id;
                    String member_name;
                    System.out.print("Enter member id :");
                    m_id = buffer.nextInt();
                    System.out.print("Name : ");
                    buffer.next();
                    member_name = buffer.nextLine();
                    members[member_count-1].setData(m_id, member_name);
                    System.out.println("member successfully added!");
                    member_count++;
                    break;
                case 6:
                    System.out.print("Enter member id : ");
                    member_id = buffer.nextInt();
                    boolean hit3 = false;
                    for(int i=0; i<member_count; i++)
                    {
                        if(member_id == members[i].ret_id())
                        {
                            System.out.print("Displaying member ");
                            members[i].getData();
                            hit3 = true;
                            break;
                        }
                    }
                    if(hit3)
                    {
                        System.out.println("Successfully displayed member.");
                    }
                    else 
                    {
                        System.out.println("member not found");
                    }
                    hit3 = false;
                    break;
                case 7:
                    System.out.print("Member id : ");
                    flag_logged_member = buffer.nextInt();
                    boolean hit4 = false;
                    for(int i=0; i<member_count; i++)
                    {
                        if(flag_logged_member == members[i].ret_id())
                        {
                            member_flag = i;
                            hit4 = true;
                            break;
                        }
                    }
                    if(hit4)
                    {
                        System.out.println("Successfully Logged.");
                    }
                    else 
                    {
                        System.out.println("Invalid member id.");
                        flag_logged_member = 0;
                    }
                    hit4 = false;
                    break;
                case 8:
                    if(flag_logged_member == 0)
                    {
                        System.out.println("Member is not logged in.");
                    }
                    else 
                    {
                        System.out.print("Enter book id : ");
                        book_id = buffer.nextInt();
                        boolean hit5 = false;
                        for(int i=0; i<book_count; i++)
                        {
                            if(book_id == books[i].ret_id())
                            {
                                if(members[member_flag].request_book())
                                {
                                    if(books[i].purchase())
                                    {
                                        System.out.println("Success!");
                                        transactions[transaction_count-1].setData(flag_logged_member, book_id);
                                        transaction_count++;
                                    }
                                    else 
                                    {
                                        System.out.println("Book is not available.");
                                    }
                                }
                                else 
                                {
                                    System.out.println("Cannot borrow book. limit reached.");
                                }
                                break;
                            }
                            hit5  = true;
                        }
                        if(hit5)
                        {
                            System.out.println("Transaction completed");
                        }
                        else 
                        {
                            System.out.println("Book not found");
                        }
                        hit5 = false;
                    }
                    break;
                case 9:
                    if(flag_logged_member == 0)
                    {
                        System.out.println("Member is not logged in.");
                    }
                    else 
                    {
                        System.out.print("Enter book id : ");
                        book_id = buffer.nextInt();
                        boolean hit6 = false;
                        for(int i=0; i<book_count; i++)
                        {
                            if(book_id == books[i].ret_id())
                            {
                                if(members[member_flag].return_book())
                                {
                                    books[i].return_book();
                                    System.out.println("Success!");
                                    for(int j=0; j<transaction_count; j++)
                                    {   
                                        if(transactions[j].getMemberId() == flag_logged_member)
                                        {
                                            transactions[j].changeMember();
                                        }
                                    }
                                    System.out.println("Returned successfully.");
                                }
                                else 
                                {
                                    System.out.println("Cannot return book. none borrowed.");
                                }
                                break;
                            }
                            hit6 = true;
                        }
                        if(hit6)
                        {
                            System.out.println("Transaction completed");
                        }
                        else 
                        {
                            System.out.println("Book not found");
                        }
                        hit6 = false;
                    }
                    break;
                case 10:
                    for(int i=0; i<transaction_count; i++)
                    {
                        System.out.println(transactions[i].getMemberId()+"borrowed "+transactions[i].getBookId());
                    }
                    break;
                case 11:
                    con = false;
                    break;
                default:
                    System.out.println("Invalid input.");
                    break;
            }
        }
        buffer.close();
    }
    static void UI_Statements()
    {
        System.out.println("Choose from the following : ");
        System.out.println("1) Add a book");
        System.out.println("2) Add more copies of a book.");
        System.out.println("3) Display a book");
        System.out.println("4) Display list of books");
        System.out.println("5) Add a member");
        System.out.println("6) View a member");
        System.out.println("7) Login as a member");
        System.out.println("8) Borrow a book");
        System.out.println("9) Return a book");
        System.out.println("10) View all transaction");
        System.out.println("11) Exit");
        System.out.print("Enter your choice : ");
    }
    public void add_book()
    {
        Scanner buffer = new Scanner(System.in);
        int id, number;
        String book_name;
        System.out.print("Enter book id :");
        id = buffer.nextInt();
        System.out.print("Total number to be added : ");
        number = buffer.nextInt();
        System.out.print("Name : ");
        buffer.next();
        book_name = buffer.nextLine();
        books[book_count-1].setData(id, number, book_name);
        System.out.println("Book successfully added!");
        book_count++;
        break;
    }
    public void search_book()
    {

    }
    public void view_all_book()
    {

    }
    public void add_member()
    {

    }
    public void search_member()
    {

    }
    public void view_all_member()
    {

    }
    public void issued_book()
    {

    }
    public void return_book()
    {

    }
}
class Booklist
{
    int available, purchased, book_id;
    String name;
    int ret_id()
    {
        return book_id;
    }
    void setData(int book_id, int available, String name)
    {
        this.book_id = book_id;
        this.available = available;
        this.name = name;
        purchased = 0;        
    }
    void getData()
    {
        System.out.println("Book information :");
        System.out.println("------------------------");
        System.out.println("Book name : "+name+".");
        System.out.println("Book ID : "+book_id+".");
        System.out.println("Available : "+available+".");
        System.out.println("Purchased : "+purchased+".");
    }
    boolean purchase()
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
    void increase(int incoming)
    {
        available = available + incoming;
    }
    void return_book()
    {
        available++;
        purchased--;
    }
}
class Memberlist
{
    int member_id, issued_number_of_books, max_issued_books;
    String name;
    void setData(int member_id, String name)
    {
        this.name = name;
        this.member_id = member_id;
        issued_number_of_books = 0;
        max_issued_books = 20;
    }
    void getData()
    {
        System.out.println("Member information :");
        System.out.println("------------------------");
        System.out.println("Member name : "+name+".");
        System.out.println("Member ID : "+member_id+".");
        System.out.println("Number of issued books : "+issued_number_of_books+".");
        System.out.println("Max issued books : "+max_issued_books+".");   
    }
    int ret_id()
    {
        return member_id;
    }
    boolean request_book()
    {
        if(issued_number_of_books+1 <= max_issued_books)
        {
            issued_number_of_books++;
            return true;
        }
        return false;
    }
    boolean return_book()
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
class Transaction
{
    int book_id;
    String member_id;
    void setData(int member_id, int book_id)
    {
        this.member_id = String.valueOf(member_id);
        this.book_id = book_id;
    }
    int getMemberId()
    {
        return Integer.valueOf(member_id);
    }
    int getBookId()
    {
        return book_id;
    }
    void changeMember()
    {
        this.member_id = "xxxx";
    }
}
