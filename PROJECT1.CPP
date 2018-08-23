#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
    union REGS in,out;
    int gd=DETECT, gm;
    int x,y,x1,y1,b;
    FILE *fp, *ft;

    void Main1();
    void Show();
    void Welcome();
    void Student();
    void Faculty();
    void Move(int *x,int *y,int *b);
    void Terminate();

void main()
 {
       initgraph(&gd,&gm,"c:\\tc\\bgi");
       Main1();
       getch();
       closegraph();
       getch();
 }

void Main1()
  {
     char unm[20],user[20]="abhishek";
     char str[20],password[20]="12345678";
     char str1[10] ;
     int i=0;

     rectangle(100,36,600,400);
     setcolor(BLUE);
     rectangle(230,100,500,75);
     rectangle(275,143,500,165);
     rectangle(275,190,500,210);
     rectangle(250,350,350,390); //login
     outtextxy(280,370,"Login");
     rectangle(400,350,500,390);    //exit
     outtextxy(430,370,"Exit");
     gotoxy(40,6);
     printf("-:Login Screen:-");
     gotoxy(23,10);
     printf("Username:");
     gotoxy(23,13);
     printf("Password:");
     gotoxy(36,10);
     gets(unm);
  if(unm==user)
       clrscr();
     gotoxy(36,10);
     puts(unm);
     gotoxy(36,13);
  while(i<=6)
  {
     str[i]=getch();
     printf("*");
     i++;
  }
     str[i]='\0' ;
     i=0;

     printf("\n");
     getch();
     rectangle(400,350,500,390);
   Show();
     while(!kbhit())
    {
	 Move(&x,&y,&b);
	 if(b==1)
	{
	   for(x1=250;x1<=350;x1++)
	   for(y1=350;y1<=390;y1++)
	    if(x==x1&&y==y1)
	     {

	       if(password[i]==str[i])
		{
		  clrscr();
		  Welcome();
		}
		else
		{
		  clrscr();
		  cout<<"\n Wrong password try again\n";
		  getch();
		  exit(0);
		}
	       delay(100);
	       for(x1=400;x1<=500;x1++)
	       for(y1=350;y1<=390;y1++)
	       if(x==x1&&y==y1)
		{
		 Terminate();
		}

	      }
	}
    }
 }

 void Welcome()
{
       int choice;
       clrscr();
       cout<<"\n\n**********************************WELCOME********************************\n\n\n";
       cout<<"\n\n\n///// 1.Student database"<<endl<<"///// 2.Faculty database"<<endl<<"///// 3.Others"<<endl<<"///// 4.Exit";
     while(1)
     {
       cout<<"\n\n\nEnter your choice:";
       cin>>choice;
       switch(choice)
       {
	  case 1:
	     Student();
	    // cout<<"hello case 1";
	     break;
	  case 2:
	     Faculty();
	    // cout<<"\nHello case 2\n";
	     break;
	  case 3:
	     cout<<"\nOthers are not available";
	     break;
	  case 4:
	     exit(0);
	  default:
	     cout<<"\nWrong option try again";
       }
    }
}



 void Student()
{
     class Student1
     {
	 public:
	  char name[40];
	  int id;
	  float fee;
     };

	Student1 s;
	char name[40];
	char ano,choice;
	long int size;
	fp = fopen("Student1.DAT","wb+");
	if(fp == NULL)
       {
	    fp = fopen("Student1.DAT","wb+");
	    if(fp == NULL)
	    {
	       cout<<"Cannot open file";
	       exit(1);
	    }
	}
	size = sizeof(s);
	while(1)
       {
	   clrscr();
	   cout<<"\n1. Add Record";
	   cout<<"\n2. List Records";
	   cout<<"\n3. Modify Records";
	   cout<<"\n4. Delete Records";
	   cout<<"\n5. Exit";
	   cout<<"\nYour Choice: ";
	  // fflush(stdin);
	   choice  = getche();
	   switch(choice)
	   {
	     case 1:
		clrscr();
		fseek(fp,0,SEEK_END);
		ano = 'y';
		while(ano == 'y')
		{
		    cout<<"\nEnter name: ";
		    cin>>s.name;
		    cout<<"\nEnter id: ";
		    cin>>s.id;
		    cout<<"\nEnter fee: ";
		    cin>>s.fee;
		    fwrite(&s,size,1,fp);
		    cout<<"\nAdd another record(y/n)";
		    fflush(stdin);
		    ano = getche();
		}
		break;
	     case 2:
		clrscr();
		fseek(fp,0,SEEK_SET);
		while(fread(&s,size,1,fp)==1)
		{
		    cout<<"\n"<<s.name<<"\n"<<s.id<<"\n"<<s.fee;
		}
		getch();
		break;

	     case 3:
		clrscr();
		ano = 'y';
		while(ano == 'y')
		{
		   cout<<"\nEnter the student name to modify:";
		   cin>> name;
		   rewind(fp);
		   while(fread(&s,size,1,fp)==1)
		   {
		      if(strcmp(s.name,name) == 0)
		      {
			 cout<<"\nEnter new name,id and fee:";
			 cin>>s.name>>s.id>>s.fee;
			 fseek(fp,-size,SEEK_CUR);
			 fwrite(&s,size,1,fp);
			 break;
		       }
		    }
		 cout<<"\nModify another record(y/n)";
		 fflush(stdin);
		 ano = getche();
	       }
	       break;
	     case 4:
		clrscr();
		ano = 'y';
		while(ano == 'y')
		{
		   cout<<"\nEnter name of student to delete: ";
		   cin>>name;
		   ft = fopen("Temp.dat","wb");
		   rewind(fp);
		   while(fread(&s,size,1,fp) == 1)
		   {
		      if(strcmp(s.name,name) != 0)
		      {
			 fwrite(&s,size,1,ft);
		      }
		   }
		   fclose(fp);
		   fclose(ft);
		   remove("Student1.DAT");
		   rename("Temp.dat","Student1.DAT");
		   fp = fopen("Student1.DAT", "rb+");
		   cout<<"\nDelete another record(y/n)";
		   fflush(stdin);
		   ano = getche();
		}
		break;
	     case 5:
		fclose(fp);
		clrscr();
		Welcome();
		break;
	   }
       }
 }



void Faculty()
{
	char ano, choice;
    class Faculty1
      {
	public:
	char name[40];
	char id;
	float salary;
      };
	Faculty1 f1;
	char fname[40];
	long int recsize;
	fp = fopen("faculty.DAT","rb+");
     if(fp == NULL)
      {
	fp = fopen("faculty.DAT","wb+");
	if(fp == NULL)
	{
	    cout<<"Cannot open file";
	    exit(1);
	}
      }
	recsize = sizeof(f1);

     while(1)
     {
	clrscr();
	cout<<"\n6. Add Record";
	cout<<"\n7. List Records";
	cout<<"\n8. Modify Records";
	cout<<"\n9. Delete record";
	cout<<"\n10. EXIT";
	cout<<"\nYour Choice:";
       //	fflush(stdin);
	choice= getche();
     switch(choice)
       {
	case'6':
	      clrscr();
	      fseek(fp,0,SEEK_END);
	      char a= 'y';
	    while(a == 'y')
	       {
		    cout<<"\nEnter name:";
		    cin>>f1.name;
		    cout<<"\nEnter id:";
		    cin>> f1.id;
		    cout<<"\nEnter salary:";
		    cin>>f1.salary;
		    fwrite(&f1,recsize,1,fp);
		    cout<<"\nAdd another record (y/n)";
		//fflush(stdin);
		a = getche();
	       }
	    break;
	case '7':
	    clrscr();
	    rewind(fp);
	    while(fread(&f1,recsize,1,fp)==1)
	     {
		cout<<f1.name<<"\n"<<f1.id<<"\n"<<f1.salary;
	     }
	     getch();
	     break;

	 case '8':
	     clrscr();
	     ano = 'y';
	     while(ano == 'y')
	     {
		cout<<"\nEnter the faculty name to modify:";
		cin>>fname;
		rewind(fp);
		while(fread(&f1,recsize,1,fp)==1)
		{
		    if(strcmp(f1.name,fname) == 0)
		    {
			cout<<"\nEnter new name,id and salary:";
			cin>>f1.name>>f1.id>>f1.salary;
			fseek(fp,-recsize,SEEK_CUR);
			fwrite(&f1,recsize,1,fp);
			break;
		    }
		}
		cout<<"\nModify another record(y/n)";
		//fflush(stdin);
		ano = getche();
	    }
	    break;
	case '9':
	      clrscr();
	      ano = 'y';
	      while(ano == 'y')
	      {
		 cout<<"\nEnter name of faculty to delete:";
		 cin>>fname;
		 ft = fopen("Temp.dat","wb");
		 rewind(fp);
		 while(fread(&f1,recsize,1,fp) == 1)
		 {
		     if(strcmp(f1.name,fname) != 0)
		     {
			 fwrite(&f1,recsize,1,ft);
		     }
		}
		 fclose(fp);
		 fclose(ft);
		 remove("faculty.DAT");
		 rename("Temp.dat","faculty.DAT");
		 fp = fopen("facultty.DAT", "rb+");
		 cout<<"\nDelete another record(y/n)";
      //		 fflush(stdin);
		 ano = getche();
	     }
		 break;
	case '10':
	      fclose(fp);
	      clrscr();
	 //   welcome();
	      exit(0);
	}
     }
}


void Terminate()
  {
     exit(0);
  }

void Show()
  {
     int x,y,x1,y1,b;
     in.x.ax=1;
     int86(51,&in,&out);
  }


 void Move(int *x,int *y,int *b)
  {
     in.x.ax=3;
     int86(51,&in,&out);
     *x=out.x.cx;
     *y=out.x.dx;
     *b=out.x.bx;
  }


