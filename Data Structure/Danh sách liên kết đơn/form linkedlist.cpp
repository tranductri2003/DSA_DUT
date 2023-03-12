#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;  // 4 bytes of data
    struct Node *next; // 8 bytes of data
}; // Kích thước con trỏ 8 bytes

typedef struct Node* node;

// Cấp phát động một node mới với dữ liệu là một số nguyên x
node makeNode(int x)
{
    node tmp= new Node(); // cấp phát bộ nhớ cho con trỏ Node thuộc kiểu node 
    tmp->data=x;
    tmp->next=NULL;  //nullptr
    return tmp;
}

// Kiểm tra rỗng
bool empty (node a)
{
    return a==NULL;
}

int Size (node a)
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
void insertFirst(node &a, int x)  // truyền tham chiếu
{
    node tmp=makeNode (x);
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

// Code trong C
// void insertFirst(node *a, int x) Con trỏ kiểu node
// {
//     node tmp=makeNode(x);
//     if (*a==NULL)  giá trị con trỏ
//     {
//         *a=tmp;
//     }
//     else
//     {
//         tmp->next=*a;
//         *a=tmp;
//     }
// }


//thêm 1 phần từ vào cuối danh sách liên kết

void insertLast(node &a, int x)
{
    node tmp=makeNode (x);
    if (a==NULL) 
    {
        a=tmp;
    }
    else
    {
        node p=a;
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

void insertMiddle(node &a, int x, int pos)
{
    int n=Size(a);
    if (pos <=0 || pos >n+1) 
    {
        cout << "vi tri chen khong hop le\n";
    }
    if (pos==1)
    {
        insertFirst(a,x); return;
    }
    else if (pos==n+1)
    {
        insertLast(a,x); return;
    }
    else
    {
        node p=a;
        for (int i=1; i<pos-1;i++)
        {
            p=p->next;
        }

        // giờ p đang ở pos-1
        node tmp=makeNode (x);
        tmp->next=p->next;
        p->next=tmp;
    }
}

//Xóa phần tử ở đầu

void deleteFirst(node &a)
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
void deleteLast(node &a)
{
    if (a==NULL) 
    {
        return;
    }
    else
    {
        node truoc =NULL, sau=a;
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
void deleteMiddle(node &a, int pos)
{
    if (pos<=0||pos>Size(a))
    {
        return;
    }
    else
    {
        node truoc=NULL,sau=a;
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

void in(node a)
{
    cout << "------------------------------------\n";
    while (a!=NULL)
    {
        cout << a->data << " ";
        a=a->next;  
    }
    cout << endl;
}

void sapxep(node &a)
{
    for (node p=a; p->next!=NULL; p=p->next)
    {
        node min=p;
        for (node q=p->next; q!=NULL; q=q->next)
        {
            if (q->data < min->data)
            {
                min=q;
            }
        }
        int tmp=min->data;
        min->data=p->data;
        p->data=tmp;
    }
}

int main()
{
    node head=NULL;
	while(1)
    {
		cout << "-----------------MENU---------------\n";
		cout << "1. Chen phan tu vao dau danh sach\n";
		cout << "2. Chen phan tu vao cuoi danh sach\n";
		cout << "3. Chen phan tu vao giua danh sach\n";
		cout << "4. Xoa phan tu o dau\n";
		cout << "5. Xoa phan tu o cuoi\n";
		cout << "6. Xoa phan tu o giua\n";
		cout << "7. Duyet danh sach lien ket\n";
		cout << "8. Sap xep cac phan tu trong dslk\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
        
        int lc; cin >> lc;
        if(lc == 1)
        {
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            insertFirst(head, x);
        }
        else if(lc == 2)
        {
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            insertLast(head, x);
        }
        else if(lc == 3)
        {
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
            insertMiddle(head, x, pos);
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
            in(head);
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


