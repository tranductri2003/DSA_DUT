#include <bits/stdc++.h>

using namespace std;

void in (int a[], int n)
{
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

}
void selectionSort(int a[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        //Dùng 1 biến để lưu chỉ số của phần tử nhỏ nhất
        int min_pos=i;
        //Duyệt tất cả các phần tử đứng sau phần tử hiện tại và cập nhật chỉ số của phần tử nhỏ nhất
        for (int j=i+1;j<n;j++)
        {
            if (a[j]<a[min_pos])
            {
                min_pos=j;
            }
        }
        swap(a[i],a[min_pos]);
    }
}


void bubbleSort(int a[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
        in(a,n);
    }
}

void insertionSort(int a[], int n)
{
    for (int i=1;i<n;i++)
    {
        //Lấy ra phần tử ở chỉ i
        int x=a[i], pos=i-1;
        while (pos>=0 && x<a[pos])
        {
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1]=x;
        in (a,n);
    }
}


int partition(int a[], int l, int r)
{
    int pivot=a[r];
    int i=l-1;
    for (int j=l;j<r;j++)
    {
        if (a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    //đưa chốt về giữa
    i++;
    swap(a[i],a[r]);
    return i; //vị trí của chốt sau phân hoạch
}

void quickSort(int a[], int l, int r)
{
    if (l>=r) return;
    int p=partition(a,l,r);
    quickSort(a,l,p-1);
    quickSort(a,p+1,r);
}


int main()
{
    int a[1000], n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    // selectionSort(a,n);
    // bubbleSort(a,n);
    insertionSort(a,n);
    // quickSort(a,0,n-1);
    for (int i=0;i<n;i++) cout << a[i] <<" ";
}

// theo thu tu giam dan
//             if (a[j]<a[j+1])
// 42 89 12 73 25 62 31 50
// b1: 89 42 73 25 62 31 50 12
// b2: 89 73 42 62 31 50 25 12
// b3: 89 73 62 42 50 31 25 12
// b4: 89 73 62 50 42 31 25 12
// b5: 89 73 62 50 42 31 25 12
// b6: 89 73 62 50 42 31 25 12
// b7: 89 73 62 50 42 31 25 12

