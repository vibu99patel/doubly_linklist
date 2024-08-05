#include "IntDList.hpp"
#include <iomanip>
#include <sstream>

// constructor 
IntDLList::IntDLList()
{
    ListHead = nullptr;
}

// destructor 
IntDLList::~IntDLList() 
{
    // creating a node 
    IntDLLNode *curr = ListHead;
    // iterating through the list and deleting each node 
    while (curr != nullptr) {
        IntDLLNode *next = curr->next;
        delete curr;
        curr = next;
        }
} 

void IntDLList::addToHead(int n)
{
    // creating a new node 
    IntDLLNode *newNode = new IntDLLNode(n);
    // checking if the list is empty 
    if (!ListHead)
    {
        ListHead = newNode;
    }
    // if non-empty list
    else
    {
        newNode->next = ListHead;
        ListHead->prev = newNode;
        ListHead = newNode;
    }
}

void IntDLList::insertInOrder(int n)
{
    // creating a new node 
    IntDLLNode *newNode = new IntDLLNode(n);
    // checking if the list is empty or inserting in the first position 
    if (ListHead == nullptr || n < ListHead->info) {
        newNode->next = ListHead;
        newNode->prev = nullptr;
        // if head is not empty 
        if (ListHead != nullptr) {
            ListHead->prev = newNode;
        }
        ListHead = newNode;
    } else {
        // creating a new node 
        IntDLLNode *curr = ListHead;
        // searching for the place to insert the node to keep list in order
        while (curr->next != nullptr && curr->next->info < n) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        // if the insertion node is not the last node 
        if (curr->next != nullptr) {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
    }

}

void IntDLList::addToTail(int n)
{
    // creating a new node 
    IntDLLNode *newNode = new IntDLLNode(n);
    // if list is empty 
    if (!ListHead)
    {
        ListHead = newNode;
        newNode->prev = nullptr;
    }
    else
    {
        // creating a new node 
        IntDLLNode *curr = ListHead;
        // iterating through the list till it reaches the tail
        while (curr->next)
        {
            curr = curr->next;
        }
        // adding the new node 
        curr->next = newNode;
        newNode->prev = curr;
    }
}

int IntDLList::deleteFromHead() // delete the head and return its info;
{
    if (ListHead)
    {
        // creating a new node 
        IntDLLNode *temp = ListHead;
        int val = temp->info;
        // updating the head node and deleting the first node 
        ListHead = ListHead->next;
        if (ListHead)
        {
            ListHead->prev = nullptr;
        }
        delete temp;
        // returning the deleted value
        return val;
    }
    return 0;
}

int IntDLList::deleteFromTail() // delete the tail and return its info;
{
    if (ListHead)
    {
        // if head == tail or if its the only node in the list 
        if (!ListHead->next)
        {
            int tail = ListHead->info;
            delete ListHead;
            ListHead = nullptr;
            return tail;
        }
        else
        {
            // creating a new node 
            IntDLLNode *curr = ListHead;
            // iterating through list 
            while (curr->next->next)
            {
                curr = curr->next;
            }
            // saving the info of tail and deleting the tail node
            int tail = curr->next->info;
            delete curr->next;
            curr->next = nullptr;
            // returning the value 
            return tail; 
        }
    }
    return 0;
}

void IntDLList::deleteNode(int n)
{
    //creating two pointers 
    IntDLLNode *curr = ListHead;
    IntDLLNode *prev = nullptr;
    // iterating through the list to find the correct node to delete
    while (curr != nullptr && curr->info != n) {
        prev = curr;
        curr = curr->next;
    }
    // checking if the node found is empty 
    if (curr != nullptr) {
        // if its the first node 
        if (curr == ListHead) {
            ListHead = curr->next;
        } 
        // keeping the prev pointer in check if head is not empty
        if (ListHead != nullptr) {
            ListHead->prev = nullptr;
        } else {
            // skipping the node to be deleted  
            prev->next = curr->next;
            // updating prev pointer if its not the last node 
            if (curr->next != nullptr) {
                curr->next->prev = prev;
            }
        }
        delete curr;
    }
}

bool IntDLList::isInList(int n) const
{
    // creating a node 
    IntDLLNode *curr = ListHead;
    // iterating through the list and searching for the info number is in the list 
    while (curr != nullptr) {
        if (curr->info == n) {
            return true;
        }
        curr = curr->next;
    }
    // if the number is not in the list 
    return false;
    
}

string IntDLList::addToString() const
{
    stringstream ss;
    // creating a node 
    IntDLLNode *curr = ListHead;
    // iterating through the list and converting it to a string 
    while (curr != nullptr) {
        ss << setw(0) << curr->info;
        curr = curr->next;
    }
    // returning the string 
    return ss.str();
}