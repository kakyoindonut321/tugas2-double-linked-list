#include <iostream>
using namespace std;

struct Node
{
    string judul;
    string penulis;
    Node *next;
    Node *prev;
};

struct Node *buatnode(string judul, string penulis)
{
    Node *newNode = new Node{judul, penulis, NULL, NULL};
    // Node *newNode = (Node *)malloc(sizeof(data));
    return newNode;
}

void sisipnodedepan(Node **head, string judul, string penulis)
{

    Node *newNode = buatnode(judul, penulis);
    newNode->next = *head;
    if (*head != NULL)
    {

        (*head)->prev = newNode;
    }
    *head = newNode;
}

void sisipnodebelakang(Node **head, string judul, string penulis)
{

    Node *newNode = buatnode(judul, penulis);
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

void hapusnodetengah(Node **head, string key)
{
    if (*head == NULL)
    {
        cout << "List Kosong" << endl;
        return;
    }

    Node *bantu = *head;
    while (bantu != NULL && bantu->judul != key)
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
    int i = 1;
    while (bantu != NULL)
    {
        cout << i << ". " << bantu->judul << " by " << bantu->penulis << endl;
        bantu = bantu->next;
        i += 1;
    }
    cout << endl;
}

main()
{
    // Node *head = NULL;
    // sisipnodedepan(&head, "berk", "kenmura");
    // sisipnodebelakang(&head, "villain soggy", "the guy");
    // sisipnodebelakang(&head, "narutod", "masahiro sakurai");
    // printdaridepan(head);
    // hapusnodetengah(&head, "narut");
    // printdaridepan(head);
    // printdaridepan(head);
    // printdaridepan(head);

    int pilihan;
    bool program = true;

    while (program)
    {
        cout << "=== MENU SISTEM PERPUSTAKAAN GURAMEDIA ===" << endl;

        cout << "1. Tambah Buku dari Depan List" << endl;
        cout << "2. Tambah Buku dari Belakang List" << endl;
        cout << "3. Hapus Judul bedasarkan Judul" << endl;
        cout << "4. Daftar Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi : ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan)
        {
        case 1:
        {
            cout << "== Tambah Buku dari Depan List ==" << endl;
            string tempjudul, temppenulis;

            break;
        }
        case 2:
        {
            cout << "== Tambah Buku dari Belakang List ==" << endl;
            break;
        }
        case 3:
        {
            cout << "== Hapus Judul bedasarkan Judul ==" << endl;
            break;
        }
        case 4:
        {
            cout << "== Daftar Buku ==" << endl;
            break;
        }
        case 5:
            program = false;
            break;
        default:
            cout << "Opsi invalid, ulang." << endl;
        }

        cout << endl;
    }

    cout << "Terimakasih terlah memakai Menu Sistem Perpustakaan Guramedia." << endl;
    return 0;
}