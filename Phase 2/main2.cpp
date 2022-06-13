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
    static int getcount() //static function
    {
        return count;
    }
    void setname(string n)// set name
    {
        name=n;
    }
    void setemail(string e)// set mail
    {
        email=e;
    }
    void setpass(string p)// set password
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
    string getpass()// get password
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
    friend ostream&operator<<(ostream&output, User&u)//ostream function for class user
    {
        output<<"user "<<u.id<<" information"<<endl;
        output<<" Name: "<<u.name<<" Age: "<<u.age<<" ID: "<<u.id<<" Email: "<<u.email;
        return output;
    }
};
int User::count=0; //definition of static variable of class user

class UserList
{
private:
     User*users;
     int capacity;
     int usersCount;
public:
    int n=0;
    UserList(int c)
    {
       capacity=c;
       users=new User[c];
       for(int i=0;i<c;i++)
       {
           users->setage(0);
           users->setid(0);
           users->setname(" ");
           users->setemail(" ");
           users->setpass(" ");
       }
    }
    void adduser(User*user)
    {
        user->count++;
        while(n<capacity)
        {
        users[n].setname(user->getname());
        users[n].setage(user->getage());
        users[n].setemail(user->getemail());
        users[n].setpass(user->getpass());
        users[n].setid(user->getcount());
        break;
        }
        n++;
        usersCount=n;
    }
    User&searchUser(string name)
    {
        bool check;
        for(int i=0; i<usersCount; i++)
        {
            if(name==users[i].getname()){
                check=true;
                cout<<"user "<<users[i].getname()<<" information"<<endl;
                cout<<"Name: "<<users[i].getname()<<endl<<"Age: "<<users[i].getage()<<endl;
                cout<<"ID: "<<users[i].getid()<<endl<<"Email: "<<users[i].getemail()<<endl;
                break;}
            else
                check=false;
        }
        if (check==false)
            cout<<"wrong name"<<endl;
    }
    User&searchUser(int id)
    {
        bool check;
        for(int i=0; i<usersCount; i++)
        {
            if(id==users[i].getid()){
                check=true;
                cout<<"user "<<users[i].getid()<<" information"<<endl;
                cout<<"Name: "<<users[i].getname()<<endl<<"Age: "<<users[i].getage()<<endl;
                cout<<"ID: "<<users[i].getid()<<endl<<"Email: "<<users[i].getemail()<<endl;
                break;}
             else
                check=false;
        }
        if (check==false)
            cout<<"wrong id"<<endl;
    }
    void deleteuser(int id)
    {
        int z;
        for(int i=0; i<usersCount; i++)
        {
             if(id==users[i].getid()){
                z=i;
                break;}
        }
        for(int j=z; j<usersCount; j++)
        {
            users[j].getname()=users[j+1].getname();
            users[j].getemail()=users[j+1].getemail();
            users[j].getpass()=users[j+1].getpass();
            users[j].setage(users[j+1].getage());
            users[j].setid(users[j+1].getid());
        }
    }
    friend ostream&operator<<(ostream&output, UserList&userList) //ostream function for class UserList
    {
        for(int j=0; j<userList.usersCount; j++)
        {
            output<< userList.users[j]<<endl;
        }
        return output;
    }
    ~UserList()
    {
        delete users;
    }
};

class Book //Class 2 Book
{
private:
    string title;
    string isbn;
    string category;
    double avgrate;
    int id;
    double rate;
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
        author->setpass(a->getpass());
        author->setid(a->getid());
    }
    User getauthor() //get author
    {
        cout<<author->getname()<<author->getage()<<author->getemail()<<author->getpass()<<author->getid();
    }

    void setrate(double r)
    {
        rate=r;
    }
    double getrate()
    {
        return rate;
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
};
int Book::count=0; //definition of static variable of class book

class BookList
{
 private:
      Book *books ;
     int capacity;
     int booksCount;

 public:
     void setcapacity(int c)
     {
     capacity=c;
     }

      BookList( const BookList& anotherList)
     {
         capacity=anotherList.capacity;
         booksCount=anotherList.booksCount;
         books=anotherList.books;

         }

        void setbookCount(int i)
        {
            booksCount=i;
        }
         BookList(int c)
     {
         capacity=c;
         books=new Book [c];

         for(int i=0;i<c;i++)

         { string t,c,is;
           int d,r;
             cin>>t>>d>>c>>is;
             cin>>r;
              (books+i)->settitle(t);
             (books+i)->setid(d);
             (books+i)->setcategory(c);
             (books+i)->setisbn(is);
            (books+i)->ratebook(books[i].getrate());



         }


     }
         Book&searchBook(string name)
         {
             for(int i=0;i<5;i++)
             {
                 if( (books+i)->gettitle()== name)
                 {
                     cout<<books[i].gettitle()<<endl<<books[i].getisbn()<<endl;
                     cout<<books[i].getid()<<endl<<books[i].getcategory()<<endl;
                     books[i].ratebook(books[i].getrate());
                     books[i].getauthor();

                 }

             }
         }
         Book&searchBook(int id)
         {
             for(int i=0;i<capacity;i++)
             {
                 if( (books+i)->getid()== id )
                 {
                     cout<<books[i].gettitle()<<endl<<books[i].getisbn()<<endl;
                     cout<<books[i].getid()<<endl<<books[i].getcategory()<<endl;
                     books[i].ratebook(books[i].getrate());
                     books[i].getauthor();

                 }

                 }

             }





        Book &operator [ ] (int position)
         {

             return  books [position];
         }
         void deletebook(int id)

         { int x;
             for (int i=0;i<5; i++)
            {

             if((books+i)->getid() == id)

               {
                 x=i;
               }
            }
             for (int c=x; c<5 ; c++)
             {
               books[c].gettitle()=books[c+1].gettitle();
               books[c].getisbn()=books[c+1].getisbn();
               books[c].getcategory()=books[c+1].getcategory();
               books[c].setid(books[c+1].getid());

             }

         }

         Book gethigh()
         { double h;
         int x=0;
                h=books[0].getavr();
             for(int i=1;i<2;i++)
             {
                 if( (books+i)->getavr() > h )
                 {
                     h=books[i].getavr();
                 }
             }

             cout<<h<<endl;

         }
         Book* getBooksForUser( User u)

         {
          books[u.getid()].gettitle();
        books[u.getid()].getisbn();
        books[u.getid()].getid();
        books[u.getid()].getcategory();
        books[u.getid()].getauthor();
        books[u.getid()].ratebook(books[u.getid()].getrate());


         }
         friend ostream &operator<<( ostream &output,const  BookList &booklist )
         {

             for(int i=0;i<10;i++)
             {

              output<< booklist.books [i]<<endl;

             }
             return output;
         }


         ~BookList()
         {

             delete books;
         }
};

int main()
{
    int c1,c2,c3,c4;
    int capacity1,age,id;
    string name,email,pass;
    int capacity2,c;
    User U;
    Book b;
    cout<<"select one of this choices"<<endl;
    cout<<"1-User Menu"<<endl<<"2-Book Menu"<<endl<<"3-Exit"<<endl;
    cin>>c1;
    if(c1==1)
    {
        cout<<"how many users will be add"<<endl;
        cin>>capacity1;
        UserList UL(capacity1);
        do{
        cout<<"Users Menu"<<endl;
        cout<<"1-create a user"<<endl<<"2-search for a user"<<endl;
        cout<<"3-display all users"<<endl<<"4-back"<<endl;
        cin>>c2;
        if(c2==1)
        {
            cout<<"Enter the user information"<<endl;
            cout<<"name  "<<"age  "<<"email  "<<"password"<<endl;
            cin>>name>>age>>email>>pass;
            U.setname(name);
            U.setage(age);
            U.setemail(email);
            U.setpass(pass);
            UL.adduser(&U);
        }
        else if(c2==2)
        {
            cout<<"search for a user"<<endl<<"1-search by name"<<endl;
            cout<<"2-search by id"<<endl<<"3-return to the user menu"<<endl;
            cin>>c3;
            if(c3==1)
            {
                cout<<"Enter name"<<endl;
                cin>>name;
                UL.searchUser(name);
            }
            else if(c3==2)
            {
                cout<<"Enter id"<<endl;
                cin>>id;
                UL.searchUser(id);
                cout<<"1-delete this user"<<endl<<"2-return to the user menu"<<endl;
                cin>>c4;
                if (c4==1){
                    UL.deleteuser(id);}
                else if (c4==2){}
            }
            else if(c3=3){}
        }
        else if(c2=3)
        {
            cout<<UL;
        }
        else if (c2=4){}
        }while(true);
    }
    else if (c1==2)
    {
        do{
        cout<<"How many books will be addead"<<endl;
        cin>>capacity2;
        BookList bo(capacity2);
        cout<<"BOOKS MENU"<<endl;
        cout<<"1-Create a book and add it to the 1ist"<<endl<<"2-Search for a book "<<endl;
        cout<<"3-Display all books (with book rating)"<<endl<<"4-Get the highest rating book"<<endl;
        cout<<"5-Get all books of a user"<<endl;
        cout<<"6-Copy the current Book List to a new Book List and switch to it"<<endl;
        cout<<"7-Back to the main menu"<<endl;
        cin>>c;
        if(c==1)
          { Book newbook;
            int id,i;
            string s,cat,t;
            cout<< "Enter the book information in this order"<<endl<<"title"<<" "<<"isbn"<<" "<<"category"<<endl;
            cin>>t>>s>>cat;
             capacity++;
             newbook.setcategory(cat);
             newbook.settitle(t);
             newbook.setisbn(s);
             cout<<" 1-Assign author"<<endl<<"2-continue"<<endl;
             cin>>i;
                 if (i==1)
                 {
                 cout<<"enter  author (user) id" <<endl;
                 int id;
                 cin>>id;
                 UL.searchUser(id);
                 }
            break;
            }
            else if(c==2)
            { int i;
              cout<<  "SEARCH FOR A BOOK"<<endl<<"1- Search by name"<<endl<<"2- Search by id"<<endl<<"3- Return to Books Menu"<<endl;
              cin>>i;
              if(i==1)
              { string name;
                cin>>name;
                bo.searchBook(name);

              }
                else if(i==2)
              {
                  int id;
                  cin>>id;
                  bo.searchBook(id);
                  break;
              }
               else if (i==3)
              {
                  break;
              }
              break;

            }
       else if(c==3)
        {
            cout<<bo<<endl;
            break;
        }
       else if(c==4)
      {
        bo.gethigh();
        break;
      }
      else if (c==5)
      {
        cout<<bo<<endl;
        break;
      }
       else if(c==6)
      {
        BookList b2(bo);
        break;

      }

        else if (c==7){}
        }while(true);
    }
    else if (c1==3){}
    return 0;
}
