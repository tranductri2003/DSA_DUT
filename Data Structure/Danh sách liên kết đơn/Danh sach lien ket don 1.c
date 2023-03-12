#include <stdio.h>

//  Khai báo một node ở dạng đơn giản nhất
struct Node
{ 
    int data; //Dữ liệu của node
    struct Node *next; //Con trỏ kiểu Node tên là next lưu trữ vị trí của Node tiếp theo trong danh sách liên kết đơn
};

// Được cấp phát dộng nên đây là con trỏ kiểu Node
typedef struct Node* listNode; 
// Mỗi con trỏ listNode
// Mỗi listNode là một node trong danh sách (một con trỏ) 


