// -------------------------LIBRARY MANAGEMENT SYSTEM-----------------------------//
#include<iostream>
using namespace std;
//Book class for storing book details
class book{
    public:
    string author,title;
    int isbn;
    bool loan;
    book(string title,string author,int isbn){
        this->author=author;
        this->title=title;
        this->isbn=isbn;
        loan=false;
    }
};
//node class for creating a book objects linked list
class node{
    public:
    //instead of data we are taking book object.
    book *bnode;
    node *next;
    node(book *b1){
        bnode=b1;
        next=NULL;
    }
};
//library class for implementing user choices
class library{
    public:
    //Method to add book to the catalogue
    node* add_book(book *ob1,node *tail){
        node *head1=new node(ob1);
        tail->next=head1;
        tail=tail->next;
        return tail;
    }
    //Method to remove book from catalogue
    node *remove_book(node *head){
        node *head1=head;
        string title,author;
        int flag=0,n,isbn;
        cout<<"Choose one: "<<endl;
        cout<<"1. Remove book by title\n 2. Remove book by author\n 3.Remove book by isbn\n";
        cin>>n;
        if(n==1){
            cout<<"Enter title: ";
            cin>>title;
            while(head1->next!=NULL){
                if(head1->next->bnode->title==title){
                    head1->next=head1->next->next;
                    flag=1;
                    break;
                }
                head1=head1->next;
            }
            if(flag==1)
                cout<<"Book is removed from Catalogue";
            else
                cout<<"Book not found";
            return head;
        }
        else if(n==2){
            cout<<"Enter Author: ";
            cin>>author;
            while(head1->next!=NULL){
                if(head1->next->bnode->author==author){
                    head1->next=head1->next->next;
                    flag=1;
                    break;
                }
                head1=head1->next;
            }
            if(flag==1)
                cout<<"Book is removed from Catalogue";
            else
                cout<<"Book not found";
            return head;
        }
        else{
            cout<<"Enter ISBN: ";
            cin>>isbn;
            while(head1->next!=NULL){
                if(head1->next->bnode->isbn==isbn){
                    head1->next=head1->next->next;
                    flag=1;
                    break;
                }
                head1=head1->next;
            }
            if(flag==1)
                cout<<"Book is removed from Catalogue";
            else
                cout<<"Book not found";
            return head;
        }
    }
    //Method to check wheather book is available or not
    node *search_book(node *head){
        node *head1=head;
        int n,flag=0,isbn;
        string title,author;
        cout<<"Choose one: "<<endl;
        cout<<"1. Search book by title\n 2. Search book by author\n 3.Search book by isbn\n";
        cin>>n;
        if(n==1){
            cout<<"Enter title name: ";
            cin>>title;
            while(head1->next!=NULL){
                if(head1->next->bnode->title==title){
                    flag=1;
                    break;
                }
                head1=head1->next;
            }
            if(flag==1)
                cout<<"Book Found"<<endl;
            else
                cout<<"Book Not Found"<<endl;
        }
        else if(n==2){
            cout<<"Enter author name: ";
            cin>>author;
            while(head1->next!=NULL){
                if(head1->next->bnode->author==author){
                    flag=1;
                    break;
                }
                head1=head1->next;
            }
            if(flag==1)
                cout<<"Book Found"<<endl;
            else
                cout<<"Book Not Found"<<endl;
        }
        else{
            cout<<"Enter isbn no: ";
            cin>>isbn;
            while(head1->next!=NULL){
                if(head1->next->bnode->isbn==isbn){
                    flag=1;
                    break;
                }
                head1=head1->next;
            }
            if(flag==1)
                cout<<"Book Found"<<endl;
            else
                cout<<"Book Not Found"<<endl;
        }
        return head;
    }
    node *book_loan(string title1,string author1,int isbn1,node *head){
        node *head1=head;
        int flag1=0,flag2=0;
        while(head1->next!=NULL){
            book *b3=head1->next->bnode;
            if(b3->title==title1 and b3->author==author1 and b3->isbn==isbn1){
                flag1=1;
                if(b3->loan==true){
                    flag2=1;
                }
                else{
                    b3->loan=true;
                }
                break;
            }
            head1=head1->next;
        }
        if(flag1==0)
            cout<<"Book is not available currently"<<endl;
        else{
            if(flag2==1){
                cout<<"Book is on loan, we'll inform you when it is available"<<endl;
            }
            else{
                cout<<"Loan Granted!! --HAPPY LEARNING--"<<endl;
            }
        }
        return head;
    }
    node *return_loan(string title1,string author1,int isbn1,node *head){
        node *head1=head;
        int flag1=0,flag2=0;
        while(head1->next!=NULL){
            book *b3=head1->next->bnode;
            if(b3->title==title1 and b3->author==author1 and b3->isbn==isbn1){
                flag1=1;
                b3->loan=false;
                break;
            }
            head1=head1->next;
        }
        if(flag1==1)
            cout<<"Book is available for loan now.."<<endl;
        else
            cout<<"Wrong book details entered"<<endl;
        return head;
    }

};
int main(){
    int n,i,j,isbn,flag=0;
    string author,title;
    //starting a linked list with head,tail;
    book *b1;
    book *d=new book("dummy","dummy",45);
    node *head=new node(d);
    node *tail=head;
    //creating library object for performing the functions.
    library *lib;
    //For continuous menu option I have taken infinite loop
    while(true){
        cout<<"\nChoose any of the menu option: ";
        cout<<"\n 1. ADD BOOK \n 2. REMOVE BOOK \n 3. SHOW ALL THE AVAILABLE BOOKS\n4. SEARCH BOOK \n5. TAKE BOOK ON LOAN\n6. RETURN BOOK\n7. Exit"<<endl;
        cin>>n;
        //Based on menu options else if ladder
        if(n==1){
            //ADDING BOOK TO LIBRARY
            cout<<"\nEnter Title: ";
            cin>>title;
            cout<<"\nEnter Author: ";
            cin>>author;
            cout<<"\nEnter ISBN: ";
            cin>>isbn;
            b1=new book(title,author,isbn);
            tail=lib->add_book(b1,tail);
        }
        else if(n==2){
            //REMOVING BOOK FROM LIBRARY
            head=lib->remove_book(head);
        }
        else if(n==3){
            //SHOWING ALL THE AVAILABLE BOOKS TO THE USER
            cout<<"printing available books"<<endl;
            node *head1=head;
            book *b2;
            while(head1->next!=NULL){
            b2=head1->next->bnode;
            cout<<b2->title<<" "<<b2->author<<" "<<b2->isbn<<endl;
            head1=head1->next;
            }
        }
        else if(n==4){
            //SEARCHING USER REQUESTED BOOK
            head=lib->search_book(head);
        }
        else if(n==5){
            //TAKING A BOOK LOAN
            cout<<"\nEnter book details that you want to take: ";
            cout<<"\nEnter title: ";
            cin>>title;
            cout<<"\nEnter author: ";
            cin>>author;
            cout<<"\nEnter ISBN: ";
            cin>>isbn;
            head=lib->book_loan(title,author,isbn,head);
        }
        else if(n==6){
            //RETURNING BOOK THAT WE HAVE TAKEN LOAN
            cout<<"\nEnter book details that you want to return: ";
            cout<<"\nEnter title: ";
            cin>>title;
            cout<<"\nEnter author: ";
            cin>>author;
            cout<<"\nEnter ISBN: ";
            cin>>isbn;
            head=lib->return_loan(title,author,isbn,head);
        }
        else{
            //COMING OUT WHEN USER CHOOSE TO EXIT
            flag=1;
        }
        if(flag==1)
            break;
    }
    return 0;
}