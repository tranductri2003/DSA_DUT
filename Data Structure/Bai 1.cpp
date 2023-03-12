#include <bits/stdc++.h>
using namespace std;

struct thongtin
{
    string name;
    int mssv;
    double gpa;
};

struct SV
{
    struct thongtin s;
    struct SV* next;
};

typedef struct SV* sv;

sv makeNode()
{
    thongtin nguoidung;
    cout << "Nhap thong tin sinh vien: \n";
    cout << "Nhap MSSV: "; cin >> nguoidung.mssv; fflush(stdin);
    cout << "Nhap ten: "; getline(cin, nguoidung.name); 
    cout << "Nhap GPA: "; cin >> nguoidung.gpa; 

    sv tmp=new SV();
    tmp->s=nguoidung;
    tmp->next=NULL;
    return tmp;
}


void insertFirst (sv &a)
{
    sv tmp=makeNode();
    if (a==NULL)
    {
        a=tmp;
    }
    else
    {
        tmp->next=a;
        a=tmp;
    }
}


void insertLast(sv &a)
{
    sv tmp=makeNode();
    if (a==NULL)
    {
        a=tmp;
    }
    else
    {
        sv p=a;
        while (p->next!=NULL)
        {
            p=p->next;
        }
        p->next=tmp;
    }
}

void in (thongtin s)
{
    cout << "--------------------------------\n";
    cout << "ID: " << s.name << endl;
    cout << "Ho va ten: " << s.mssv << endl;
    cout << "GPA: " << s.gpa << endl;
    cout << "--------------------------------\n";
}

void inds (sv a)
{
    cout << "Danh sach sinh vien: \n";
    cout << "----------------------------------------------------------------";
    while(a!=NULL)
    {
        in (a->s);
        a=a->next;
    }
    cout << endl;
}

void diemtrungbinhcaohon(sv a)
{
    double diem; cin >> diem;
    int check=0;

    cout << "Danh sach sinh vien co diem trung binh cao hon " << diem <<": \n" ;
    cout << "----------------------------------------------------------------";
    while(a!=NULL)
    {
        if (a->s.gpa>=diem)
        {
            in (a->s);
            check++;
        }
        a=a->next;
    }
    if (check==0) 
    {
        cout << "Khong co sinh vien nao diem cao hon " <<diem;
    }
    cout << endl;   
}

void sapxep (sv &a)
{
    for (sv p=a; p->next!=NULL; p=p->next)
    {
        sv max=p;
        for (sv q=p->next; q!=NULL; q=q->next)
        {
            if (q->s.gpa>max->s.gpa) 
            {
                max=q;
            }
        }

        thongtin tmp=max->s;
        max->s=p->s;
        p->s=tmp;
    }
    inds(a);
}
void max (sv a)
{
    float max=0;
    sv tmp=a;
    while (a!=NULL )
    {
        if (a->s.gpa>max)
        {
            max=a->s.gpa;
        }
        a=a->next;
    }

    while (tmp!=NULL)
    {
        if (tmp->s.gpa==max)
        {
            in(tmp->s);
        }
        tmp=tmp->next;
    }
}
int main()
{
    sv head=NULL;
    while (1)
    {
		cout << "-----------------MENU---------------\n";
		cout << "1. Chen sinh vien vao dau danh sach\n";
		cout << "2. Chen sinh vien vao cuoi danh sach\n";
		cout << "3. Duyet danh sach lien ket\n";
		cout << "4. Sap xep diem cac sinh vien\n";
        cout << "5. In ra thong tin cac sinh vien co diem trung binh cao hon x\n";
        cout << "6. In ra cac sinh vien co diem cao nhat\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";

        int lc; cin >>lc;
        if (lc ==1)
        {
            insertFirst(head);
        }
        else if (lc ==2)
        {
            insertLast(head);
        }
        else if (lc ==3)
        {
            inds(head);
        }
        else if (lc ==4)
        {
            sapxep(head);
        }
        else if (lc ==5)
        {
            diemtrungbinhcaohon(head);
        }
        else if (lc ==6)
        {
            max(head);
        }
        else if (lc ==0)
        {
            break;
        }
    }
}




// Câu 1:  Viết chương trình C hoàn chỉnh thực hiện các công việc sau đây:

// 1a:  Nhập mới danh sách liên kết n sinh viên một lớp gồm: Họ tên, Mã sinh viên, Điểm trung bình năm học.

// 1b: Nhập 1 điểm trung bình x và in thông tin của các sinh viên có Điểm trung bình năm học lớn hơn x.

// 1c: Tìm và liệt kê thông tin của những sinh viên có Điểm trung bình năm học cao nhất.
bool empty (sv a) 
{
    return a==NULL;
}

int Size (sv a)
{
    int cnt=0;
    while (a!=NULL)
    {
        a=a->next;
        cnt+=1;
    }
    return cnt;
}
