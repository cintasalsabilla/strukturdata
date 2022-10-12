#include<iostream>
using namespace std;
#define MAX 8

struct Antrian {
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void create();
bool isEmpty();
bool isFull();
void enqueue(int);
int dequeue();
void tampil();
void menu();

int main(){

    create();
    menu();

    return 0;
}

void create(){
    antre.head = antre.tail =-1;
}

bool isEmpty(){
    if(antre.tail == -1){
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(){
    if(antre.tail == MAX - 1){
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int data){
    if(isEmpty()){
        antre.head = antre.tail = 0;
        antre.data[antre.tail] = data;
    }
    else
    {
        antre.tail++;
        antre.data[antre.tail] = data;
    }
    cout<<data<<" Dimasukkan Ke Antrian";
}

int dequeue(){
    int i;
    int e = antre.data[antre.head];
    for(i = antre.head;i < antre.tail;i++){
        antre.data[i] = antre.data[i+1];
    }
    antre.tail--;
    return e;
}

void tampil(){
    if(isEmpty()){
        cout<<"Data Kosong";
    }
    else{

        for(int i = antre.head;i <= antre.tail;i++){
            cout << antre.data[i] << " ";
        }
    }
}

void menu()
{

    int opsi, angka;


    do{

        cout << "===MENU===" << endl;
        cout << "1. Masukkan Antrian" << endl;
        cout << "2. Menyelesaikan Antrian" << endl;
        cout << "3. Menampilkan Antrian" << endl;
        cout << "4. Mengecheck Antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "\n\n\n";
        cout << "Pilih menu : ";cin>>opsi;


        switch (opsi)
        {
        case 1:
            cout << "Isi Nomor Antrian ";cin>>angka;
            enqueue(angka);
            cout << "\n\n\n";
            break;
        case 2:
            cout << "Antrian " << dequeue() << " Selesai" << endl;
            cout << "\n\n\n";
            break;
        case 3:
            if (isEmpty()!=true)
            {
                cout << "Antrian Yang Masih Tersedia ";tampil();
                cout << "\n\n";
            }
            else{
                cout << "Masih Kosong" << endl;
                cout << "\n\n";
            }

            break;
        case 4:
            if (isFull())
            {
                cout << "Antrian Telah Penuh! " << endl;
                cout << "\n\n";
            }
            else if(isEmpty())
            {
                cout << "Antrian Masih Kosong! " << endl;
                cout << "\n\n";
            }
            else{
                cout << "Ada Isinya Tapi Tidak Penuh" << endl;
                cout << "\n\n";
            }
            break;
        case 5:
            cout << "\n\n\n";
            break;
        default:
            cout << "Input Tidak Valid" << endl;
            cout << "\n\n\n";


        }



    }while(opsi!=5);


}
