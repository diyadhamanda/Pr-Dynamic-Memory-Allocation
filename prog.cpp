// Develop a simple curd operation in linked list  with the help of cpp that will hhelp you to understand the system and memory to provide dynamically.//

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    int size;
    Node *head;

    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    void insertAtbeginning(int data)
    {
        Node *newnode = new Node(data);
        newnode->next = this->head;
        head = newnode;
        this->size++;
    }

    void search(int index)
    {
        if (index >= 0 && index < size)
        {
            Node *ptr = this->head;
            for (int i = 0; i < index; i++)
            {
                ptr = ptr->next;
            }
            cout << "Value at index " << index << " is: " << ptr->data << endl;
        }
        else
        {
            cout << "out of thr range ! " << endl;
        }
    }

    void DeleteNode(int value)
    {
        if (head == NULL)
        {
           cout<<"List is Empty ";
           return;
        }
        if (head->data == value)
        {
            Node *ptr = this->head;
            this->head = head->next;
            delete ptr;

            cout<<"Delete Node with Value ["<<value<<"] delete";
            return;
        }

        Node *current = this->head;
        Node *prev = NULL;
        
        while (current != NULL && current->data != value)
        {
            prev = current;
            current = current->next;
        }

        if (current == NULL)
        {
           cout<<"Delete Node with Value ["<<value<<"] delete";
           delete current;
        }

        prev->next = current->next;
        delete current;

            cout<<"Delete Node with Value ["<<value<<"] delete";
            return;
        
    }
    void reverse()
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        this->head = prev;

    }

    void displaylist()
    {
       
        Node *ptr = this->head;
        cout << "Linked list: ";

        while (ptr != NULL)
        {
            cout << ptr->data << "  ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    int choice, index, element;

    do
    {
        cout << endl<< "-------------------------------" << endl;
        cout << endl;
        cout << "Enter 1 for insert at beginning " << endl;
        cout << "Enter 2 for search in List " << endl;
        cout << "Enter 3 for Delete Node from the List " << endl;
        cout << "Enter 4 for Reverse in the List " << endl;
        cout << "Enter 5 for Display the list " << endl;
        cout << "Enter 0 for Exit " << endl;
        cout << endl;
        cout << "Enter your Choice ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Insert in the Beginning ";
            cin >> element;
            list.insertAtbeginning(element);
            break;

        case 2:
            cout << "Enter Index for Search ";
            cin >> index;
            list.search(index);
            break;

        case 3:
            cout << "Enter value for Delete ";
            cin >>element;
            list.DeleteNode(element);
            break;

        case 4:
            list.reverse();
            break;

        case 5:
            list.displaylist();
            break;

        case 0:
            cout << "Exiting from the List" << endl;
            break;

        default:
            cout << "wrong choice ! " << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}