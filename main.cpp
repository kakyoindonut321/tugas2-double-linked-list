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

Node *searching(Node *head, int key)
{

    Node *bantu = head;
    while (bantu != NULL)
    {
        if (bantu->data == key)
        {
            return bantu;
        }
        bantu = bantu->next;
    }
    return NULL;
}

void sisipnodetengah(Node *nodekiri, int data)
{

    if (nodekiri == NULL)
    {
        cout << "Node tidak ada " << endl;
    }

    Node *newNode = buatnode(data);
    newNode->next = nodekiri->next;
    newNode->prev = nodekiri;

    if (nodekiri->next != NULL)
    {
        nodekiri->next->prev = newNode;
    }
    nodekiri->next = newNode;
}

void hapusnodedepan(Node **head)
{

    if (*head == NULL)
    {
        cout << "List Kosong" << endl;
        return;
    }

    Node *bantu = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(bantu);
}

void hapusnodebelakang(Node **head)
{

    if (*head == NULL)
    {
        cout << "List Kosong" << endl;
        return;
    }
    Node *bantu = *head;
    while (bantu->next != NULL)
    {
        bantu = bantu->next;
    }
    if (bantu->prev != NULL)
    {
        bantu->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }
    free(bantu);
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

void printdaribelakang(Node *head)
{

    if (head == NULL)
    {
        cout << "Node nya ga ada!" << endl;
        return;
    }
    Node *bantu = head;
    while (bantu->next != NULL)
    { // buat jalan ke ujung list
        bantu = bantu->next;
    }
    while (bantu != NULL)
    { // buat jalan dari belakang ke depan

        cout << bantu->data << " ";
        bantu = bantu->prev;
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
    buatnode(10);
    Node *head = NULL;
    sisipnodedepan(&head, 8);
    sisipnodedepan(&head, 7);
    sisipnodedepan(&head, 3);
    sisipnodetengah(searching(head, 3), 5);
    sisipnodedepan(&head, 10);
    sisipnodebelakang(&head, 6);
    // hapusnodebelakang(&head);
    // hapusnodetengah(&head, 3);
    hapusnodebelakang(&head);
    printdaridepan(head);

    int data;
    cout << "end";
    cin >> data;
}