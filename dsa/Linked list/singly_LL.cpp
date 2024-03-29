#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        //constructor method- it is same name as of class
        //it doesn't have any return type
        //it will initialize data and give it a value
        //it will be called automatically
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head,int val){

    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        return;
    }

    // we will create a temp pointer which will first point to head than we will keep moving/iterating it using next pointers till temp will start pointing to null

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(Node* &head,int val){
    
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void searchKey(Node* head,int key){
    Node* temp = head;
    int y = 0;
    while(temp != NULL){
        if(temp->data == key){
            cout<<"True"<<endl;
            y+=1;
            break;
        }
        temp = temp->next;
    }
    if(y == 0){
        cout<<"False"<<endl;
    }
}

void deletion(Node* &head, int val){
    Node* temp = head;

    if(head == NULL){
        return;
    }

    if(head->data == val){
        head = head->next;
        delete temp;
        return;
    }

    while(temp->next->data != val){
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void del(Node* &head, int val){
    Node* temp = head;

    if(temp == NULL){
        cout << "List is empty\n";
        return;
    }
    if(temp->data == val){
        head = head->next;
        cout << "data deleted: " << val << endl;
        delete temp;
        return;
    }
    bool f = true;
    while(temp->next){
        if(temp->next->data == val){
            Node* n = temp->next;
            temp->next = temp->next->next;
            cout << "data deleted: " << val << endl;
            delete n;
            f=false;
            break;
        }
        temp = temp->next;
    }
    if(f){
        cout<<"Data not found."<<endl;
    }
    return;
}

void display(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

Node* kReverse(Node* &head, int k){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int n = 0;
    while(curr != NULL && n < k){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        n++;
    }

    if(next != NULL){
        head->next = kReverse(next,k);
    }

    return prev;
}

int main(){
    int key,k;
    //int del;
    Node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,10);
    insertAtHead(head,20);

    // display(head);
    // cout<<"\nEnter key: ";
    // cin>>key;
    // searchKey(head,key);
    // cout<<"Enter element to be deleted: ";
    // cin>>del;
    // deletion(head,del);
    // display(head);
    // cout<<endl<<"Reversed array: \n";
    // display(reverse(head));
    // cout<<endl<<"Enter value of k: ";
    // cin>>k;
    // display(kReverse(head,k));

    int n;
    display(head);
    cin>>n;
    del(head,n);
    display(head);
}