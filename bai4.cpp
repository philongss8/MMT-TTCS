#include <iostream>     // std::cin, std::cout
#include <stdio.h>
#include<conio.h>
#include <fstream>
#include <string>
#include<vector>
#include<time.h>
#include<windows.h>
#include <cstdlib>
using namespace std;
using namespace std;
void textcolor(int x)	//doi mau chu
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
int main()
{tt:
int n;

// doc file
char temp[255];
ifstream filein;
filein.open("input.txt",ios_base::in);
filein.getline(temp, 255);
n=atoi(temp);
int G[n][n];
int M[n][n];
string tam;
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{	fflush(stdin);
	if(j==n-1) getline(filein,tam);
	else
	getline(filein,tam,' ');
	G[i][j]=atoi(tam.c_str());
}
fflush(stdin);
}
int sum=0;
//sum ~ inf
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
sum+=G[i][j];
//nhung vi tri = 0 tra ve inf
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
if(G[i][j]==0) G[i][j]=sum;
//xuat ma tran duoc luu sau khi da bien doi
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{printf("%*d",5,G[i][j]);
}
cout<<endl;
}

//Tao mang vi tri
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
 M[i][j]=sum;

//nhap du lieu
int cuoi;
int vt;
cout<<"Nhap diem dau: ";
cin>>vt;
cout<<"Nhap diem cuoi: ";
cin>>cuoi;
//cho gt min ban dau bang inf
int min=sum;
//cac bien tam thoi
int tam2;
int bm=0;
int dem=0;
//xu ly vs mang 2 chieu =>> nhap -1
vt=vt-1;
cuoi=cuoi-1;
for(int i=0;i<n;i++)
{if(i==vt) {textcolor(14);G[vt][i]=0;}
printf("%*d",5,G[vt][i]);
if(G[vt][i]!=sum) M[bm][i]=vt;
if(i==vt) G[vt][i]=sum;
textcolor(7);
if(i==n-1) cout<<endl;
}
//tai cot vi tri nhap vao cho tat ca = inf --> xet min 
for(int i=0;i<n;i++)
{G[i][vt]=sum;
}

//khoi tao vong lap
while(vt!=cuoi)
{//moi lan lap lai lay gia tri min khac
bm=bm+1;
min=sum;
//tim min va bien tam thoi -->lay ra dong thu 2 khi tim kiem de xet vs dong thu 1 - vt
for(int i=0;i<n;i++)
{if(G[vt][i]<min) {
min=G[vt][i];
tam2=i;}
}
//tai cot vi tri  cho tat ca = inf --> xet min khi toi vong lap tiep theo
for(int i=0;i<n;i++)
{G[i][tam2]=sum;
}
//cong dong du lieu thu 2 voi min
for(int i=0;i<n;i++)
{G[tam2][i]=G[tam2][i]+min;

if(G[tam2][i]>G[vt][i]||G[tam2][i]==G[vt][i]) 
{
G[tam2][i]=G[vt][i];
M[bm][i]=M[bm-1][i];
}
else 
M[bm][i]=tam2;

}
//so sanh voi dong du lieu thu nhat
cout<<min;
cout<<endl<<tam2+1;
cout<<endl;
//gan vi tri de tiep tuc vong lap
vt=tam2;
//in ra man hinh
for(int i=0;i<n;i++)
{if(i==vt) {textcolor(14);G[vt][i]=min;}
printf("%*d",5,G[vt][i]);
if(i==vt) G[vt][i]=sum;
textcolor(7);
if(i==n-1) cout<<endl;
}
dem++;
if(vt==cuoi) break;
}


cout<<endl<<endl;
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{printf("%*d",5,M[i][j]+1);
}
cout<<endl;
}








cout<<endl<<"Again?";
char c;
c=getch();
if(c=='y') {system("cls");goto tt;}







}
