#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    int a[1000], n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    selectionSort(a,n);
    for (int i=0;i<n;i++) cout << a[i] <<" ";
    
}