#include <iostream>
using namespace std;

void countingSort(int A[], int n){
    int i, j, k = 0;
    for(i = 0; i < n; i++) k = (A[i] >= k)?A[i]:k;
    // tìm k (số lớn nhất trong mảng)
    int B[n], C[k]; // tạo mảng B kích thước bằng A và mảng C với kích thước bằng giá trị của số lớn nhất trong A
    for(i = 0; i <= k; i++) C[i] = 0; // khởi tạo mảng C với tất cả ptu bằng 0
    for(j = 0; j < n; j++) C[A[j]] = C[A[j]] + 1; // ghi lại số lần xuất hiện của từng giá trị trong A
    for(i = 1; i <= k; i++) C[i] = C[i] + C[i-1]; // làm như này để xác định được thứ tự của số đó trong mảng A
    for(j = n - 1; j >= 0; j--){
        B[C[A[j]]-1] = A[j]; // index của B cũng là index của A[j] tương ứng trong mảng sau khi được sắp xếp
        C[A[j]] = C[A[j]] - 1; // giảm số lần xuất hiện đi 1
    }
    for(i = 0; i < n; i++) A[i] = B[i]; // lưu lại giá trị cho mảng A
}

main(){
    int a[] = {2,4,2,1,5,8,3,2,17,19,21,4,2,18,50,45,42,43,5,9,28};
    int len = sizeof(a) / sizeof(int);
    int i = 0, k = 0;
    while(i < len) cout << a[i++] << " ";
    cout << endl;
    countingSort(a, len);
    i = 0;
    while(i < len) cout << a[i++] << " ";
}