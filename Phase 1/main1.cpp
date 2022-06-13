#include <cstring>
#include <iostream>
using namespace std;

class User //Class 1 User
{
private:
    string name;
    int age;
    int id;
    string password;
    string email;
public:
    static int count;
    static int getcount()//static function
    {
        return count;
    }
    User()//defult constructor
    {
        count++;
        id=count;
        getcount();
        age=0;
        name=password=email=" ";
    }
    User(string n, int a, string e, string p)//constructor passing parameters
    {
        name=n;
        age=a;
        email=e;
        password=p;
    }
    User(const User&u)//copy constructor
    {
        name=u.name;
        age=u.age;
        email=u.email;
        password=u.password;
    }
    void setname(string n)// set name
    {
        name=n;
    }
    void setemail(string e)// set mail
    {
        email=e;
    }
    void setpassword(string p)// set password
    {
        password=p;
    }
    void setage(int a)// set age
    {
        age=a;
    }
    void setid(int i)// set id
    {
        id=i;
    }
    string getname()// get name
    {
        return name;
    }
    string getemail()// get mail
    {
        return email;
    }
    string getpassword()// get password
    {
        return password;
    }
    int getage()// get age
    {
       return age;
    }
    int getid()// get id
    {
       return id;
    }
    friend istream&operator>>(istream&input, User&u) //istream function for class user
    {
        input>>u.name>>u.age>>u.email>>u.password;
        return input;
    }
    friend ostream&operator<<(ostream&output, User&u)//ostream function for class user
    {
        output<<" Name:"<<u.name<<" Age:"<<u.age<<" ID:"<<u.id<<" Email:"<<u.email;
        return output;
    }
    bool operator==(User u2)//equal function for class user
    {
        if(name==u2.name&&age==u2.age&&email==u2.email&&id==u2.id)
            return true;
        else
            return false;
    }
};
int User::count=0; //definition of static variable of class user

class Book //Class 2 Book
{
private:
    string title;
    string isbn;
    string category;
    double avgrate;
    int id;
    User*author;
public:
    static int count;
    static int getcount() //static function
    {
        return count;
    }
    Book() //defult constructor
    {
        title=isbn=category=" ";
        avgrate=0;
        count++;
        id=count;
        getcount();
    }
    Book(string t, string i, string c) //constructor passing parameters
    {
        title=t;
        isbn=i;
        category=c;
    }
    Book(const Book&b) //copy constructor
    {
        title=b.title;
        isbn=b.isbn;
        category=b.category;
    }
    void settitle(string t) //set title
    {
        title=t;
    }
    void setisbn(string i) //set isbn
    {
        isbn=i;
    }
    void setcategory(string c) //set category
    {
        category=c;
    }
    void setid(int d) //set id
    {
        id=d;
    }
    string gettitle() //get title
    {
        return title;
    }
    string getisbn() //get isbn
    {
        return isbn;
    }
    string getcategory() //get category
    {
        return category;
    }
    int getid() //get id
    {
        return id;
    }
    void setauthor(User*a) //set author
    {
        author=new User;
        author->setname(a->getname());
        author->setage(a->getage());
        author->setemail(a->getemail());
        author->setpassword(a->getpassword());
        author->setid(a->getid());
    }
    User getauthor() //get author
    {
        cout<<author->getname()<<author->getage()<<author->getemail()<<author->getpassword()<<author->getid();
    }
    double c=0,sum=0;
    void ratebook(double rate) //function rate book
    {
        sum=sum+rate;
        c++;
        avgrate=sum/c;
    }
    friend istream&operator>>(istream&input, Book&b) //istream function for class book
    {
        input>>b.title>>b.isbn>>b.category;
        return input;
    }
    friend ostream&operator<<(ostream&output, Book&b) //ostream function for class book
    {
        output<<" Title:"<<b.title<<" ISBN:"<<b.isbn<<" ID:"<<b.id<<" Category:"<<b.category<<" Avg Rating:"<<b.avgrate;
        return output;
    }
    bool operator==(Book b2) //equal function for class book
    {
        if(title==b2.title&&isbn==b2.isbn&&category==b2.category&&id==b2.id&&author==b2.author)
            return true;
        else
            return false;
    }
};
int Book::count=0; //definition of static variable of class book

int main()
{
    // Class 1 User
    User u1,u2;
    cout<<"Let's add a user"<<endl<<"Enter the user information in this order"<<endl;
    cout<<"Name Age Email Password"<<endl;
    cin>>u1;//output the class of user 1
    cout<<endl<<"========user "<<u1.getid()<<" info========"<<endl;
    cout<<u1<<endl;
    cout<<"========================================"<<endl<<endl;
    cout<<"Let's add another user"<<endl<<"Enter the user information in this order"<<endl;
    cout<<"Name Age Email Password"<<endl;
    cin>>u2; //input the class of user 2
    cout<<endl<<"========user "<<u2.getid()<<" info========"<<endl;
    cout<<u2<<endl; //output the class of user 2
    cout<<"========================================"<<endl<<endl;
    if (u1==u2) //print the result of equal function for class user
        cout<<"Data of user 1 equal Data of user 2"<<endl;
    else
        cout<<"Data of user 1 not equal Data of user 2"<<endl;
    cout<<"========================================"<<endl<<endl;

    //Class 2 Book
    Book b1,b2;
    cout<<"Let's add a book"<<endl<<"Enter the book information in this order"<<endl;
    cout<<"Title ISBN Category"<<endl;
    cin>>b1; //input the class of book 1
    cout<<"========book "<<b1.getid()<<" info========"<<endl;
    cout<<b1<<endl; //output the class of book 1
    cout<<"========================================"<<endl<<endl;
    cout<<"Let's add another book"<<endl<<"Enter the book information in this order"<<endl;
    cout<<"Title ISBN Category"<<endl;
    cin>>b2; //input the class of book 2
    cout<<"========book "<<b2.getid()<<" info========"<<endl;
    cout<<b2<<endl; //output the class of book 2
    cout<<"========================================"<<endl<<endl;
    double r1,r2,r3;
    cout<<"Let's assign an author for the first book,set the first user as an author"<<endl;
    cout<<"Let's rate the first book with 3 and 4 ratings and print the book info"<<endl;
    cin>>r1; // input the first rate of the first book
    cin>>r2; // input the second rate of the first book
    b1.ratebook(r1);
    b1.ratebook(r2);
    cout<<"========book "<<b1.getid()<<" info========"<<endl;
    cout<<b1<<endl<<endl; //output the first Avg rating of the first book
    cout<<"========user "<<u1.getid()<<" info========"<<endl;
    cout<<u1<<endl; //output the first author of the first book
    cout<<"========================================"<<endl<<endl;
    cout<<"Let's add a new rating for b1 with 5 and print the book info"<<endl;
    cin>>r3; // input the third rate of the first book
    b1.ratebook(r3);
    cout<<"========book "<<b1.getid()<<" info========"<<endl;
    cout<<b1<<endl<<endl; //output the first Avg rating of the first book
    cout<<"========user "<<u1.getid()<<" info========"<<endl;
    cout<<u1<<endl; //output the first author of the first book
    cout<<"========================================"<<endl<<endl;
    cout<<"========================================"<<endl<<endl;

    return 0;
}




















































































