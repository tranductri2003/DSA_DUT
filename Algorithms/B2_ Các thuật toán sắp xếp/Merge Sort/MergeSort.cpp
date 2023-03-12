#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){ // hàm merge 2 mảng lại
    int i, j, k = l; // khởi tạo index của mảng với k = left (vì cái mảng này bắt đầu từ left chạy tới right)
    int n1 = m - l + 1; // số lượng phần tử của mảng bên trái
    int n2 = r - m; // số lượng phần tử của mảng bên phải
    int L[n1], R[n2]; // khởi tạo 2 mảng phụ với số lg phần tử tương ứng

    for(i = 0; i < n1; i++) L[i] = arr[l + i]; // gán giá trị của mảng cần sắp xếp cho mảng phụ
    // bắt đầu gán từ arr[left + i] vì mảng bên trái bắt đầu từ left

    for(j = 0; j < n2; j++) R[j] = arr[m + j + 1]; // gán giá trị của mảng cần sắp xếp cho mảng phụ còn lại
    // bắt đầu gán từ arr[mid + j + 1] vì mảng bên phải bắt đầu từ mid + 1

    i = 0; j = 0; // khởi tạo lại giá trị biến đếm
    while(i < n1 && j < n2) arr[k++] = (L[i] <= R[j])?L[i++]:R[j++];
    // bắt đầu từ left, so sánh Left[0] và Right [0], bé hơn thì arr[k] = Left[0] và so sánh Left[1] với Right[0]
    // lớn hơn thì gán arr[k++] = Right[0] và tiếp tục so sánh Left[1] với Right[1]
    // đoạn này trong img sẽ rõ hơn

    while(i < n1) arr[k++] = L[i++]; // gán các giá trị còn lại ở mảng Left (chưa được so sánh) vào mảng chính
    while(j < n2) arr[k++] = R[j++]; // tương tự ở mảng Right
}

void mergeSort(int arr[], int l, int r){ // left & right
    if(l < r){
        int m = l + (r - l)/2; // lấy vị trí ở giữa mảng (mid) dựa vào left & right
        mergeSort(arr, l, m); // mergesort cho mảng bên trái - từ left -> mid
        mergeSort(arr, m + 1, r); // mergesort cho mảng bên phải - từ mid + 1 -> right
        merge(arr, l, m, r); // merge 2 mảng lại với nhau
    }
}

main(){
    int a[] = {2,4,2,1,5,8,3,2,17,5,9,28};
    int len = sizeof(a) / sizeof(int);
    int i = 0, k = 0;
    while(i < len) cout << a[i++] << " "; // in mảng trước khi sx
    cout << endl;
    mergeSort(a, 0, len - 1); // sort
    i = 0;
    while(i < len) cout << a[i++] << " "; // sau sx
}