#include <iostream>

using namespace std;

// deklarasi single linked list
struct Buku{

// komponen / member
string judul, pengarang;
int tahunTerbit;

Buku *next;

};

Buku *head, *tail, *cur, *newNode, *del, *Before;

// create singlee linked list
void createsinglelinkedlist(string judul, string pengarang, int tB){
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
    head->next = NULL;
    tail = head;
}

// print singlee linked list
int countsingleLinkedList(){    
    cur = head;
    int jumlah = 0;
    while( cur != NULL ){
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
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

// tambah tengah single linked list
void addMiddle(string judul, string pengarang, int tB, int posisi){
    if( posisi < 1 || posisi >countsingleLinkedList() ){
        cout << "posisi diluar jangkauan" << endl;


    }else if( posisi == 1){
        cout << "posisi bukan posisi tengah" << endl;
    }else{
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    
    // tranversiing
    cur = head;
    int nomor = 1;
    while(nomor < posisi - 1){
        cur = cur->next;
        nomor++;
    }

    newNode->next = cur->next;
    cur->next = newNode;
    }
}

// remove middle
void removemiddle(int posisi){
    if( posisi < 1 || posisi >countsingleLinkedList() ){
        cout << "posisi diluar jangkauan" << endl;


    }else if( posisi == 1){
        cout << "posisi bukan posisi tengah" << endl;
    }else{
         int nomor = 1;
    cur = head;
    while( nomor <= posisi){
        if( nomor == posisi-1){
            Before = cur;
            }
        if( nomor == posisi ){
            del = cur;
        }

        cur = cur->next;
        nomor++;    

    }
    Before->next = cur;
    delete del;
    }
   
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

// ubahtengah singlee linked list
void changeMiddle(string judul, string pengarang, int tB, int posisi){
    if( posisi < 1  || posisi == countsingleLinkedList() ){
        cout << "posisi diluar jangkauan" << endl;


    }else if( posisi == 1 || posisi == countsingleLinkedList()  ){
        cout << "posisi bukan posisi tengah" << endl;
    }else{
       cur = head;
       int nomor = 1;
       while( nomor < posisi ){
        cur = cur->next;
        nomor++;
       }
       cur->judul = judul;
       cur->pengarang = pengarang;
       cur->tahunTerbit = tB;
    }
}


// print singlee linked list
void printsingleLinkedList(){
    cout << "jumlah data ada : " << countsingleLinkedList() << endl;    
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

  addMiddle("Bumi Manusia", "Pramoedya Anata Toer", 2005, 2);

  printsingleLinkedList();
  
  cout << "\n\n" << endl;

  addMiddle("Negeri 5 Menara", "Ahmad faudi", 2009, 2);

  printsingleLinkedList();
  
  cout << "\n\n" << endl;

  removemiddle(2);

 printsingleLinkedList();

changeMiddle("sang penghayal", "suranto", 2006, 2);

  printsingleLinkedList();
  
  cout << "\n\n" << endl;


}