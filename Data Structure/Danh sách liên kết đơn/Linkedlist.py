class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        
class LinkedList:
    def __init__(self):
        self.head=None
        self.N=0
        
    def insertFirst(self,new_data):
        new_node=Node(new_data)
        new_node.next=self.head
        self.head=new_node
        self.N+=1

        
    def insertLast(self,new_data):
        new_node=Node(new_data)

        if self.head is None:
            self.head=new_node
            self.N+=1
        else:
            last=self.head
            while last.next!=None:
                last=last.next
            last.next=new_node
            self.N+=1
    
    def inserMiddle(self,new_data,pos):
        if pos<=0 or pos>self.N+1:
            print("Invalid")
            return
        else:
            if pos==1:
                self.insertFirst(new_data)
            elif pos==self.N+1:
                self.insertLast(new_data)
            else:
                middle=self.head
                for i in range(1,pos):
                    middle=middle.next
                
                new_node=Node(new_data)
                new_node.next=middle.next
                middle.next=new_node
                
    def deleteNode(self, key):
         
        # Store head node
        temp = self.head
 
        # If head node itself holds the key to be deleted
        if (temp is not None):
            if (temp.data == key):
                self.head = temp.next
                temp = None
                return
 
        # Search for the key to be deleted, keep track of the
        # previous node as we need to change 'prev.next'
        while(temp is not None):
            if temp.data == key:
                break
            prev = temp
            temp = temp.next
 
        # if key was not present in linked list
        if(temp == None):
            return
 
        # Unlink the node from linked list
        prev.next = temp.next
 
        temp = None
    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data,end=" ")
            temp = temp.next   
