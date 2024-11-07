#include <iostream>

using namespace std;

// Dinh nghia Node
struct Node
{
  int data;
  Node *next;

  Node (int val) : data (val), next (nullptr) {}
};

// Tao danh sach lien ket vong voi N nguoi
Node *
create_loop (int N)
{
  Node *head = new Node (1);
  Node *prev = head;

  for (int i = 2; i <= N; i++)
    {
      Node *newNode = new Node (i);
      prev->next = newNode;
      prev = newNode;
    }

  prev->next = head; // Noi vong

  return head;
}

// Ham loai bo nguoi thua cuoc va tra ve nguoi thang cuoc
int
find_winner (Node *head, int N, int M)
{
  Node *current = head;
  Node *prev = nullptr;

  while (N > 1)
    {

      for (int i = 0; i < M - 1; i++)
        {
          prev = current;
          current = current->next;
        }

      prev->next = current->next;
      Node *temp = current;
      current = current->next;
      delete temp;
      N--;
    }

  return current->data;
}

int
main ()
{
  int N, M;

  cout << "Nhap N: ";
  cin >> N;
  cout << "\nNhap M: ";
  cin >> M;

  Node *head = create_loop (N);
  int winner = find_winner (head, N, M);

  cout << "Nguoi chien thang cuoi cung khi N = " << N << " va M = " << M
       << " la nguoi so: " << winner << endl;

  return 0;
}
