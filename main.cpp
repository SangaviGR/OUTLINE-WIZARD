/// FILE OUTLINE USING TREE

/// LIBRARIES ARE INCLUDED

#include<iostream>
#include<string>
#include <ctype.h>
#include<stdlib.h>
#include<fstream>

using namespace std;


/// STRUCTURE FOR TREE NODES

struct Node
{
    string Heading;
    string Content;
    Node *down;
    Node *next;
    int totalSections;
};

/// CLASS FOR OUTLINE OF DOCUMENT

class Outline
            {
                ///  PRIVATE DATA MEMBERS

                Node *root = NULL;
                Node *temp = NULL;
                Node *t = NULL;
                Node *t1 = NULL;

            public:

                /// PUBLIC MEMBER FUNCTIONS

                Node* create(string &heading,string &content);
                void insertTitle();
                void insertSections();
                void insertSubSections();
                void insertSubSubSections();
                void displayOutline();
                void displayDocument();
                void store();
            };

/// CLASS Outline's MEMBER FUNCTION DEFINITION

void Outline :: displayDocument()   /// FUNCTION HEADER

/// FUNCTION displayDocument() BODY

{
    system("color 0C");

    /// CHECKS IF DOCUMENT EXISTS OR NOT

    if(root == NULL)
    {
        cout<<"Document does't exist!!!"<<endl;
        cin.ignore();
        cin.get();
    }

    /// IF DOCUMENT EXISTS TRAVESES THE TREE TO DISPLAY

    else
    {
        temp = root; /// temp NODE IS ASSIGNED TO POINT TO ROOT NODE (FOR TRAVESAL)

        /// DISPLAYS THE TITLE AND IT'S CONTENT

        cout<<"\nTITLE : "<<endl;
        cout<<"\n\t\t\t"<<temp->Heading<<endl;

        cout<<"\n "<<temp->Content;

        /// CHECKS FOR SECTIONS TO DISPLAY THEM

        if(temp->totalSections == 1)
        {
            /// IF SECTIONS ARE PRESENT FROM ROOT NODE temp GOES TO SECTION NODE

            temp = temp->down;

            /// LOOP TO TRAVERSE SECTIONS AND DISPLAY IT

            while(temp!=NULL)
            {
                /// DISPLAYS ALL SECTIONS AND THIER CONTENTS

                cout<<"\nSECTION : "<<endl;
                cout<<"\n\t\t\t"<<temp->Heading<<endl;

                cout<<"\n "<<temp->Content;

                t = temp; /// NODE t POINTS TO SECTION NODES

                /// CHECKS IF SECTIONS HAVE SUB-SECTIONS TO DISPLAY THEM

                if(t->totalSections == 1)
                {
                    /// IF SUB-SECTIONS ARE PRESENT t IS MADE TO POINT TO SUB-SECTION NODES

                    t = t->down;

                    /// LOOP TO TRAVERSE SUB-SECTION NODES AND DISPLAY THEM

                    while(t!=NULL)
                    {
                        /// DISPLAYS SUBSECTION AND IT'S CONTENTS

                        cout<<"\nSUBSECTION : "<<endl;
                        cout<<"\n\t\t\t"<<t->Heading<<endl;

                        cout<<"\n "<<t->Content;

                        t1 = t; /// t1 IS MADE TO POINT TO SUB-SECTION NODE

                        /// CHECKS IF SUB-SECTIONS HAVE SUB-SECTIONS

                        if(t1->totalSections == 1)
                        {
                            /// IF SUB-SECTIONS HAVE SUB-SECTIONS t1 POINTS TO THE SUB-SUB-SECTION

                            t1 = t1->down;

                            /// LOOP TO TRAVERSE SUB-SUB-SECTIONS AND DISPLAY THEM

                            while(t1!=NULL)
                            {
                                /// DISPLAYS SUB-SUB-SECTIONS AND IT'S CONTENTS

                                cout<<"\nSUB-SUBSECTION : "<<endl;
                                cout<<"\n\t\t\t"<<t1->Heading<<endl;

                                cout<<"\n "<<t1->Content;

                                t1 = t1->next; /// t1 IS INCREMENTED FOR TRAVERSAL OF SUB-SUB-SECTIONS
                            } //END OF WHILE
                        }
                        t = t->next; /// t IS INCREMENTED FOR TRAVERSAL OF SUB-SECTIONS
                    }//END OF WHILE
                }
                temp = temp->next; /// temp IS INCREMENTED FOR TRAVERSAL OF SECTIONS
            }//END OF WHILE
        }
    }
    cin.ignore();
    cin.get();
}   /// END OF FUNCTION displayDocument()

/// CLASS Outline's MEMBER FUNCTION DEFINITION

void Outline :: store() /// FUNCTION HEADER

/// FUNCTION store() BODY

{
    /// FILE IS OPENDED AND THE TREE IS TRAVERSED TO STORE THE DOCUMENT

    fstream out;
    out.open("DOCUMENTS.txt",ios::app|ios::out);
    if(out.is_open())
    {
        system("color 0C");
        if(root == NULL)
        {
            cout<<"Document does't exist!!!"<<endl;
            cin.ignore();
            cin.get();
            exit(1);
        }
        else
        {
            temp = root;
            out<<"\nTITLE : "<<endl;
            out<<"\n\t\t\t"<<temp->Heading<<endl;
            out<<"\n "<<temp->Content;
            if(temp->totalSections == 1)
            {
                temp = temp->down;
                while(temp!=NULL)
                {
                    out<<"\nSECTION : "<<endl;
                    out<<"\n\t\t\t"<<temp->Heading<<endl;
                    out<<"\n "<<temp->Content;
                    t = temp;
                    if(t->totalSections == 1)
                    {
                        t = t->down;
                        while(t!=NULL)
                        {
                            out<<"\nSUBSECTION : "<<endl;
                            out<<"\n\t\t\t"<<t->Heading<<endl;
                            out<<"\n "<<t->Content;
                            t1 = t;
                            if(t1->totalSections == 1)
                            {
                                t1 = t1->down;
                                while(t1!=NULL)
                                {
                                    out<<"\nSUB-SUBSECTION : "<<endl;
                                    out<<"\n\t\t\t"<<t1->Heading<<endl;
                                    out<<"\n "<<t1->Content;
                                    t1 = t1->next;
                                }
                            }
                            t = t->next;
                        }
                    }
                    temp = temp->next;
                }
            }
        }
        out.close();
    }

}   /// END OF FUNCTION store()

/// CLASS Outline's MEMBER FUNCTION DEFINITION

void Outline :: displayOutline()    /// FUNCTION HEADER

/// FUNCTION displayOutline() BODY

{
    system("color 0C");
    if(root == NULL)
    {
        cout<<"Document does't exist!!!"<<endl;
        cin.ignore();
        cin.get();
    }
    else
    {
        temp = root;
        cout<<"\nTITLE : "<<temp->Heading<<endl;
        if(temp->totalSections == 1)
        {
            temp = temp->down;
            while(temp!=NULL)
            {
                cout<<"\nSECTION : "<<temp->Heading<<endl;
                t = temp;
                if(t->totalSections == 1)
                {
                    t = t->down;
                    while(t!=NULL)
                    {
                        cout<<"\nSUBSECTION : "<<t->Heading<<endl;
                        t1 = t;
                        if(t1->totalSections == 1)
                        {
                            t1 = t1->down;
                            while(t1!=NULL)
                            {
                                cout<<"\nSUB-SUBSECTION : "<<t1->Heading<<endl;
                                t1 = t1->next;
                            }
                        }
                        t = t->next;
                    }
                }
                temp = temp->next;
            }
        }
    }
    cin.ignore();
    cin.get();
}   /// END OF FUNCTION displayOutline()

/// CLASS Outline's MEMBER FUNCTION DEFINITION

void Outline :: insertSubSubSections()  /// FUNCTION HEADER

/// FUNCTION insertSubSubSections() BODY

{
    system("color 0E");
    string subSection,subSubSection,section,content;
    int noOfSubSubSections,i,F=0,F1=0;

    if(root == NULL)
    {
        cout<<"Title's not present"<<endl;
        cin.ignore();
        cin.get();
    }

    else
    {
        cout<<"Enter section to which you want to add Sub sub section"<<endl;
        cin>>section;

        temp = root;

        if(temp->totalSections == 0)
        {
            cout<<"There's no sections in this document"<<endl;
            cin.ignore();
            cin.get();
        }

        else
        {
            temp = temp->down;  ///section level


            while(temp != NULL)
            {

                if(!section.compare(temp->Heading))
                {
                    F=1;
                    if(temp->totalSections == 0)
                    {
                        cout<<"There's no sub-sections in this section"<<endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                    cout<<"Enter name of sub-section you want to add the sub-sub-section"<<endl;
                    cin>>subSection;

                    if(temp->totalSections == 0)
                    {
                        cout<<"There's no sub-sections"<<endl;
                        cin.ignore();
                        cin.get();
                    }

                    else
                    {
                        temp = temp->down;

                        while(temp != NULL)
                        {

                            if(!subSection.compare(temp->Heading))
                            {
                                F1 = 1;

                                do
                                {
                                    cout<<"How many sub-sub-section you want to add "<<endl;
                                    cin>>noOfSubSubSections;
                                }while(noOfSubSubSections<0);

                                for(i=0; i<noOfSubSubSections; i++)
                                {
                                    cout<<"Enter "<<i+1<<" sub-section of "<<subSection<<endl;
                                    cin>>subSubSection;
                                    cout<<"Enter Info for "<<subSubSection<<endl;
                                    cin.ignore();
                                    cin.get();
                                    getline(cin,content);

                                    t = create(subSubSection,content);
                                    if(temp->totalSections == 0)
                                    {
                                        temp->down = t;
                                        temp->totalSections = 1;
                                        t1 = temp->down;
                                    }

                                    else
                                    {
                                        while(t1->next != NULL)
                                        {
                                            t1 = t1->next;
                                        }
                                        t1->next = t;
                                    }
                                }

                                break;

                            }
                            temp = temp->next;
                        }
                        if(F1 == 0)
                        {
                            cout<<"NO SUCH SUB-SECTION AVAILABLE!!!!"<<endl;
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    }
                }
                temp = temp->next;

            }

            if(F == 0)
            {
                cout<<"NO SUCH SECTION AVAILABLE!!!!"<<endl;
                cin.ignore();
                cin.get();
            }

        }
    }


}   /// END OF FUNCTION insertSubSubSections()

/// CLASS Outline's MEMBER FUNCTION DEFINITION

void Outline :: insertSubSections() /// FUNCTION HEADER

/// FUNCTION insertSubSections() BODY

{
    system("color 0E");
    string section,subSection,content;

    int noOfSubSections,i,F=0;

    if(root == NULL)
    {
        cout<<"Title's not present"<<endl;
        cin.ignore();
        cin.get();
    }

    else
    {
        cout<<"Enter section to which you want to add subsection"<<endl;
        cin>>section;

        temp = root;

        if(temp->totalSections == 0)
        {
            cout<<"There's no sections in this document"<<endl;
            cin.ignore();
            cin.get();
        }


        else
        {
            temp = temp->down;

            while(temp != NULL)
            {

                if(!section.compare(temp->Heading))
                {
                    F=1;
                    do
                    {
                        cout<<"How many sub-sections you want to add"<<endl;
                        cin>>noOfSubSections;
                    }while(noOfSubSections<0);


                    for(i=0; i<noOfSubSections; i++)
                    {

                        cout<<"Enter sub-section "<<i+1<<endl;
                        cin>>subSection;
                        cout<<"Enter Info for "<<subSection<<endl;
                        cin.ignore();
                        cin.get();
                        getline(cin,content);
                        t = create(subSection,content);
                        if(temp->totalSections == 0)
                        {
                            temp->down = t;
                            temp->totalSections = 1;
                            t1 = temp->down;
                        }

                        else
                        {
                            while(t1->next != NULL)
                            {
                                t1 = t1->next;
                            }
                            t1->next = t;
                        }
                    }

                    break;

                }
                temp = temp->next;


            }

            if(F==0)
            {
                cout<<"NO SUCH SECTION AVAILABLE!!!!"<<endl;
                cin.ignore();
                cin.get();
            }

        }
    }
}   /// END OF FUNCTION insertSubSections()

/// CLASS Outline's MEMBER FUNCTION DEFINITION

void Outline :: insertSections()    /// FUNCTION HEADER

/// FUNCTION insertSections() BODY

{
    system("color 0E");
    int noOfSections,i;

    /// VARIABLES ARE DECLARED

    string section,content;

    /// CHECKS IF THE DOCUMENT IS AVAILABLE OR NOT

    if(root == NULL)
    {
        /// IF TITLE IS NOT PRESENT

        cout<<"Title's not present"<<endl;
        cin.ignore();
        cin.get();
    }

    else
    {

        /// IF TITLE IS PRESENT

        /// ASKS USER FOR THE NUMBER OF SECTIONS TO BE ADDED

        cout<<"How many sections do you want to add ?"<<endl;

        while(!(cin>>noOfSections))
        {

        system("cls");

        cout<<"ERROR !!!!! ENTER A NUMBER !!!!!!!"<<endl;

        cout<<"How many sections would you like to add ?"<<endl;

        cin.clear();

        cin.ignore(120,'\n');

        }

        /// ASKS USER FOR SECTION AND ITS CONTENTS

        for(i=0; i<noOfSections; i++)
        {
            cout<<"Enter section "<<i+1<<endl;
            cin>>section;

            cout<<"Enter Info for "<<section<<endl;
            cin.ignore();
            cin.get();
            getline(cin,content);

            /// NEW NODE IS CREATED FOR SECTION

            t = create(section,content);

            /// CHECKS IF SECTIONS ARE ALREADY PRESENT

            if(root->totalSections == 0)
            {

                /// IF THERE ARE NO SECTIONS,THE NEW CREATED SECTION NODE IS ADDED DOWN TO THE ROOT NODE

                root->down = t;

                /// TO INDICATE CHILD NODES ARE PRESENT

                root->totalSections = 1;
            }
            else
            {

                temp = root;    /// TEMP NODE IS ASSIGNED TO POINT TO THE ROOT NODE FOR TRAVERSAL AS SOME CHILD
                               /// NODE ALREADY EXISTS

                temp = temp->down;

                /// LOOP FOR TRAVERSING TO GET THE LAST NODE TO ADD NEW NODE

                while(temp->next != NULL)
                {

                    temp = temp->next;
                }

                temp->next = t; ///INSERTS A NEW NODE AFTER THE LAST NODE

            }

        }   /// END OF FOR

    }

}   /// END OF FUNCTION insertSections()

/// CLASS Outline's MEMBER FUNCTION DEFINITION

void Outline :: insertTitle()   /// FUNCTION HEADER

/// FUNCTION insertTitle() BODY

{
    system("color 0E");

    /// VARIABLES ARE DECLARED

    string title,content;

    /// CHECKS IF DOCUMENT EXISTS OR NOT

    if(root == NULL)
    {
        /// ASKS USER FOR TITLE AND CONTENT

        cout<<"Enter Title"<<endl;
        cin>>title;

        cout<<"Enter Info"<<endl;
        cin.ignore();
        cin.get();
        getline(cin,content);

        /// CREATING A NEW NODE FOR TITLE AND ASSIGNING IT AS THE ROOT NODE

        Node *t1 = NULL;
        t1 = create(title,content);
        root = t1;
    }

    else
    {
        /// IF TITLE EXISTS

        cout<<"Title exists"<<endl;
        cin.ignore();
        cin.get();
    }
}   /// END OF FUNCTION insertTitle()

/// CLASS Outline's MEMBER FUNCTION DEFINITION

Node*  Outline :: create(string &heading,string &content) /// FUNCTION HEADER

/// FUNCTION create() BODY

{
    /// CREATING NODE

    Node *ptr = new struct Node;
    ptr->next = NULL;
    ptr->down = NULL;
    ptr->totalSections = 0;

    /// ASSIGNING PASSED ARGUMENTS

    ptr->Heading = heading;
    ptr->Content = content;

    /// RETURNING POINTER TO THE CREATED NODE

    return ptr;

} /// END OF FUNCTION create()

/// MAIN FUNCTION BEGINS

int main()
{
    Outline *document;   /// POINTER OBJECT FOR CLASS Outline

    /// VARIABLES ARE DECLARED

    int choice,i=0,noOfDocuments,F=1;
    char ch;

    system("color 0B");

    /// ASKS USER FOR THE NUMBER OF DOCUMENTS TO BE CREATED

    cout<<"How many documents would you like to add ?"<<endl;

    while(!(cin>>noOfDocuments))
    {
        system("cls");

        cout<<"ERROR !!!!! ENTER A NUMBER !!!!!!!"<<endl;

        cout<<"How many documents would you like to add ?"<<endl;

        cin.clear();

        cin.ignore(120,'\n');


    }

    system("cls");

    /// DYNAMIC MEMORY ALLOCATION FOR CLASS Outline

    document = new Outline[noOfDocuments];

    /// LOOP FOR CREATING NEW DOCUMENTS

    for(i=0; i<noOfDocuments; i++)
    {

        F = 1; /// FLAG VARIABLE TO CREATE NEW DOCUMENTS

        /// LOOP TO CREATE A DOCUMENT

        while(F)
        {

            system("color 0B");

            /// DISPLAYS AVAILABLE OPERATIONS

            cout<<"\n 1]INSERT DOCUMENT TITLE "<<endl;
            cout<<"\n 2]INSERT SECTIONS OF THE DOCUMENT"<<endl;
            cout<<"\n 3]INSERT SUBSECTIONS OF THE DOCUMENT"<<endl;
            cout<<"\n 4]INSERT SUBSECTIONS OF THE SUBSECTIONS OF THE DOCUMNENT"<<endl;
            cout<<"\n 5]DISPLAY DOCUMENT OUTLINE"<<endl;
            cout<<"\n 6]DISPLAY DOCUMENT"<<endl;
            cout<<"\n 7]SAVE"<<endl;
            cout<<"\n 8]EXIT"<<endl;

            /// GETS REQUIRED OPERATION TO BE PERFORMED

            cout<<"\n Enter your choice:"<<endl;


            while(!(cin>>choice))

            {

                cout<<"ERROR !!!!! ENTER A NUMBER !!!!!!!"<<endl;

                cout<<"\n Enter your choice:"<<endl;

                cin.clear();

                cin.ignore(120,'\n');

            }

            switch(choice)
            {

            /// FUNCTION CALL TO INSERT TITLE

            case 1:
            {
                system("cls");
                document[i].insertTitle();
                system("cls");
            }
            break;

            /// FUNCTION CALL TO INSERT SECTIONS

            case 2:
            {
                system("cls");
                document[i].insertSections();
                system("cls");
            }
            break;

            /// FUNCTION CALL TO INSERT SUB-SECTIONS

            case 3:
            {
                system("cls");
                document[i].insertSubSections();
                system("cls");
            }
            break;

            /// FUNCTION CALL TO INSERT SUB-SUB-SECTIONS

            case 4:
            {
                system("cls");
                document[i].insertSubSubSections();
                system("cls");
            }
            break;

            /// FUNCTION CALL TO DISPLAY DOCUMENT OUTLINE

            case 5:
            {
                system("cls");
                document[i].displayOutline();
                system("cls");
            }
            break;

            /// FUNCTION CALL TO DISPLAY DOCUMENT

            case 6:
            {
                system("cls");
                document[i].displayDocument();
                system("cls");
            }
            break;

            /// FUNCTION CALL TO SAVE DOCUMENT

            case 7:
            {
                system("cls");
                document[i].store();
                system("cls");
            }
            break;


             /// TO EXIT

            case 8:
            {
                exit(0);
            }

            break;

           /// DEFAULT CASE

            default:
            {
                cout<<"INVALID OPTION !!!!!!!"<<endl;

            }

            }  /// END OF SWITCH

        } /// END OF WHILE

    } /// END OF FOR LOOP

    return 0;

} ///MAIN FUNCTION ENDS
