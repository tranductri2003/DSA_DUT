#include <bits/stdc++.h>
using namespace std;

struct thongtin
{
    string name,id;
    double gpa;
};

struct SV
{
    struct thongtin s;
    struct SV *next; // 8 bytes of data
}; // Kích thước con trỏ 8 bytes

typedef struct SV* sv;

sv makeNode()
{
    thongtin nguoidung;
    cout << "Nhap thong tin sinh vien: \n";
    cout << "Nhap ID: "; cin >> nguoidung.id;
    cout << "Nhap ten: "; cin >> nguoidung.name;
    cout << "Nhap GPA: "; cin >> nguoidung.gpa;

    sv tmp=new SV();  // Xin cấp phát một node SV để lưu thông tin sinh viên đấy
    tmp->s=nguoidung;
    tmp->next=NULL;
    return tmp;
}


// Kiểm tra rỗng
bool empty (sv a)
{
    return a==NULL;
}

int Size (sv a)
{
    int cnt=0;
    while (a!=NULL)
    {
        a=a->next; // gán địa chỉ của node tiếp theo cho node hiện tại
        // Cho node hiện tại nhảy sang node tiếp theo
        cnt+=1;
    }
    return cnt;
}

// Thêm 1 phần tử vào đầu danh sách liên kết
void insertFirst(sv &a)  // truyền tham chiếu
{
    sv tmp=makeNode ();
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


//thêm 1 phần từ vào cuối danh sách liên kết

void insertLast(sv &a)
{
    sv tmp=makeNode ();
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
        //dừng lại khi p là node cuối
        // hay p->next ==NULL
        p->next=tmp;
    }
}


//thêm 1 phần tử vào giữa

void insertMiddle(sv &a, int pos)
{
    int n=Size(a);
    if (pos <=0 || pos >n+1) 
    {
        cout << "vi tri chen khong hop le\n"; return;
    }
    if (pos==1)
    {
        insertFirst(a); return;
    }
    else if (pos==n+1)
    {
        insertLast(a); return;
    }
    else
    {
        sv p=a;
        for (int i=1; i<pos-1;i++)
        {
            p=p->next;
        }

        // giờ p đang ở pos-1
        sv tmp=makeNode ();
        tmp->next=p->next;
        p->next=tmp;
    }
}

//Xóa phần tử ở đầu

void deleteFirst(sv &a)
{
    if (a==NULL)
    {
        return;
    }
    else
    {
        a=a->next;
        //Cho phần tử thứ 2 trong danh sách liên kết hiện tại bằng a
    }
}


//Xóa phần tử ở cuối 
void deleteLast(sv &a)
{
    if (a==NULL) 
    {
        return;
    }
    else
    {
        sv truoc =NULL, sau=a;
        while (sau->next!=NULL)
        {
            truoc=sau;
            sau=sau->next;
        }
        if (truoc==NULL)
        {
            a=NULL;
        }
        else
        {
            truoc->next=NULL;
        }
    }
}

//xóa ở giữa
void deleteMiddle(sv &a, int pos)
{
    if (pos<=0||pos>Size(a))
    {
        return;
    }
    else
    {
        sv truoc=NULL,sau=a;
        for (int i=1; i<pos;i++)
        {
            truoc=sau;
            sau=sau->next;
        }

        if (truoc==NULL)
        {
            a=a->next;
        }
        else
        {
            truoc->next=sau->next;
        }
    }
}
void in (thongtin s)
{
    cout << "--------------------------------\n";
    cout << "ID: " << s.id << endl;
    cout << "Ho va ten: " << s.name << endl;
    cout << "GPA: " << s.gpa << endl;
    cout << "--------------------------------\n";
}

void inds(sv a)
{
    cout << "Danh sach sinh vien : \n";
    cout << "------------------------------------\n";
    while (a!=NULL)
    {
        in (a->s);
        a=a->next;  
    }
    cout << endl;
}

void sapxep(sv &a)
{
    for (sv p=a; p->next!=NULL; p=p->next)
    {
        sv min=p;
        for (sv q=p->next; q!=NULL; q=q->next)
        {
            if (q->s.gpa < min->s.gpa)
            {
                min=q;
            }
        }

        thongtin tmp=min->s;
        min->s=p->s;
        p->s=tmp;
    }
}

int main()
{
    sv head=NULL;
	while(1)
    {
		cout << "-----------------MENU---------------\n";
		cout << "1. Chen sinh vien vao dau danh sach\n";
		cout << "2. Chen sinh vien vao cuoi danh sach\n";
		cout << "3. Chen sinh vien vao giua danh sach\n";
		cout << "4. Xoa sinh vien o dau\n";
		cout << "5. Xoa sinh vien o cuoi\n";
		cout << "6. Xoa sinh vien o giua\n";
		cout << "7. Duyet danh sach lien ket\n";
		cout << "8. Sap xep cac sinh vien trong dslk\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
        
        int lc; cin >> lc;
        if(lc == 1)
        {
            insertFirst(head);
        }
        else if(lc == 2)
        {
            insertLast(head);
        }
        else if(lc == 3)
        {
            int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
            insertMiddle(head, pos);
        }
        else if(lc == 4)
        {
            deleteFirst(head);
        }
        else if(lc == 5)
        {
            deleteLast(head);
        }
        else if(lc == 6)
        {
            int pos; cout << "Nhap vi tri can xoa:"; cin >> pos;
            deleteMiddle(head, pos);
        }
        else if(lc == 7)
        {
            inds(head);
        }
        else if (lc ==8)
        {
            sapxep(head);
        }
		else if(lc == 0)
        {
			break;
		}
    }
}


