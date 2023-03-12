// 
// 2a: Hãy vẽ cây nhị phân tìm kiếm khi nhập lần lượt các số nguyên sau đây:

// 52        31        87        20        76        68        93        45

// 2b: Hãy khai báo (định nghĩa) kiểu nút cho cây nhị phân tìm kiếm trên.

// 2c: Viết hàm tính tổng giá trị các của cây nhị phân tìm kiếm trên.

// 2d: Hãy ghi thứ tự các nút khi duyệt cây nhị phân tìm kiếm trên theo thứ tự trước (NLR)/ thứ tự giữa (LNR)/ thứ tự sau (LRN) .
// 

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Đề bài: Nhập vào cây nhị phân các số nguyên. Xuất ra màn hình các phần tử 
// của cây nhị phân


// Khai báo cấu trúc 1 cái node
struct node 
{
    int data; // Dữ liệu của các node => Dữ liệu mà nó sẽ lưu trữ
    struct node *pLeft; //Node liên kết bên trái của cây <=> Cây con trái
    struct node *pRight; // Node liên kết bên phải của cây <=> Cây con phải
};

typedef struct node NODE;
typedef NODE * TREE;

// Khởi tạo cây
void KhoiTaoCay(TREE &t)
{
    t=NULL;

}

// hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(TREE &t, int x)
{
    //Nếu cây rỗng
    if (t==NULL)
    {
        TREE p=new NODE;  //Khởi tạo một cái node mới để thêm vào cây
        p->data =x; //thêm dữ liệu x vào data
        p->pLeft=NULL; 
        p->pRight=NULL;
        t=p; //Node p chính là node gốc <=> x chính là node gốc
    }
    else // cây có tồn tại phần tử
    {
         //Nếu phần tử thêm vào mà nhỏ hơn node gốc => thêm nó vào bên trái 
        if (x < t->data)
        {
            ThemNodeVaoCay(t->pLeft,x); // duyệt qua trái để thêm phần tử x
        }
        else if (x > t->data)
        {
            ThemNodeVaoCay(t->pRight,x); //Nếu phần tử thêm vào mà lon hơn node gốc => thêm nó vào bên phai
        }
    }
}

// hàm xuất cây nhị phân theo NLR
// Cây 5 1 2 -2 6 7 duyệt theo NLR sẽ ra
// 5 1 -2 2 6 7
void Duyet_NLR(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t!=NULL)
    {
        cout << t->data << " ";// xuất dữ liệu trong node
        Duyet_NLR(t->pLeft); //Duyệt qua trái
        Duyet_NLR(t->pRight); //Duyệt qua phải
    }
}



// hàm xuất cây nhị phân theo NRL
// Cây 5 7 -2 0 -5 1 6 -3 duyệt theo NRL sẽ ra
// 5 7 6 -2 0 1 -5 -3
void Duyet_NRL(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t!=NULL)
    {
        cout << t->data << " ";// xuất dữ liệu trong node
        Duyet_NRL(t->pRight); //Duyệt qua phải
        Duyet_NRL(t->pLeft); //Duyệt qua trái
    }
}



// hàm xuất cây nhị phân theo LNR <=> Xuất ra các phần tử từ bé đến lớn
// Cây 5 7 -2 0 -5 1 6 -3 duyệt theo LNR sẽ ra
// -5 -3 -2 0 1 5 6 7
// Thứ tự in ra tăng dần từ trái sang phải
// Đây là hàm sắp xếp luôn rồi
void Duyet_LNR(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t!=NULL)
    {
        Duyet_LNR(t->pLeft); //Duyệt qua trái
        cout << t->data << " ";// xuất dữ liệu trong node
        Duyet_LNR(t->pRight); //Duyệt qua phải
    }
}


// hàm xuất cây nhị phân theo RNL <=> Xuất ra các phần tử từ lớn đến bé
// Cây 5 7 -2 0 -5 1 6 -3 duyệt theo RNL sẽ ra
// -7 6 5 1 0 -2 -3 -5
void Duyet_RNL(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t!=NULL)
    {
        Duyet_RNL(t->pRight); //Duyệt qua phải
        cout << t->data << " ";// xuất dữ liệu trong node
        Duyet_RNL(t->pLeft); //Duyệt qua trái

    }
}


// hàm xuất cây nhị phân theo LRN 
// Cây 5 7 -2 0 -5 1 6 -3 duyệt theo LRN sẽ ra
// -3 -5 1 0 -2 6 7 5
void Duyet_LRN(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t!=NULL)
    {
        Duyet_LRN(t->pLeft); //Duyệt qua trái
        Duyet_LRN(t->pRight); //Duyệt qua phải
        cout << t->data << " ";// xuất dữ liệu trong node
    }
}


// hàm xuất cây nhị phân theo RLN 
// Cây 5 7 -2 0 -5 1 6 -3 duyệt theo RLN sẽ ra
// 6 7 1 0 -3 -5 -2 5
void Duyet_RLN(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t!=NULL)
    {
        Duyet_RLN(t->pRight); //Duyệt qua phải
        Duyet_RLN(t->pLeft); //Duyệt qua trái
        cout << t->data << " ";// xuất dữ liệu trong node
    }
}


void SUM(TREE t,int &sum)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t!=NULL)
    {
        SUM(t->pLeft, sum); //Duyệt qua trái
        sum+=t->data;
        SUM(t->pRight,sum); //Duyệt qua phải
    }
}

// Hàm kiểm tra số nguyên tố
bool KiemTraSoNguyenTo(int x)
{
    if (x < 2) return false;
    else
    {
        if (x == 2) return true;
        else
        {
            if (x%2==0)
            {
                return false;
            }
            else
            {
                for (int i=2;i<x;i++)
                {
                    if (x%i==0) return false;
                }
            }
        }
    }
    return true;
}

// Hàm đếm số lượng số nguyên tố
void SoLuongSoNguyenTo(TREE t, int &dem)  //Cho biến đếm là tham chiếu
{
    if (t!=NULL)
    {
        SoLuongSoNguyenTo(t->pRight,dem); //Duyệt qua phải
        SoLuongSoNguyenTo(t ->pLeft,dem); //Duyệt qua trái
        if (KiemTraSoNguyenTo(t->data)==true) dem++;
    }
}


// Nếu node có tồn tại trong cây thì trả về cái node đó - còn không tồn tại thì trả về NULL
TREE TimKiem (TREE t, int x)
{
    //Nếu cây rỗng
    if (t==NULL)
    {
        return NULL;
    }
    else
    {
        // Nếu phần tử cần tìm kiếm mà nhỏ hơn node gốc thì duyệt đệ quy sang bên trái
        if (x<t->data)
        {
            TimKiem(t->pLeft,x);
        }
        else if (x> t->data)
        {
            TimKiem(t->pRight,x);
        }
        else
        {
            return t;  // Trả về node cần tìm kiếm
        }
    }
}
void TimKiem2 (TREE t, int x)
{
    //Nếu cây rỗng
    if (t==NULL)
    {
        cout <<"khong" << endl;
    }
    else
    {
        // Nếu phần tử cần tìm kiếm mà nhỏ hơn node gốc thì duyệt đệ quy sang bên trái
        if (x<t->data)
        {
            TimKiem2(t->pLeft,x);
        }
        else if (x> t->data)
        {
            TimKiem2(t->pRight,x);
        }
        else
        {
            cout << "co" << endl;
        }
    }
}


// Xuất các node có 2 con
void Node_co_2_con(TREE t)
{
    if (t!=NULL)
    {
        // Xử lý
        if (t->pLeft!=NULL && t->pRight!=NULL) // con trái và con phải có tồn tại phần tử
        {
            cout << t->data << " "; 
        }
        Node_co_2_con(t->pLeft); //Duyệt sang cây con trái của node hiện tại
        Node_co_2_con(t->pRight); //Duyệt sang cây con phải của node hiện tại
    }
}

// Xuất các node có 1 con
void Node_co_1_con(TREE t)
{
    if (t!=NULL)
    {
        // Xử lý
        if ((t->pLeft!=NULL && t->pRight==NULL)||(t->pLeft==NULL && t->pRight!=NULL))
        {
            cout << t->data << " "; 
        }
        Node_co_1_con(t->pLeft); //Duyệt sang cây con trái của node hiện tại
        Node_co_1_con(t->pRight); //Duyệt sang cây con phải của node hiện tại
    }
}

// Xuất các node lá
void Node_la(TREE t)
{
    if (t!=NULL)
    {
        // Xử lý
        if (t->pLeft==NULL && t->pRight==NULL)
        {
            cout << t->data << " "; 
        }
        Node_la(t->pLeft); //Duyệt sang cây con trái của node hiện tại
        Node_la(t->pRight); //Duyệt sang cây con phải của node hiện tại
    }
}


//Tìm min
void Min(TREE t)
{
    if (t==NULL)
    {
        cout << "Khong co phan tu nho nhat\n";
    }
    else
    {
        if (t->pLeft == NULL)
        {
            cout << "Min: " << t->data << endl;
        }
        else
        {
            Min(t->pLeft);
        }
    }
}


//Tìm max
void Max(TREE t)
{
    if (t==NULL)
    {
        cout << "Khong co phan tu lon nhat\n";
    }
    else
    {
        if (t->pRight == NULL)
        {
            cout << "Max: " << t->data << endl;
        }
        else
        {
            Max(t->pRight);
        }
    }
}

// Xóa 1 node bất kì trong cây nhị phân tìm kiếm
// Node X là node cần xóa:
// Nếu X:
// 1. Node lá: xóa bình thường - bởi vì lúc này node x đang là node tự do
// (không tồn tại cây con trái và cây con phải)
// 2. Node có 1 con: trước khi xóa node x - chúng ta phải cập nhật mối liên kết
// giữa node cha của node x với node con(con trái hoặc con phải) của node x 
// 3. Node có 2 con: trước khi hủy thì ta phải đi tìm 1 cái node thế mạng cho node cần xóa
// - tìm node thế mạng phải đảm bảo quy tắc cây nhị phân tìm kiếm
// + Tìm node trái nhất của cây con phải(cây con phải của cái node cần xóa)
// + Tìm node phải nhất của cây con trái(cây con trái của cái node cần xóa)



// hàm tìm node thế mạng
void DiTimNodeTheMang(TREE &X, TREE &Y) // NODE Y là node thế mạng cho node cần xóa - node này sẽ đảm nhận nhiệm vụ tìm ra node trái nhất(TÌM NODE TRÁI NHẤT CÂY CON PHẢI) hoặc phải nhất(TÌM NODE PHẢI NHẤT CỦA CÂY CON TRÁI)
{
	// CÁCH 1: TÌM NODE TRÁI NHẤT CỦA CÂY CON PHẢI
	if (Y->pLeft != NULL)
	{
		DiTimNodeTheMang(X, Y->pLeft);// tìm ra node trái nhất ?
	}
	else // tìm ra được node trái nhất rồi nek..
	{
		X->data = Y->data; // cập nhật cái data của node cần xóa chính là data của node thế mạng
		X = Y; // cho node X(là node mà chúng ta sẽ đi xóa sau này) trỏ đến node thế mạng ==> ra khỏi hàm thì ta sẽ xóa node X
		Y = Y->pRight; // bản chất chỗ này chính là cập nhật lại mối liên kết cho node cha của node thế mạng(mà chúng ta sẽ xóa) với node con của node thế mạng	
        // Y=Y->pLeft là hoàn toàn sai
	}
}


// hàm xóa 1 cái node bất kì trong cây nhị phân tìm kiếm
void XoaNode(TREE &t, int data) // data chính là giá trị của cái node cần xóa
{
	// nếu như cây đang rỗng
	if (t == NULL)
	{
		return; // kết thúc hàm
	}
	else
	{
		// nếu như data nhỏ hơn node gốc
		if (data < t->data)
		{
			XoaNode(t->pLeft, data); // duyệt sang nhánh trái của cây 
		}
		else if (data > t->data)
		{
			XoaNode(t->pRight, data); // duyệt sang nhánh phải của cây 
		}
		else // data == t->data - đã tìm ra cái node cần xóa
		{
			NODE *X = t; // node X là node thế mạng - tí nữa chúng ta sẽ xóa nó
			// nếu như nhánh trái bằng NULL <=> đây là cây có 1 con chính là con phải
			if (t->pLeft == NULL)
			{
				// duyệt sang phải của cái node cần xóa để cập nhật mối liên kết giữa node 
				// cha của node cần xóa với node con của node cần xóa
				t = t->pRight; 
			}
			else if (t->pRight == NULL)
			{
				// duyệt sang trái của cái node cần xóa để cập nhật mối liên kết giữa node 
				// cha của node cần xóa với node con của node cần xóa
				t = t->pLeft;
			}
			else // node cần xóa là node có 2 con
			{
				// CÁCH 1: Tìm node trái nhất của cây con phải(cây con phải của cái node cần xóa)
				DiTimNodeTheMang(X, t->pRight);
			}
			delete X; // xóa node cần xóa
		}
	}
}

// hàm nhập dữ liệu
void Menu(TREE &t)
{
    while (true)
    {
        cout << "\n\n============================= MENU =============================\n\n";
        cout << "\n1. Nhap du lieu";
        cout << "\n2. Duyet cay NLR";
        cout << "\n3. Duyet cay NRL";
        cout << "\n4. Duyet cay LNR";
        cout << "\n5. Duyet cay RNL";
        cout << "\n6. Duyet cay LRN"; 
        cout << "\n7. Duyet cay RLN";   
        cout << "\n8. Tinh tong cac phan tu";
        cout << "\n9. Dem so luong so nguyen to";
        cout << "\n10. Tim kiem phan tu trong cay";
        cout << "\n11. Tim kiem don gian phan tu trong cay";
        cout << "\n12. In ra node co 2 con";
        cout << "\n13. In ra node co 1 con";
        cout << "\n14. In ra node la";
        cout << "\n15. In ra gia tri min";
        cout << "\n16. In ra gia tri max";
        cout << "\n17. Xoa node";
        cout << "\n0 .Ket thuc";
        cout << "\n=================================================================";

        int luachon;

        cout << "\nNhap lua chon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 17)
        {
            cout << "\nLua chon khong hop le";
        }
        else if (luachon==1)
        {
            int x;
            cout << "\nNhap so nguyen x: ";
            cin >> x;
            ThemNodeVaoCay(t,x);
        }
        else if (luachon==2)
        {
            cout << "\n\n\t\t DUYET CAY THEO NLR\n";
            Duyet_NLR(t);
            system("pause");
        }
        else if (luachon==3)
        {
            cout << "\n\n\t\t DUYET CAY THEO THEO NRL\n";
            Duyet_NRL(t);
            system("pause");
        }
        else if (luachon==4)
        {
            cout << "\n\n\t\t DUYET CAY THEO THEO LNR\n";
            Duyet_LNR(t);
            system("pause");
        }
        else if (luachon==5)
        {
            cout << "\n\n\t\t DUYET CAY THEO THEO RNL\n";
            Duyet_RNL(t);
            system("pause");
        }
        else if (luachon==6)
        {
            cout << "\n\n\t\t DUYET CAY THEO THEO LRN\n";
            Duyet_LRN(t);
            system("pause");
        }
        else if (luachon==7)
        {
            cout << "\n\n\t\t DUYET CAY THEO THEO RLN\n";
            Duyet_RLN(t);
            system("pause");
        }   
        else if (luachon==8)
        {
            int sum=0;
            SUM(t,sum);
            cout <<"Tong cua cac phan tu co trong cay la: " <<sum <<endl;
            system("pause");
        }  
        else if (luachon==9)
        {
            int dem=0;
            SoLuongSoNguyenTo(t,dem);
            cout <<"So luong so nguyen to co trong cay la: " <<dem <<endl;
            system("pause");
        }  
        else if (luachon==10)
        {
            cout << "Moi ban nhap gia tri can tim: ";
            int x; cin >>x;
            TREE p=TimKiem(t,x);

            if (p==NULL)
            {
                cout << "\nPhan tu "<< x<< " khong ton tai trong cay";
            }
            else
            {
                cout << "\nPhan tu "<< x<< " co ton tai trong cay";
            
            }
            system("pause");
        }
        else if (luachon==11)
        {
            cout << "Moi ban nhap gia tri can tim: ";
            int x; cin >>x;
            TimKiem2(t,x);
            system("pause");
        }
        else if (luachon==12)
        {
            cout << "\n\n\t\t NODE CO 2 CON\n";
            Node_co_2_con(t);
            system("pause");
        }
        else if (luachon==13)
        {
            cout << "\n\n\t\t NODE CO 1 CON\n";
            Node_co_1_con(t);
            system("pause");
        }
        else if (luachon==14)
        {
            cout << "\n\n\t\t NODE LA\n";
            Node_la(t);
            system("pause");
        }
        else if (luachon==15)
        {
            cout << "\n\n\t\t MIN\n";
            Min(t);
            system("pause");
        }
        else if (luachon==16)
        {
            cout << "\n\n\t\t MAX\n";
            Max(t);
            system("pause");
        }
        else if (luachon==17)
        {
            cout << "\n\n\t\t XOA NODE\n";
            int x;
            cout << "\nNhap gia tri can xoa: ";
            cin >> x;
            XoaNode(t,x);
            system("pause");
        }
        else
        {
            break;
        }
        system("cls");
    }
}
int main()
{
    TREE t;
    KhoiTaoCay(t);
    Menu(t);
    return 0;
}