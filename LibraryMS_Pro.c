#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<unistd.h>
#define RETURNTIME 15
char categories[][35]={"Computer science","Electronics","Electrical","Civil","Mechnnical","Metallurgy and Mining"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
int search_viewbooks(void);
void issuebooks(void);
int  getdata();
int t(void);
void Password();
void issuerecord();
void loaderanim();
FILE *cse,*elex,*Electrical,*civil,*mech,*metamin,*delete1,*ft2,*ft3,*ft4,*ft5,*ft6,*fs1,*fs2,*fs3,*fs4,*fs5,*fs6;
int s,ar;
char foundbook,line[1000];
char password[10]={"codebig"};
COORD coord={0,0};
void cursor (int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct Date
{
    int mm,dd,yy;
};
struct books
{
    int bookid;
    char studentname[50];
    char bookname[50];
    char Author[50];
    int numberofbooks;
    float Price;
    int count;
    int deptno;
    char *cat;
    struct Date issued;
    struct Date duedate;
};
struct books a;
int main()
{
    Password();
    getch();
    return 0;
    system("pause");
}
int t(void) //for time
{
    time_t t;
    time(&t);
    printf("Date and time:%s\n",ctime(&t));
    return 0 ;
}
void Password(void)
{
    system("cls");
    char d[25]="WELCOME";
    char e[100]="NATIONAL INSTITUTE OF TECHNOLOGY RAIPUR";
    char ch,pass[10];
    int i=0,j;
    cursor(4,4);
    for(j=0;j<15;j++)
    {
        //Sleep(50);
        printf("\xDB ");
    }
    for(j=0;j<7;j++)
    {
        //Sleep(50);
        printf("%c",d[j]);
    }
    for(j=0;j<15;j++)
    {
        //Sleep(50);
        printf(" \xDB");
    }
    printf("\n\n\n");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    cursor(16,10);
    for(j=0;j<50;j++)
    {
        //Sleep(50);
        printf("%c",e[j]);
    }
    printf("\n");
    cursor(16,14);
    printf("Enter Password:");
    while(1)
    {
    if(i<0)
        i=0;
      ch = getch();
      if(ch==13)
        break;
      else if(ch==8)
      {
putch('\b');
putch(NULL);
putch('\b');
i--;
continue;
      }
      else{
        pass[i]=ch;
        i++;
        putch('*');
      }
     }
    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {
        cursor(16,20);
        printf("Password match");
        cursor(16,22);
        printf("Press any key to countinue.....");
        getch();
        mainmenu();
    }
    else
    {
        cursor(15,16);
        printf("\aWarning!! Incorrect Password");
        getch();
        Password();
    }
}

void issuerecord()  //display issued book's information
{
    system("cls");
    cursor(10,8);
    printf("The Book has taken by Mr. %s",a.studentname);
    cursor(10,9);
    printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
    cursor(10,10);
    printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}

void returnfunc(void)
{
    {
        printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13) //allow only use of enter
        mainmenu();
    else
        goto a;
}

void mainmenu()
{
    system("cls");
    int i;
    cursor(20,3);
    printf("\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2 MAIN MENU \xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2");
    cursor(20,5);
    printf("\xDB\xDB\xDB\xDB\ 1. Add Books   ");
    cursor(20,7);
    printf("\xDB\xDB\xDB\xDB\ 2. Delete books");
    cursor(20,9);
    printf("\xDB\xDB\xDB\xDB\ 3. Search_view Books");
    cursor(20,11);
    printf("\xDB\xDB\xDB\xDB\ 4. Issue Books");
    cursor(20,13);
    printf("\xDB\xDB\xDB\xDB\ 5. Close Application");
    cursor(20,15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    cursor(20,17);
    t();
    cursor(20,19);
    int choice;
    printf("Enter your choice:");
    choice=getch();
    switch(choice)
    {
        case '1':
                    addbooks();
                    break;
        case '2':
                    deletebooks();
                    break;
        case '3':
                    search_viewbooks();
                    break;
        case '4':
                    issuebooks();
                    break;
        case '5':
                    system("cls");
                    cursor(30,3);
                    printf("TERM PROJECT IN C");
                    cursor(26,4);
                    printf("LIBRARY MANAGEMENT SYSTEM");
                    cursor(28,5);
                    printf("BY  LAKSHMI PRIYA KOLLI");
                    cursor(28,7);
                    printf("COMPUTER SCIENCE");
                    cursor(16,8);
                    printf("--------------------------------------------");
                    cursor(16,10);
                    printf("--------------------------------------------");
                    cursor(16,13);
                    printf("Exiting...........");
                    exit(0);
                    break;
        default:
                    cursor(10,23);
                    printf("\nWrong Entry!!Please re-enter correct option");
                    if(getch())
                        mainmenu();
                    break;
    }
}
int check_book(int id,FILE *temp)
{
    int x;;
char line[1000];
     while(fgets ( line, sizeof line, temp ) != NULL){

    sscanf(line, "%d", &x);
    if(id==x)
    return 1;
    }
}
void addbooks()
{
    system("cls");
    int i;
    cursor(12,5);
    printf("\xB2 \xB3 \xB2 \xB3 \xB2 \xB3 \xB2 \xB3  \xB2 \xB3  SELECT CATEGORY \xB2 \xB3  \xB2 \xB3  \xB2 \xB3  \xB2 \xB3  \xB2 \xB3 ");
    cursor(12,7);
    printf("\xDB\xDB\xDB\xDB\xB3 1. Computer science");
    cursor(12,9);
    printf("\xDB\xDB\xDB\xDB\xB3 2. Electronics");
    cursor(12,11);
    printf("\xDB\xDB\xDB\xDB\xB3 3. Electrical");
    cursor(12,13);
    printf("\xDB\xDB\xDB\xDB\xB3 4. Civil");
    cursor(12,15);
    printf("\xDB\xDB\xDB\xDB\xB3 5. Mechanical");
    cursor(12,17);
    printf("\xDB\xDB\xDB\xDB\xB3 6. metamin");
    cursor(12,19);
    printf("\xDB\xDB\xDB\xDB\xB3 7. Back to main menu");
    cursor(0,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    cursor(18,22);
    printf("Enter your choice:");
    s=getch();
    if(s==7)
    {
        mainmenu() ;
    }
    system("cls");
    printf("*******************Enter details without spaces*******************\n");
    switch(s)
    {
        case '1':
                {
                    cse=fopen("cse.txt","a+");
                    printf("Enter The unique id of The Book :(Integer) \n");
                    scanf("%d",&a.bookid);
                    ar=check_book(a.bookid,cse);
                    if(ar==1)
                    {
                        printf("Record already exists\nPress any key to go back to main menu\n");
                        getch();
                        mainmenu();
                    }
                    printf("Enter The Name of The Book :\n");
                    fflush(stdin);
                    gets(a.bookname);
                    printf("Enter The Name of Author :\n");
                    fflush(stdin);
                    gets(a.Author);
                    printf("Enter The Number of books :\n");
                    scanf("%d",&a.numberofbooks);
                    printf("Enter The Price Of Book :\n");
                    scanf("%f",&a.Price);
                    fprintf(cse,"%d\t\t%s\t\t\t%s\t\t\t\t%d\t\t%f\t\t\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                    printf("Record Saved Successfully");
                    fclose(cse);
                    printf("\nPress Enter to continue to main menu");
                    getch();
                    mainmenu();
                }
                break;
        case '2':
                {
                    elex=fopen("elex.txt","a+");
                    printf("Enter The unique id of The Book :(Integer) \n");
                    scanf("%d",&a.bookid);
                    ar=check_book(a.bookid,elex );
                    if(ar==1)
                    {
                        printf("Record already exists\nPress any key to go back to main menu\n");
                        getch();
                        mainmenu();
                    }
                    printf("Enter The Name of The Book :\n");
                    fflush(stdin);
                    gets(a.bookname);
                    printf("Enter The Name of Author :\n");
                    fflush(stdin);
                    gets(a.Author);
                    printf("Enter The Number of books :\n");
                    scanf("%d",&a.numberofbooks);
                    printf("Enter The Price Of Book :\n");
                    scanf("%f",&a.Price);
                    printf("Record Saved Successfully");
                    fprintf(elex,"%d\t\t%s\t\t%s\t\t%d\t\t%f\t\t\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                    fclose(elex);
                    printf("\nPress Enter to continue to main menu");
                    getch();
                    mainmenu();
                }
                break;
        case '3':
                {
                    Electrical=fopen("Electrical.txt","a+");
                    printf("Enter The unique id of The Book :(Integer) \n");
                    scanf("%d",&a.bookid);
                    ar=check_book(a.bookid,Electrical);
                    if(ar==1)
                    {
                        printf("Record already exists\nPress any key to go back to main menu\n");
                        getch();
                        mainmenu();
                    }
                    printf("Enter The Name of The Book :\n");
                    fflush(stdin);
                    gets(a.bookname);
                    printf("Enter The Name of Author :\n");
                    fflush(stdin);
                    gets(a.Author);
                    printf("Enter The Number of books :\n");
                    scanf("%d",&a.numberofbooks);
                    printf("Enter The Price Of Book :\n");
                    scanf("%f",&a.Price);
                    fprintf(Electrical,"%d\t\t%s\t\t%s\t\t%d\t\t%f\t\t\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                    printf("Record Saved Successfully");
                    printf("\nPress Enter to continue to main menu");
                    fclose(Electrical);
                    getch();
                    mainmenu();
                }
                break;
        case '4':
                {
                    civil=fopen("civil.txt","a+");
                    printf("Enter The unique id of The Book :(Integer) \n");
                    scanf("%d",&a.bookid);
                    ar=check_book(a.bookid,civil);
                    if(ar==1)
                    {
                        printf("Record already exists\nPress any key to go back to main menu\n");
                        getch();
                        mainmenu();
                    }
                    printf("Enter The Name of The Book :\n");
                    fflush(stdin);
                    gets(a.bookname);
                    printf("Enter The Name of Author :\n");
                    fflush(stdin);
                    gets(a.bookname);
                    printf("Enter The Number of books :\n");
                    scanf("%d",&a.numberofbooks);
                    printf("Enter The Price Of Book :\n");
                    scanf("%f",&a.Price);
                    fprintf(civil,"%d\t\t%s\t\t%s\t\t%d\t\t%f\t\t\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                    printf("Record Saved Successfully");
                    printf("\nPress Enter to continue to main menu");
                    fclose(civil);
                    getch();
                    mainmenu();
                }
                break;
        case '5':
                {
                    mech=fopen("mech.txt","a+");
                    printf("Enter The unique id of The Book :(Integer) \n");
                    scanf("%d",&a.bookid);
                    ar=check_book(a.bookid,mech);
                    if(ar==1)
                    {
                        printf("Record already exists\nPress any key to go back to main menu\n");
                        getch();
                        mainmenu();
                    }
                    printf("Enter The Name of The Book :\n");
                    fflush(stdin);
                    gets(a.bookname);
                    printf("Enter The Name of Author :\n");
                    fflush(stdin);
                    gets(a.Author);
                    printf("Enter The Number of books :\n");
                    scanf("%d",&a.numberofbooks);
                    printf("Enter The Price Of Book :\n");
                    scanf("%f",&a.Price);
                    fprintf(mech,"%d\t\t%s\t\t%s\t\t%d\t\t%f\t\t\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                    printf("Record Saved Successfully");
                    printf("\nPress Enter to continue to main menu");
                    fclose(mech);
                    getch();
                    mainmenu();
                }
                break;
        case '6':
                {
                    metamin=fopen("metamin.txt","a+");
                    printf("Enter The unique id of The Book :(Integer) \n");
                    scanf("%d",&a.bookid);
                    ar=check_book(a.bookid,metamin);
                    if(ar==1)
                    {
                        printf("Record already exists\nPress any key to go back to main menu\n");
                        getch();
                        mainmenu();
                    }
                    printf("Enter The Name of The Book :\n");
                    fflush(stdin);
                    gets(a.bookname);
                    printf("Enter The Name of Author :\n");
                    fflush(stdin);
                    gets(a.Author);
                    printf("Enter The Number of books :\n");
                    scanf("%d",&a.numberofbooks);
                    printf("Enter The Price Of Book :\n");
                    scanf("%f",&a.Price);
                    fprintf(metamin,"%d\t\t%s\t\t%s\t\t%d\t\t%f\t\t\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                    printf("Record Saved Successfully");
                    printf("\nPress Enter to continue to main menu");
                    fclose(metamin);
                    getch();
                    mainmenu();
                }
                break;
        default:
                system("cls");
                printf("Enter correct choice");
                mainmenu();
                break;
    }
}
void deletebooks()
{//void 1 on
    system("cls");
    cursor(12,5);
    printf("\xB2 \xB3 \xB2 \xB3 \xB2 \xB3 \xB2 \xB3 \xB2 \xB3 \xB2 SELECT CATEGORY \xB2 \xB3 \xB2 \xB3 \xB2 \xB3 \xB2 \xB3 \xB2 \xB3 \xB2 \xB3");
    cursor(12,7);
    printf("\xDB\xDB\xDB\xDB\xB3 1. Computer science");
    cursor(12,9);
    printf("\xDB\xDB\xDB\xDB\xB3 2. Electronics");
    cursor(12,11);
    printf("\xDB\xDB\xDB\xDB\xB3 3. Electrical");
    cursor(12,13);
    printf("\xDB\xDB\xDB\xDB\xB3 4. Civil");
    cursor(12,15);
    printf("\xDB\xDB\xDB\xDB\xB3 5. Mechanical");
    cursor(12,17);
    printf("\xDB\xDB\xDB\xDB\xB3 6. Metallurgy and Mining");
    cursor(12,19);
    printf("\xDB\xDB\xDB\xDB\xB3 7. Back to main menu");
    cursor(12,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    cursor(12,22);
    int schc;
    char schc1;
    printf("Enter the category: ");
    schc=getch();
    if(schc==7)
    {//7 on 2
        mainmenu();
    }//7off
    char Target[25];
    int Found=0;
    switch(schc)
    {// 3 on
                   case '1':
                    system("cls");
                    if((cse=fopen("cse.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        while(!feof(cse)&&Found==0)
                        {
                            fscanf(cse,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                        }
                        printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                    printf("Do u want to proceed y(for yes) / n(for no)");
                    }
                    if(!Found)
                        printf("! There is no such Entry...\n");
                    fclose(cse);
                    break;
        case '2':
                    system("cls");
                    if((elex=fopen("elex.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        while(!feof(elex)&&Found==0)
                        {
                            fscanf(elex,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                        }
                        printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                    printf("Do u want to proceed y(for yes) / n(for no)");
                    }
                    if(!Found)
                        printf("! There is no such Entry...\n");
                    fclose(elex);
                    break;
        case '3':
                    system("cls");
                    if((Electrical=fopen("Electrical.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        while(!feof(Electrical)&&Found==0)
                        {
                            fscanf(Electrical,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                        }
                        printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                    printf("Do u want to proceed y(for yes) / n(for no)");
                    }
                    if(!Found)
                        printf("! There is no such Entry...\n");
                    fclose(Electrical);
                    break;
        case '4':
                    system("cls");
                    if((civil=fopen("civil.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        while(!feof(civil)&&Found==0)
                        {
                            fscanf(civil,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                        }
                   printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                   printf("Do u want to proceed y(for yes) / n(for no)");
                    }
                    if(!Found)
                        printf("! There is no such Entry...\n");
                    fclose(civil);
                    break;
        case '5':
                    system("cls");
                    if((mech=fopen("mech.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        while(!feof(mech)&&Found==0)
                        {
                            fscanf(mech,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                        }
                        printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                   printf("Do u want to proceed y(for yes) / n(for no)");
                    }
                    if(!Found)
                        printf("! There is no such Entry...\n");
                    fclose(mech);
                    break;
        case '6':
                    system("cls");
                    if((metamin=fopen("metamin.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        while(!feof(metamin)&&Found==0)
                        {
                            fscanf(cse,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                        }
                        printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                   printf("Do u want to proceed y(for yes) / n(for no)");
                    }
                    if(!Found)
                        printf("! There is no such Entry...\n");
                    fclose(metamin);
                    break;

}//switch 3 off
}//void off
void issuebooks()
{
    int t,c=0;
    char another='y',foundbook;
    system("cls");
    printf("********************************ISSUE SECTION**************************");
    cursor(10,5);
    printf("\xDB\xDB\xDB\xDb\xB2 x. Issue a Book");
    cursor(10,9);
    printf("\xDB\xDB\xDB\xDb\xB2 y. Remove Issued Book");
    cursor(10,14);
    char mchc;
    printf("Enter a Choice:");
    mchc=getch();
    system("cls");
    printf("\xB3\xB3\xB3\xB3\xB3\xB3\xB3\xB3\xB3\xB3\xB3SELECT CATEGORY\xB3\xB3\xB3\xB3\xB3\xB3\xB3\xB3\xB3\xB3\xB3\xB3");
    int ichce;
    cursor(20,7);
    printf("\xDB\xDB\xDB\xDB\xB3 1. Computer science");
    cursor(20,9);
    printf("\xDB\xDB\xDB\xDB\xB3 2. Electronics");
    cursor(20,11);
    printf("\xDB\xDB\xDB\xDB\xB3 3. Electrical");
    cursor(20,13);
    printf("\xDB\xDB\xDB\xDB\xB3 4. Civil");
    cursor(20,15);
    printf("\xDB\xDB\xDB\xDB\xB3 5. Mechanical");
    cursor(20,17);
    printf("\xDB\xDB\xDB\xDB\xB3 6. Metallurgy and Mining");
    cursor(20,19);
    printf("\xDB\xDB\xDB\xDB\xB3 7. Back to main menu");
    ichce=getch();
    system("cls");
    if(ichce==7)
    {
        printf("Enter valid choice");
        mainmenu();
    }
    system("cls");
    int l;
    switch(ichce)
    {
        //mswitch
        case '1':
                    switch(mchc)
                    { //iswitch
                        case 'x':
                                    l=search_viewbooks();
                                    fs1=fopen("Issue1.txt","ab+");
                                    if(l==1)
                                    {
                                        cursor(10,8);
                                        printf("The book record is available");
                                        cursor(10,9);
                                        printf("There are %d unissued books in library ",a.numberofbooks);
                                        cursor(10,10);
                                        printf("The name of book is %s",a.bookname);
                                        cursor(10,11);
                                        printf("Enter student name:");
                                        scanf("%s",a.studentname);
                                        cursor(10,12);
                                        SYSTEMTIME str_t;
                                        {
                                            GetSystemTime(&str_t);
                                        }
                                        a.issued.dd=str_t.wDay;
                                        a.issued.mm=str_t.wMonth;
                                        a.issued.yy=str_t.wYear;
                                        printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
                                        cursor(10,13);
                                        printf("The BOOK of ID %d is issued",a.bookid);
                                        a.duedate.dd=a.issued.dd+RETURNTIME;
                                        a.duedate.mm=a.issued.mm;
                                        a.duedate.yy=a.issued.yy;
                                        if(a.duedate.dd>30)
                                        {
                                            //a.due
                                            a.duedate.mm+=a.duedate.dd/30;
                                            a.duedate.dd-=30;
                                        }
                                        //a.due
                                        if(a.duedate.mm>12)

                                        {
                                            //a.mm
                                            a.duedate.yy+=a.duedate.mm/12;
                                            a.duedate.mm-=12;
                                        }
                                        //a.mm
                                        cursor(10,14);
                                        printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
                                        fprintf(fs1,"STUDENTNAME: %s\t\t\tBOOK-ID: %d\t\t\tBOOK-NAME: %s\t\t\tISSUE DATE: %d-%d-%d\t\t\tDUE DATE: %d-%d-%d \n",a.studentname,a.bookid,a.bookname,a.issued.dd,a.issued.mm,a.issued.yy,a.duedate.dd,a.duedate.mm,a.duedate.yy);
                                        fclose(fs1);
                                        c=1;
                                    }
                                    //if a off
                                    if(c==0)
                                    {
                                        //c
                                        cursor(10,11);
                                        printf("No record found");
                                    }
                                    //c
                                    cursor(10,15);
                                    printf("Issue any more(Y/N):");
                                    fflush(stdin);
                                    another=getche();
                                    fclose(cse);
                                    break;

                    }//iswitch
                break;
                //c1b
        case '2':
                    switch(mchc)
                    {
                         //iswitch
                        case 'x':
                                    l=search_viewbooks();
                                    fs2=fopen("Issue2.txt","ab+");
                                    if(l==1)
                                    {
                                        cursor(10,8);
                                        printf("The book record is available");
                                        cursor(10,9);
                                        printf("There are %d unissued books in library ",a.numberofbooks);
                                        cursor(10,10);
                                        printf("The name of book is %s",a.bookname);
                                        cursor(10,11);
                                        printf("Enter student name:");
                                        scanf("%s",a.studentname);
                                        cursor(10,12);
                                        SYSTEMTIME str_t;
                                        {
                                            GetSystemTime(&str_t);
                                        }
                                        a.issued.dd=str_t.wDay;
                                        a.issued.mm=str_t.wMonth;
                                        a.issued.yy=str_t.wYear;
                                        printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
                                        cursor(10,13);
                                        printf("The BOOK of ID %d is issued",a.bookid);
                                        a.duedate.dd=a.issued.dd+RETURNTIME;
                                        a.duedate.mm=a.issued.mm;
                                        a.duedate.yy=a.issued.yy;
                                        if(a.duedate.dd>30)
                                        {
                                            //a.due
                                            a.duedate.mm+=a.duedate.dd/30;
                                            a.duedate.dd-=30;
                                        }
                                        //a.due
                                        if(a.duedate.mm>12)
                                        {
                                            //a.mm
                                            a.duedate.yy+=a.duedate.mm/12;
                                            a.duedate.mm-=12;
                                        }
                                        //a.mm
                                        cursor(10,14);
                                        printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
                                        fseek(fs2,sizeof(a),SEEK_END);
                                        fwrite(&a,sizeof(a),1,fs2);
                                        fclose(fs2);
                                        c=1;
                                    }
                                    //if a off
                                    if(c==0)
                                    {
                                        //c
                                        cursor(10,11);
                                        printf("No record found");
                                    }
                                    //c
                                    cursor(10,15);
                                    printf("Issue any more(Y/N):");
                                    fflush(stdin);
                                    another=getche();
                                    fclose(cse);
                                    break;
                                    //x break
                        }//iswitch
                        break;//c2b
            case '3':
                        switch(mchc)
                        {
                             //iswitch
                            case 'x':
                                        l=search_viewbooks();
                                        fs3=fopen("Issue3.txt","ab+");
                                        if(l==1)
                                        {
                                            cursor(10,8);
                                            printf("The book record is available");
                                            cursor(10,9);
                                            printf("There are %d unissued books in library ",a.numberofbooks);
                                            cursor(10,10);
                                            printf("The name of book is %s",a.bookname);
                                            cursor(10,11);
                                            printf("Enter student name:");
                                            scanf("%s",a.studentname);
                                            cursor(10,12);
                                            SYSTEMTIME str_t;
                                            {
                                                GetSystemTime(&str_t);
                                            }
                                            a.issued.dd=str_t.wDay;
                                            a.issued.mm=str_t.wMonth;
                                            a.issued.yy=str_t.wYear;
                                            printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
                                            cursor(10,13);
                                            printf("The BOOK of ID %d is issued",a.bookid);
                                            a.duedate.dd=a.issued.dd+RETURNTIME;
                                            a.duedate.mm=a.issued.mm;
                                            a.duedate.yy=a.issued.yy;
                                            if(a.duedate.dd>30)
                                            {
                                                //a.due
                                                a.duedate.mm+=a.duedate.dd/30;
                                                a.duedate.dd-=30;
                                            }
                                            //a.due
                                            if(a.duedate.mm>12)
                                            {
                                                //a.mm
                                                a.duedate.yy+=a.duedate.mm/12;
                                                a.duedate.mm-=12;
                                            }//a.mm
                                            cursor(10,14);
                                            printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
                                            fseek(fs3,sizeof(a),SEEK_END);
                                            fwrite(&a,sizeof(a),1,fs3);
                                            fclose(fs3);
                                            c=1;
                                        }
                                        //if a off
                                        if(c==0)
                                        {
                                            //c
                                            cursor(10,11);
                                            printf("No record found");
                                        }
                                        //c
                                        cursor(10,15);
                                        printf("Issue any more(Y/N):");
                                        fflush(stdin);
                                        another=getche();
                                        fclose(cse);
                                        break;
                                        //x break
                            }//iswitch
                            break;//c3b
            case '4':
                        switch(mchc)
                        {
                             //iswitch
                            case 'x':
                                        l=search_viewbooks();
                                        fs4=fopen("Issue4.txt","ab+");
                                        if(l==1)
                                        {
                                            cursor(10,8);
                                            printf("The book record is available");
                                            cursor(10,9);
                                            printf("There are %d unissued books in library ",a.numberofbooks);
                                            cursor(10,10);
                                            printf("The name of book is %s",a.bookname);
                                            cursor(10,11);
                                            printf("Enter student name:");
                                            scanf("%s",a.studentname);
                                            cursor(10,12);
                                            SYSTEMTIME str_t;
                                            {
                                                GetSystemTime(&str_t);
                                            }
                                            a.issued.dd=str_t.wDay;
                                            a.issued.mm=str_t.wMonth;
                                            a.issued.yy=str_t.wYear;
                                            printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
                                            cursor(10,13);
                                            printf("The BOOK of ID %d is issued",a.bookid);
                                            a.duedate.dd=a.issued.dd+RETURNTIME;
                                            a.duedate.mm=a.issued.mm;
                                            a.duedate.yy=a.issued.yy;
                                            if(a.duedate.dd>30)
                                            {
                                                //a.due
                                                a.duedate.mm+=a.duedate.dd/30;
                                                a.duedate.dd-=30;
                                            }
                                            //a.due
                                            if(a.duedate.mm>12)
                                            {
                                                //a.mm
                                                a.duedate.yy+=a.duedate.mm/12;
                                                a.duedate.mm-=12;
                                            }
                                            //a.mm
                                            cursor(10,14);
                                            printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
                                            fseek(fs4,sizeof(a),SEEK_END);
                                            fwrite(&a,sizeof(a),1,fs4);
                                            fclose(fs4);
                                            c=1;
                                        }
                                        //if a off
                                        if(c==0)
                                        {
                                            //c
                                            cursor(10,11);
                                            printf("No record found");
                                        }
                                        //c
                                        cursor(10,15);
                                        printf("Issue any more(Y/N):");
                                        fflush(stdin);
                                        another=getche();
                                        fclose(cse);
                                        break;
                                        //x break
                        }//iswitch
                        break;//c1b
            case '5':
                        switch(mchc)
                        {
                            //iswitch
                            case 'x':
                                        l=search_viewbooks();
                                        fs5=fopen("Issue5.txt","ab+");
                                        if(l==1)
                                        {
                                            cursor(10,8);
                                            printf("The book record is available");
                                            cursor(10,9);
                                            printf("There are %d unissued books in library ",a.numberofbooks);
                                            cursor(10,10);
                                            printf("The name of book is %s",a.bookname);
                                            cursor(10,11);
                                            printf("Enter student name:");
                                            scanf("%s",a.studentname);
                                            cursor(10,12);
                                            SYSTEMTIME str_t;
                                            {
                                                GetSystemTime(&str_t);
                                            }
                                            a.issued.dd=str_t.wDay;
                                            a.issued.mm=str_t.wMonth;
                                            a.issued.yy=str_t.wYear;
                                            printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
                                            cursor(10,13);
                                            printf("The BOOK of ID %d is issued",a.bookid);
                                            a.duedate.dd=a.issued.dd+RETURNTIME;
                                            a.duedate.mm=a.issued.mm;
                                            a.duedate.yy=a.issued.yy;
                                            if(a.duedate.dd>30)
                                            {
                                                //a.due
                                                a.duedate.mm+=a.duedate.dd/30;
                                                a.duedate.dd-=30;
                                            }
                                            //a.due
                                            if(a.duedate.mm>12)
                                            {
                                                //a.mm
                                                a.duedate.yy+=a.duedate.mm/12;
                                                a.duedate.mm-=12;
                                            }
                                            //a.mm
                                            cursor(10,14);
                                            printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
                                            fseek(fs5,sizeof(a),SEEK_END);
                                            fwrite(&a,sizeof(a),1,fs5);
                                            fclose(fs5);
                                            c=1;
                                        }
                                        //if a off
                                        if(c==0)
                                        {
                                            //c
                                            cursor(10,11);
                                            printf("No record found");
                                        }
                                        //c
                                        cursor(10,15);
                                        printf("Issue any more(Y/N):");
                                        fflush(stdin);
                                        another=getche();
                                        fclose(cse);
                                        break;
                                        //x break
                                    }
                                    //iswitch
                                    break;
                                    //c1b
            case '6':
                        switch(mchc)
                        {
                             //iswitch
                            case 'x':
                            l=search_viewbooks();
                            fs6=fopen("Issue6.txt","ab+");
                            if(l==1)
                            {
                                cursor(10,8);
                                printf("The book record is available");
                                cursor(10,9);
                                printf("There are %d unissued books in library ",a.numberofbooks);
                                cursor(10,10);
                                printf("The name of book is %s",a.bookname);
                                cursor(10,11);
                                printf("Enter student name:");
                                scanf("%s",a.studentname);
                                cursor(10,12);
                                SYSTEMTIME str_t;
                                {
                                    GetSystemTime(&str_t);
                                }
                                a.issued.dd=str_t.wDay;
                                a.issued.mm=str_t.wMonth;
                                a.issued.yy=str_t.wYear;
                                printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
                                cursor(10,13);
                                printf("The BOOK of ID %d is issued",a.bookid);
                                a.duedate.dd=a.issued.dd+RETURNTIME;
                                a.duedate.mm=a.issued.mm;
                                a.duedate.yy=a.issued.yy;
                                if(a.duedate.dd>30)
                                {
                                    //a.due
                                    a.duedate.mm+=a.duedate.dd/30;
                                    a.duedate.dd-=30;
                                }
                                //a.due
                                if(a.duedate.mm>12)
                                {
                                    //a.mm
                                    a.duedate.yy+=a.duedate.mm/12;
                                    a.duedate.mm-=12;
                                }
                                //a.mm
                                cursor(10,14);
                                printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
                                fseek(fs6,sizeof(a),SEEK_END);
                                fwrite(&a,sizeof(a),1,fs6);
                                fclose(fs6);
                                c=1;
                            }
                            //if a off
                            if(c==0)
                            {
                                //c
                                cursor(10,11);
                                printf("No record found");
                            }
                            //c
                            cursor(10,15);
                            printf("Issue any more(Y/N):");
                            fflush(stdin);
                            another=getche();
                            fclose(cse);
                            break;
                            //x break
                        }//iswitch
                        break;//c1b
                }//mswitch
}

//issue books
int search_viewbooks()
{
    //view 1 on
    system("cls");
    int d;
    printf("*****************************search Books*********************************");
    cursor(20,7);
    printf("\xDB\xDB\xDB\xDB\xB3 1. Computer science");
    cursor(20,9);
    printf("\xDB\xDB\xDB\xDB\xB3 2. Electronics");
    cursor(20,11);
    printf("\xDB\xDB\xDB\xDB\xB3 3. Electrical");
    cursor(20,13);
    printf("\xDB\xDB\xDB\xDB\xB3 4. Civil");
    cursor(20,15);
    printf("\xDB\xDB\xDB\xDB\xB3 5. Mechanical");
    cursor(20,17);
    printf("\xDB\xDB\xDB\xDB\xB3 6. Metallurgy and Mining");
    cursor(20,19);
    printf("\xDB\xDB\xDB\xDB\xB3 7. Back to main menu");
    cursor(20,21);
    int schc,schc1;
    printf("Enter the category: ");
    schc=getch();
    if(schc==7)
    {
        //7 on 2
        mainmenu();
    }
    char Target[25];
    int Found=0;
    //7 off2
    switch(schc)
    {
        case '1':
                    system("cls");
                    if((cse=fopen("cse.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        fflush(stdin);
                        gets(Target);
                        char line[1000];
                        while(fgets ( line, sizeof line, cse ) != NULL)
                            {
                            fscanf(cse,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                            }
                        if(Found==1)
                            printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                        else
                        printf("! There is no such Entry...\n");
                    }
                    fclose(cse);
                    break;
        case '2':
                    system("cls");
                    if((elex=fopen("elex.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        while(fgets ( line, sizeof line, elex ) != NULL)
                            {
                            fscanf(cse,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                            }
                        if(Found==1)
                            printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                        else
                        printf("! There is no such Entry...\n");
                        }
                    fclose(elex);
                    break;
        case '3':
                    system("cls");
                    if((Electrical=fopen("Electrical.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        char line[1000];
                        while(fgets ( line, sizeof line, Electrical ) != NULL)
                            {
                            fscanf(cse,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                            }
                        if(Found==1)
                            printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                        else
                        printf("! There is no such Entry...\n");
                        }
                    fclose(Electrical);
                    break;
        case '4':
                    system("cls");
                    if((civil=fopen("civil.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        char line[1000];
                        while(fgets ( line, sizeof line, civil ) != NULL)
                            {
                            fscanf(cse,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                            }
                        if(Found==1)
                            printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                        else
                        printf("! There is no such Entry...\n");
                        }
                    fclose(civil);
                    break;
        case '5':
                    system("cls");
                    if((mech=fopen("mech.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        char line[1000];
                        while(fgets ( line, sizeof line, mech ) != NULL)
                            {
                            fscanf(cse,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                            }
                        if(Found==1)
                            printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                        else
                        printf("! There is no such Entry...\n");
                    }
                    fclose(mech);
                    break;
        case '6':
                    system("cls");
                    if((metamin=fopen("metamin.txt","r"))==NULL)
                    {
                        printf(" ! The File is Empty...\n\n");
                    }
                    else
                    {
                        printf("\nEnter The Name Of Book : ");
                        scanf("%s",Target);
                        char line[1000];
                        while(fgets ( line, sizeof line, metamin ) != NULL)
                            {
                            fscanf(cse,"%d %s %s %d %f", &a.bookid,a.bookname,a.Author,&a.numberofbooks,&a.Price);
                            if(strcmp(Target,a.bookname)==0)
                            {
                                Found=1;
                            }
                            }
                        if(Found==1)
                            printf("\nThe ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author of the book is: %s\nQuantity: %d\nPrice: %f\n",a.bookid,a.bookname,a.Author,a.numberofbooks,a.Price);
                        else
                        printf("! There is no such Entry...\n");
                    }
                    fclose(metamin);
                    break;
    }
    return Found;
}
