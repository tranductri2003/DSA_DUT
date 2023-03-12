class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        
class ListNode:
    def __init__(self,val):
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
            
class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head1=l1
        num1=[]
        while head1!=None:
            num1.append(head1.val)
            head1=head1.next
        
        head2=l2
        num2=[]
        while head2!=None:
            num2.append(head2.val)
            head2=head2.next

        num1=num1[::-1]
        num2=num2[::-1]
        for i in range(len(num1)):
            num1[i] = str(num1[i])
        for i in range(len(num2)):
            num2[i] = str(num2[i])
                
        num1=int("".join(num1))
        num2=int("".join(num2))

        res=num1+num2
        res=str(res)[::-1]
        res=list(res)

        for i in range(len(res)):
            res[i] = int(res[i])
        
        ans=ListNode()
        for num in res:
            ans.insertLast(num)
        
        ans.printList()

