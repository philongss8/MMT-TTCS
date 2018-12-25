#include <stdio.h>
#include <string.h>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
struct danhba
{char mod[10];
char ten[40];
char gt[10];
char sdt[12];
char email[40];
char dc[40];
};
typedef struct danhba danhba;
void Nhapdanhba(ifstream &filein,danhba &danhba)
{	char temp[255];
	filein.getline(temp, 255);
	strcpy(danhba.mod,temp);
	filein.getline(temp, 255);
	strcpy(danhba.ten,temp);
	fflush(stdin);
	filein.getline(temp, 255);
	strcpy(danhba.gt,temp);
	fflush(stdin);
	filein.getline(temp, 255);
	strcpy(danhba.sdt,temp);
	fflush(stdin);
	filein.getline(temp, 255);
	strcpy(danhba.email,temp);
	fflush(stdin);
	filein.getline(temp, 255);
	strcpy(danhba.dc,temp);
}
void Nhapdanhba2(ifstream &filein, vector<danhba> &ds)
{while (filein.eof()==false)
{danhba danhba;
Nhapdanhba(filein,danhba);
ds.push_back(danhba);
}
}
void Nhapdanhba3(danhba &danhba)
{cout<<"Nhap ten:";
gets(danhba.ten);
cout<<endl;
	fflush(stdin);
cout<<"Nhap gt:";
gets(danhba.gt);
cout<<endl;
	fflush(stdin);
cout<<"Nhap sdt:";
gets(danhba.sdt);
cout<<endl;
	fflush(stdin);
cout<<"Nhap email:";
gets(danhba.email);
cout<<endl;
	fflush(stdin);
cout<<"Nhap dc:";
gets(danhba.dc);
cout<<endl;
	fflush(stdin);
}
void Xuatdanhba(danhba danhba)
{cout<<"Ten: "<<danhba.ten<<endl;
cout<<"GT: "<<danhba.gt<<endl;
cout<<"Sdt: "<<danhba.sdt<<endl;
cout<<"Email: "<<danhba.email<<endl;
cout<<"Dc: "<<danhba.dc<<endl;
}
int main()
{ifstream filein;
filein.open("danhba.txt",ios_base::in);
vector<danhba> dsdanhba;
Nhapdanhba2(filein,dsdanhba);
filein.close();
for(int i=0;i<dsdanhba.size();i++)
{cout<<"===========================STT: "<<i+1<<"==========================="<<endl;
Xuatdanhba(dsdanhba[i]);
}
system("pause");
system("cls");
danhba tam;
Nhapdanhba3(tam);
char a[]="0";
strcpy(tam.mod,a);
dsdanhba.push_back(tam);
for(int i=0;i<dsdanhba.size();i++)
{cout<<"===========================STT: "<<i+1<<"==========================="<<endl;
Xuatdanhba(dsdanhba[i]);
}
 ofstream outfile;
   outfile.open("diem.txt");
for(int i=0;i<dsdanhba.size();i++)
{outfile<<dsdanhba[i].mod<<endl;
outfile<<dsdanhba[i].ten<<endl;
outfile<<dsdanhba[i].gt<<endl;
outfile<<dsdanhba[i].sdt<<endl;
outfile<<dsdanhba[i].email<<endl;
outfile<<dsdanhba[i].dc<<endl;
}
outfile.close();
}
