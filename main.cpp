#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct Node *buatnode(int data)
{
    // Node* newNode = new Node{data, NULL, NULL}; (alternatif)
    Node *newNode = (Node *)malloc(sizeof(data));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void sisipnodedepan(Node **head, int data)
{

    Node *newNode = buatnode(data);
    newNode->next = *head;
    if (*head != NULL)
    {

        (*head)->prev = newNode;
    }
    *head = newNode;
}

void sisipnodebelakang(Node **head, int data)
{

    Node *newNode = buatnode(data);
    if (*head == NULL)
    {

        *head = newNode;
        return;
    }
    Node *bantu = *head;
    while (bantu->next != NULL)
    {
        bantu = bantu->next;
    }
    bantu->next = newNode;
    newNode->prev = bantu;
}

void hapusnodetengah(Node **head, int key)
{
    if (*head == NULL)
    {
        cout << "List Kosong" << endl;
        return;
    }

    Node *bantu = *head;
    while (bantu != NULL && bantu->data != key)
    {
        bantu = bantu->next;
    }

    if (bantu == NULL)
    {
        cout << "Node ga ketemu!" << endl;
        return;
    }

    if (bantu->prev != NULL)
    {
        bantu->prev->next = bantu->next;
    }
    else
    {
        *head = bantu->next;
    }
    if (bantu->next != NULL)
    {

        bantu->next->prev = bantu->prev;
    }

    free(bantu);
}

void printdaridepan(Node *head)
{

    if (head == NULL)
    {
        cout << "Node nya ga ada!" << endl;
    }
    Node *bantu = head;
    while (bantu != NULL)
    {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

void hapusnodespesifik(Node **head, int key)
{
    if (*head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
}

main()
{
    Node *head = NULL;
    sisipnodedepan(&head, 10);
    sisipnodebelakang(&head, 20);
    printdaridepan(head);
    // hapusnodetengah(&head, 10);
    // printdaridepan(head);
    // printdaridepan(head);

    int end;
    cout << "berhentikan...";
    cin >> end;
}