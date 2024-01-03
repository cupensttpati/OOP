#include <iostream>
#include <string>

using namespace std;

class Buku {
public:
    string judul, pengarang;
    int tahunTerbit;
    Buku* next;

    Buku() : next(nullptr) {}

    Buku(string judul, string pengarang, int tB) : judul(judul), pengarang(pengarang), tahunTerbit(tB), next(nullptr) {}
};

class LinkedList {
private:
    Buku* head;
    Buku* tail;
    Buku* cur;
    Buku* newNode;
    Buku* del;
    Buku* Before;

public:
    LinkedList() : head(nullptr), tail(nullptr), cur(nullptr), newNode(nullptr), del(nullptr), Before(nullptr) {}

    void createSingleLinkedList(string judul, string pengarang, int tB) {
        head = new Buku(judul, pengarang, tB);
        tail = head;
    }

    int countSingleLinkedList() {
        cur = head;
        int jumlah = 0;
        while (cur != nullptr) {
            jumlah++;
            cur = cur->next;
        }
        return jumlah;
    }

    void addFirst(string judul, string pengarang, int tB) {
        newNode = new Buku(judul, pengarang, tB);
        newNode->next = head;
        head = newNode;
    }

    void addLast(string judul, string pengarang, int tB) {
        newNode = new Buku(judul, pengarang, tB);
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }

    void addMiddle(string judul, string pengarang, int tB, int posisi) {
        if (posisi < 1 || posisi > countSingleLinkedList()) {
            cout << "posisi diluar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "posisi bukan posisi tengah" << endl;
        } else {
            newNode = new Buku(judul, pengarang, tB);
            cur = head;
            int nomor = 1;
            while (nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }

    void removeMiddle(int posisi) {
        if (posisi < 1 || posisi > countSingleLinkedList()) {
            cout << "posisi diluar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "posisi bukan posisi tengah" << endl;
        } else {
            int nomor = 1;
            cur = head;
            while (nomor <= posisi) {
                if (nomor == posisi - 1) {
                    Before = cur;
                }
                if (nomor == posisi) {
                    del = cur;
                }
                cur = cur->next;
                nomor++;
            }
            Before->next = cur;
            delete del;
        }
    }

    void removeFirst() {
        del = head;
        head = head->next;
        delete del;
    }

    void removeLast() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }

        del = tail;
        cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = nullptr;
        delete del;
    }

    void changeFirst(string judul, string pengarang, int tB) {
        head->judul = judul;
        head->pengarang = pengarang;
        head->tahunTerbit = tB;
    }

    void changeLast(string judul, string pengarang, int tB) {
        tail->judul = judul;
        tail->pengarang = pengarang;
        tail->tahunTerbit = tB;
    }

    void changeMiddle(string judul, string pengarang, int tB, int posisi) {
        if (posisi < 1 || posisi == countSingleLinkedList()) {
            cout << "posisi diluar jangkauan" << endl;
        } else if (posisi == 1 || posisi == countSingleLinkedList()) {
            cout << "posisi bukan posisi tengah" << endl;
        } else {
            cur = head;
            int nomor = 1;
            while (nomor < posisi) {
                cur = cur->next;
                nomor++;
            }
            cur->judul = judul;
            cur->pengarang = pengarang;
            cur->tahunTerbit = tB;
        }
    }

    void printSingleLinkedList() {
        cout << "jumlah data ada : " << countSingleLinkedList() << endl;
        cur = head;
        while (cur != nullptr) {
            cout << "Judul Buku : " << cur->judul << endl;
            cout << "Pengarang Buku : " << cur->pengarang << endl;
            cout << "Tahun Terbit : " << cur->tahunTerbit << endl;
            cur = cur->next;
        }
    }
};

int main() {
    LinkedList linkedList;

    linkedList.createSingleLinkedList("kata", "Gezz & Aan", 2018);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.addFirst("Dia adalah kakakku", "Tere Liye", 2009);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.addLast("Aroma Karsa", "Dee Lestari", 2018);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.removeFirst();
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.addLast("11.11", "Fiersa Besari", 2018);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.removeLast();
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.changeFirst("Berhenti di kamu", "Gia pratama", 2018);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.addMiddle("Bumi Manusia", "Pramoedya Anata Toer", 2005, 2);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.addMiddle("Negeri 5 Menara", "Ahmad faudi", 2009, 2);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.removeMiddle(2);
    linkedList.printSingleLinkedList();

    linkedList.changeMiddle("sang penghayal", "suranto", 2006, 2);
}