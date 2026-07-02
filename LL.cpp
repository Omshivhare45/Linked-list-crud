#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
};

// Insert at head
void iah(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

//insert at tail
void iat(Node* &tail, int d){
    Node* temp = new Node(d);

    tail -> next = temp;
    tail = temp;
}

//insert at mid;
void iam(Node* &head, Node* &tail, int pos, int d ){
    if( pos == 1 ){
        iah(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while( cnt != pos - 1 ){
        temp = temp -> next;
        cnt++;
    }

    if( temp == NULL ){
        iat(tail, d);
        return;
    }

    Node* iam = new Node(d);
    iam -> next = temp -> next;
    temp -> next = iam;
}

//printing
void print(Node* &head){
    Node* temp = head;

    while( temp != NULL ){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


//delete
void del(Node* &head,Node* &tail, int pos){
    if( head == NULL ){
        return;
    }

    if( pos == 1 ){
        Node*temp = head;
        head = head ->  next;
        delete temp;
        return;
    }

    Node* prev = head;
    int cnt = 1;

    while(cnt < pos - 1){
        prev = prev -> next;
        cnt++;
    }

    Node* curr = prev -> next;
    prev -> next = curr -> next;
    delete curr;

}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    iah(head, 10);
    print(head);
    iat(tail, 30);
    print(head);
    iam(head, tail, 2, 20);
    print(head);
    del(head, tail, 1);
    print(head);
}