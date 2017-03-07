#include<iomanip.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include <conio.h>
#include<iostream.h>
#include<string.h>
#include<process.h>
#include<dos.h>
class password
{
char username[20];
char password[20];
char name[20];
public:
void newuser()
{
cout<<"enter name\t";
gets(name);
cout<<"enter username\t";
gets(username);
cout<<"enter password\t";
gets(password);
}
char* rusername()
{
return username;
}
char* rpassword()
{
return password;
}
char* rname()
{return name;
}
};
void pword()
{
password p;
char username[20],password[20];
cout<<"enter username\t";
gets(username);
cout<<"enter password\t";
gets(password);
ifstream f1;
f1.open("password.dat",ios::binary) ;
while(!f1.eof())
{
f1.read((char*)&p, sizeof(p));

if(strcmp(username,p.rusername())==0&&strcmp(password,p.rpassword())==0)
{cout<<"welcome "<<p.rname()<<endl;
sleep(1);
break;
}
else
{
if(f1.eof())
{cout<<"wrong password\n";
sleep(1);
exit(0);
}}
}}
void newu()
{
password p;
ofstream f1;
f1.open("password.dat",ios::app| ios::binary);

     p.newuser();
      f1.write((char*)&p, sizeof(p));
cout<<"welcome "<<p.rname()<<endl;
 sleep(1);
      f1.close();

}
class doflights
{
char passname[20];
int passage;
char from[20];
char to[20];
double pnrno;
char date[20];
double cost;
int duration;
double cardno;
int seatno;
public:
void accept()
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\npassenger name\t";
gets(passname);
cout<<"passenger age\t";
cin>>passage;
cout<<"journey from\t";
gets(from);
cout<<"journey to\t";
gets(to);
cout<<"date\t";
gets(date);
cout<<"enter your credit card no\t";
cin>>cardno;
randomize();
pnrno=random(10000)+1;
duration=random(20)+1;
seatno=random(100)+1;
}
void display()
{
 cout<<"\nTHANKS FOR THE BOOKING\n";
   cout<<"YOUR DETAILS\n";
if(duration<=2)
cout<<"bill is:Rs10000"<<endl;
else if(2<duration<=5)
cout<<"bill is:Rs20000"<<endl;
else
cout<<"bill is:Rs40000"<<endl;
cout<<"passenger name:"<<setw(11)<<passname<<endl;
cout<<"passenger age:"<<setw(12)<<passage<<endl;
cout<<"journey from:"<<setw(13)<<from<<endl;
cout<<"journey to:"<<setw(15)<<to<<endl;
cout<<"seat no:\t"<<seatno<<endl;
cout<<"date:"<<setw(20)<<date<<endl;
cout<<"pnrno is"<<setw(17)<<pnrno<<endl;
cout<<"journey duration(hrs):"<<setw(3)<<duration<<endl;
}
int rpnrno()
{
return pnrno;
}
};
   void write()
   {
    char ch;
    doflights d;
    fstream f1;
    f1.open("doflight.dat",ios::app| ios::binary);
    do
    {
      d.accept();
      f1.write((char*)&d, sizeof(d));
      cout<<"want to continue\t";
      cin>>ch;
      }while(ch!='n');
       f1.close();
      }
   void read()
   {
   doflights d;
   ifstream f1;
   f1.open("doflights.dat",ios::binary);
   while(f1.read((char*)&d, sizeof(d)))
   {
     d.display();
   }
   f1.close();
   }
   void search()
   {
     int n,flag=0;
     doflights d;
     ifstream f1;
     f1.open("doflights.dat",ios::binary);
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\nenter the pnrno\n";
     cin>>n;
     while(f1.read((char*)&d, sizeof(d)))
     {
      if(n==d.rpnrno())
      {
       cout<<"record found";
       d.display();
       flag=1;
       break;
       }
       }
       if(flag==0)
       cout<<"\nnot found";
       f1.close();
	      }
  void del()
{
doflights d;
fstream f1,f2;
int n,flag=0;
f1.open("doflights.dat",ios::in|ios::binary);
f2.open("temp.dat",ios::out|ios::binary);
cout<<"\n\n\n\n\n\n\n\n\n\n\n\nenter the pnr no\n";
cin>>n;
while(f1.read((char*)&d,sizeof(d)))
{
 if(d.rpnrno()!=n)
 f2.write((char*)&d, sizeof(d));
 else
 flag=1;
 }
 if(flag==0)
 cout<<"record not found\n";
 else
 cout<<"record deleted successfully\n";
 f1.close();
 f2.close();
 remove("doflights.dat");
 rename("temp.dat","doflights.dat");
 }
class intflights
{
char passname[20];
int passage;
char from[20];
char to[20];
double pnrno;
char date[20];
float cost;
int duration;
double cardno;
int seatno;
public:
void accept()
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\npassenger name\t";
gets(passname);
cout<<"passenger age\t";
cin>>passage;
cout<<"journey from\t";
gets(from);
cout<<"journey to\t";
gets(to);
cout<<"date\t";
gets(date);
cout<<"enter your credit card no\t";
cin>>cardno;
randomize();
pnrno=random(10000);
duration=random(20);
seatno=random(100);
}
void display()
{
 cout<<"\nTHANKS FOR THE BOOKING\n";
   cout<<"YOUR DETAILS\n";
if(duration<=5)
cout<<"bill is:40000"<<endl;
else if(5<duration<=10)
cout<<"bill is:75000"<<endl;
else
cout<<"bill is:100000"<<endl;
cout<<"passenger name"<<setw(11)<<passname<<endl;
cout<<"passenger age"<<setw(12)<<passage<<endl;
cout<<"journey from"<<setw(13)<<from<<endl;
cout<<"journey to"<<setw(15)<<to<<endl;
cout<<"seat no\t"<<seatno<<endl;
cout<<"date"<<setw(20)<<date<<endl;
cout<<"pnrno is"<<setw(17)<<pnrno<<endl;
cout<<"journey duration(hrs)"<<setw(4)<<duration<<endl;
}
int rpnrno()
{
return pnrno;
}
};
   void intwrite()
   {
    char ch;
    intflights i;
    ofstream f1;
    f1.open("intflight.dat",ios::app| ios::binary);
    do
    {
      i.accept();
      f1.write((char*)&i, sizeof(i));
      cout<<"want to continue\t";
      cin>>ch;
      }while(ch!='n');
       f1.close();
      }
   void intread()
   {
   intflights i;
   ifstream f1;
   f1.open("intflights.dat",ios::binary);
   while(f1.read((char*)&i, sizeof(i)))
   {
     i.display();
   }
   f1.close();
   }
   void intsearch()
   {
     int n,flag=0;
     intflights i;
     ifstream f1;
     f1.open("intflights.dat",ios::binary);
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\nenter the pnrno\n";
     cin>>n;
     while(f1.read((char*)&i, sizeof(i)))
     {
      if(n==i.rpnrno())
      {
       cout<<"record found\n";
       i.display();
       flag=1;
       break;
       }
       }
       if(flag==0)
       cout<<"not found\n";
       f1.close();
	      }
void intdel()
{
intflights i;
fstream f1,f2;
int n,flag=0;
f1.open("intflights.dat",ios::in|ios::binary);
f2.open("temp.dat",ios::out|ios::binary);
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\nenter the pnr no\t";
cin>>n;
while(f1.read((char*)&i,sizeof(i)))
{
if(i.rpnrno()!=n)
 f2.write((char*)&i,sizeof(i));
 else
 flag=1;
 }
 if(flag==0)
 cout<<"record not found\n";
 else
 cout<<"record deleted successfully\n";
 f1.close();
 f2.close();
 remove("intflights.dat");
 rename("temp.dat","intflights.dat");
 }

 void graphics()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode,"c:\\turboc3\\bgi");
   setbkcolor(RED);
   settextstyle(7,0,6 );
   outtextxy(160, 0,"WELCOME TO");
   outtextxy(120,50,"SM TOURS AND TRAVELS");
   settextstyle(1,0,2);
   outtextxy(75,120,"customer care no:9999888877,9999888876");
   outtextxy(75,160,"e-mail:smtravels@gmail.com");
}
 void g()
 {
 int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode,"c:\\turboc3\\bgi");
   setbkcolor(RED);
   }
   void main()
  {g();
  settextstyle(7,0,5);
   outtextxy(40,200,"Copyright @SM TOURS AND TRAVELS");
  sleep(2);
   for(int i=1;i<=2;i++)
   {
   clrscr();
   g();
   settextstyle(7,0,5);
   outtextxy(150,180,"Loading");
   outtextxy(320,180,".");
   delay(500);
   outtextxy(340,180,".");
   delay(500);
   outtextxy(360,180,".");
   delay(500);
   }
   clrscr();
   closegraph();
    int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode,"c:\\turboc3\\bgi");
   int z,n,a,b,c;
   clrscr();
   g();
   settextstyle(2,0,6 );
   outtextxy(10,5,"existing users:1");
   outtextxy(10,25,"new users:2\n");
   outtextxy(10,45,"enter choice:");
   gotoxy(22,4);
   cin>>z;
   cout<<endl;
   switch(z)
   {
   case 1:
   pword();
   break;
   case 2:
   newu();
   break;
   default:
   cout<<"invalid choice\n";
   sleep(1);
   exit(0);
  }
   for(i=1;i<=2;i++)
   {
   clrscr();
   g();
   settextstyle(7,0,5);
   outtextxy(150,180,"Loading");
   outtextxy(320,180,".");
   delay(500);
   outtextxy(340,180,".");
   delay(500);
   outtextxy(360,180,".");
   delay(500);
   }
   clrscr();
   graphics();
   settextstyle(5,0,3);
   outtextxy
   (230,195,"MENU:\n");
   settextstyle(8,0,2);
   outtextxy(230,230,"FLIGHTS:1\n");
   outtextxy(230,260,"Enter Choice:\t");
   gotoxy(49,18);
   cin>>n;
   clrscr();
   closegraph();
   graphics();
   switch(n)
   {
   case 1:
   settextstyle(5,0,3);
   outtextxy(230,195,"MENU:\n");
   settextstyle(8,0,2);
   outtextxy(20,230,"Domestic Flights:1");
   outtextxy(340,230,"International Flights:2\n");
   outtextxy(230,276,"Enter Choice:\t");
   gotoxy(49,19);
   cin>>a;
    clrscr();
    closegraph();
   graphics();
   switch(a)
  {
   case 1:
   settextstyle(5,0,3);
   outtextxy(230,195,"MENU:\n");
   settextstyle(8,0,2);
   outtextxy(190,230,"Book Domestic Flights:1\n");
   outtextxy(190,275,"Search For Your Flight:2\n");
   outtextxy(190,320,"Cancel Your Flight:3\n");
   outtextxy(190,357,"Enter Choice:");
   gotoxy(44,24);
   cin>>b;
    clrscr();
   closegraph();
   graphics();
   switch(b)
   {
   case 1:
   write();
   read();
   break;
   case 2:
   search();
   break;
   case 3:
   del();
   break;
    default:
   settextstyle(1,0,3);
   outtextxy(230,195,"\nINVALID OPTION");
   }
   break;
   case 2:
   settextstyle(5,0,3);
   outtextxy(230,195,"MENU:\n");
    settextstyle(8,0,2);
   outtextxy(190,230,"Book International Flights:1\n");
   outtextxy(190,275,"Search For Your Flight:2\n");
   outtextxy(190,320,"Cancel Your Flight:3");
   outtextxy(190,357,"Enter Choice:");
   gotoxy(44,24);
   cin>>c;
    clrscr();
   closegraph();
   graphics();
   switch(c)
   {
   case 1:
   intwrite();
   intread();
   break;
   case 2:
   intsearch();
   break;
   case 3:
   intdel();
   break;
    default:
   settextstyle(1,0,3);
   outtextxy(230,195,"\nINVALID OPTION");
   }
   break;
    default:
   settextstyle(1,0,3);
   outtextxy(230,195,"\nINVALID OPTION");
   }
   break;
   default:
   outtextxy(230,195,"INVALID OPTION");
   }
   getch();
}