#include <iostream>

using namespace std;

// deklarasi single linked list
struct Buku{

// komponen / member
string judul, pengarang;
int tahunTerbit;

Buku *next;

};

Buku *head, *tail, *cur, *newNode, *del;

// create singlee linked list
void createsinglelinkedlist(string judul, string pengarang, int tB){
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
    head->next = NULL;
    tail = head;
}

// tambahAwal single linked list
void addfirst(string judul, string pengarang, int tB){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = head;
    head = newNode;
    
}

// tambahAkhir single linked list
void addLast(string judul, string pengarang, int tB){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
    
}

// Remove First
void removeFirst(){
    del = head;
    head = head->next;
    delete del;
}

// Remove Last
void removeLast(){
    del = tail;
    head = head;
    while( cur->next != tail ){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

// ubahAwal singlee linked list
void changefirst(string judul, string pengarang, int tB){
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
}

// ubahAkhir singlee linked list
void changelast(string judul, string pengarang, int tB){
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tB;
}

// print singlee linked list
void printsingleLinkedList(){    
    cur = head;
    while( cur != NULL){
      cout << "Judul Buku : " << cur->judul << endl;
      cout << "Pengarang Buku : " << cur->pengarang << endl;
      cout << "Tahun Terbit : " << cur->tahunTerbit << endl;

    cur = cur->next;
    }
}
int main(){

  createsinglelinkedlist("kata", "Gezz & Aan", 2018);

  printsingleLinkedList();

  cout << "\n\n" << endl;

  addfirst("Dia adalah kakakku", "Tere Liye", 2009);
  
  printsingleLinkedList();
  
  cout << "\n\n" << endl;

  addLast("Aroma Karsa", "Dee Lestari", 2018);
  
  printsingleLinkedList();
  
  cout << "\n\n" << endl;
  
  removeFirst();

  printsingleLinkedList();
  
  cout << "\n\n" << endl;

  addLast("11.11", "Fiersa Besari", 2018);
  
  printsingleLinkedList();
  
  cout << "\n\n" << endl;

  removeLast();

  printsingleLinkedList();
  
  cout << "\n\n" << endl;

  changefirst("Berhenti di kamu", "Gia pratama", 2018);

  
  printsingleLinkedList();
  
  cout << "\n\n" << endl;

}