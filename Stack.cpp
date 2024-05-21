//Cài đặt ngan xep bằng con tro
#include<iostream>
#include<fstream>
using namespace std;
struct Sinhvien
{
	int masv;
	string hoten;
	int namsinh;
};
typedef Sinhvien Item;
struct Node//dinh nghia 1 node
{
	Item Data;
	Node *Next;
};
struct Stack//dinh nghia ngan xep
{
	Node *Top;
};

//Khoi tao ngan xep
void Init(Stack &S)
{
	S.Top=NULL;
}
//Kiểm tra ngan xep S trong khong true/false
bool isEmpty(Stack S)
{
	if(S.Top==NULL)
		return true;
	else
		return false;
}
//Trả về độ dài của ngan xep
int len(Stack S)
{
	int dodai=0;
	while(S.Top!=NULL)
	{
		dodai++;
		S.Top=S.Top->Next;
	}
	return dodai;
}
// tao va tra ve 1 node co data la x
Node *Make_Node(Item x)
{
	Node *p;
	
	p = new Node;//cap phat bo nho cho con tro p
	p->Data = x;
	p->Next=NULL;
	
	return p;
}
//Push - Them 1 node co data la x vao ngan xep
void Push(Stack &S, Item x)
{
	Node *p;
	
	p = Make_Node(x);//b1 tao node p
	
	if(isEmpty(S))//ngan xer rong
		S.Top = p;
		else // ngan xep khong rong
	{
		p->Next = S.Top;//b2 tao lien ket
		S.Top = p;//b3 chuyen s top len tren
	}
}
//hien thi thong tin trong ngan xep
void Display(Stack S)
{
	while(S.Top!=NULL)
	{
		cout<<S.Top->Data.masv<<"\t"<<S.Top->Data.hoten<<"\t"<<S.Top->Data.namsinh<<endl;
		S.Top=S.Top->Next;
	}
}
//lay va tra ve data cua node dau tien trong ngan xep nhung khong xoa di
Item Peak(Stack S)
{
	return S.Top->Data;
}
//Pop - lay va tra ve node dau tien trong ngan xep va xoa di
Item Pop(Stack S)
{
	Item d;
	Node *p;
	d = S.Top->Data;//b0 luu lai va tra ve
	p = S.Top;//luu lai de giai phong
	S.Top = S.Top->Next;//b2 di chuyentop xuong duoi
	delete p;//b3 giai phong con tro p (node dau tien )
	return d;
}
//tim va tra ve  sinh vien lon tuoi nhat su dung ham Pop
Item Oldest(Stack S)
{
	Item DataMin, Data;
	
	DataMin = Pop(S);
	while(S.Top!=NULL)
	{
		Data = Pop(S);
		if(DataMin.namsinh > Data.namsinh)
		{
			DataMin = Data;
		}
	}
	return DataMin;
}
//ghi du lieu tu ngan xep s va tep stack.txt
void SaveStackToFile(Stack S)
{
	ofstream f1;
	Item Data;
	f1.open("stack.txt");
	if(!f1)
	{
		cout<<"Loi mo tep!";
		return;
	}
	while(S.Top!=NULL)
	{
		Data = Pop(S);
		f1<<Data.masv<<endl;
		f1<<Data.hoten<<endl;
		f1<<Data.namsinh<<endl;
	}
	f1.close();
}
//Menu
void Menu(Stack S)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao\n";
		cout<<"2. Kiem tra trong\n";
		cout<<"3. Do dai ngan xep\n";
		cout<<"4. Push - them vao ngan xep\n";
		cout<<"5. Peak - lay va khong xoa\n";
		cout<<"6. Pop - lay va xoa\n";
		cout<<"7. Tim sinh vien lon tuoi\n";
		cout<<"8. ghi du lieu tu ngan xep vao tep\n";
		
		cout<<"11. Dislay - hien thi ngan xep\n";
		cout<<"12. Thoat khoi chuong trinh\n";
		cout<<"Moi chon chuc nang (1-12)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Khoi tao
			{
				Init(S);
				cout<<"Da khoi tao!";
				break;
			}
			case 2://Kiem tra trong
			{
				if (isEmpty(S))
					cout<<"Danh sach trong!";
				else
					cout<<"Danh sach khong trong!";
				break;
			}
			case 3: //Lay do dai ngan xep
			{
				cout<<"Do dai ngan xep la:"<<len(S)<<endl;
				break;
			}
			case 4://theo vao ngan xep
			{
				Item x;
				
				cout<<"nhap thong tin sinh vien\n";
				cout<<"Ma sv:";
				cin>>x.masv;
				cin.ignore();
				cout<<"Ho ten:";
				getline(cin,x.hoten);
				cout<<"Nam sinh:";
				cin>>x.namsinh;
				
				Push(S,x);//them vao ngan xep
				break;
			}
			case 5://lay va khong xoa
			{
				Item Data;
				if(!isEmpty(S))
				{
					Data = Peak(S);//Gia tri tra ve cua Pop duoc gian cho bien Data
					cout<<Data.masv<<"\t"<<Data.hoten<<"\t"<<Data.namsinh<<endl;
				}
				else//ngan xep rong
				{
					cout<<"Ngan xep rong!";
				}
				break;
			}
			case 6://Pop lay va xoa
			{
				Item Data;
				if(!isEmpty(S))
				{
					Data = Pop(S);//Gia tri tra ve cua Pop duoc gian cho bien Data
					cout<<Data.masv<<"\t"<<Data.hoten<<"\t"<<Data.namsinh<<endl;
				}
				else//ngan xep rong
				{
					cout<<"Ngan xep rong!";
				}
				break;
			}
			case 7://hien thi sinh vien lon tuoi
			{
				Item DataMin;
				if(isEmpty(S))
				{
					cout<<"Ngan xep rong!";
				}
				else
				{
					DataMin = Oldest(S);//In datamin in ra man hinh
					cout<<DataMin.masv<<"\t"<<DataMin.hoten<<"\t"<<DataMin.namsinh<<endl;
				}
				break;
			}
			case 8://ghi du lieu tu ngan xep vao tep
			{
				SaveStackToFile(S);
				cout<<"Da ghi xong!";
				break;
			}
			case 11://hien thi ngan xep
			{
				Display(S);
				break;
			}
			case 12:
			{
				cout<<"Tam biet!";
				break;
			}		
		}
	}while(LuaChon!=12);
}
int main()
{
	Stack S;
	Menu(S);
	
	return 0;
}
