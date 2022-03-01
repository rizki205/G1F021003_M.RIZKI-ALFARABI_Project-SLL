#include <iostream>

using namespace std;

struct node{

  char data;

  node *next;
};

node *head, *tail, *cur, *newNode, *del, *before;

void createSingleLinkedList(char data){
  head = new node();
  head->data = data;
  head->next = NULL;
  tail = head;
}

int countSingleLinkedList(){
  cur = head;
  int jumlah = 0;
  while( cur != NULL ){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}

void addFirst(char data){
  newNode = new node();
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}

void addLast(char data){
  newNode = new node();
  newNode->data = data;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

void addMiddle(char data, int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    newNode = new node();
    newNode->data = data;

    cur = head;
    int nomor = 1;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
  }
}

void removeFirst(){
  del = head;
  head = head->next;
  delete del;
}

void removeLast(){
  del = tail;
  cur = head;
  while( cur->next != tail ){
    cur = cur->next;
  }
  tail = cur;
  tail->next = NULL;
  delete del;
}

void removeMiddle(int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    int nomor = 1;
    cur = head;
    while( nomor <= posisi ){
      if( nomor == posisi-1 ){
        before = cur;
      }
      if( nomor == posisi ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    before->next = cur;
    delete del;
  }
}

void printSingleLinkedList(){
  cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
  cur = head;
  while( cur != NULL ){
    cout << "Data : " << cur->data << endl;

    cur = cur->next;
  }
}

bool searchNode(node **head, int key)
{
    node *cur = *head;
    while (cur != NULL)
    {
        if (cur->data == key)
            return true;
        cur = cur->next;
    }
    return false;
}

int main(){
	cout << "Membuat data Single Linked List" << endl;
	createSingleLinkedList('c');
	printSingleLinkedList();
	cout << "\n" << endl;

	cout << "Insert First" << endl;
	addFirst('b');
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Insert Last" << endl;
	addLast('d');
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Delete First" << endl;
	removeFirst();
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Insert Last" << endl;
	addLast('e');
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Delete Last" << endl;
	removeLast();
	printSingleLinkedList();
	cout << "\n" << endl;

	cout << "Insert Before Data Ke-2" << endl;
	addMiddle('g', 2);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Insert Before Data Ke-2" << endl;
	addMiddle('h', 2);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Delete Before Data Ke-6" << endl;
	removeMiddle(6);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Delete Before Data Ke-4" << endl;
	removeMiddle(4);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	char key ='e';
	cout << "Searching Data : " << key << endl;
    if (searchNode(&head, key))
        cout << "Data " << key << " Ditemukan";
    else
        cout << "Data " << key << " Tidak Ditemukan";
}
