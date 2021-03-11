#include <iostream>
using namespace std;
int heap_size = 0;
int n=20;
const int INF = 100000;

int get_right_child(int A[], int index) 
{
  if((((2*index)+1) < n) && (index >= 1))
    return (2*index)+1;
  return -1;
}

int get_left_child(int A[], int index) 
{
    if(((2*index) < n) && (index >= 1))
        return 2*index;
    return -1;
}

int get_parent(int A[], int index)
 {

  if ((index > 1) && (index < n))
   {
    return index/2;
  }
  return -1;
}
void swap( int *a, int *b )
 {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void max_heapify(int A[], int index)
 {
  int left_child_index = get_left_child(A, index);
  int right_child_index = get_right_child(A, index);
  int largest = index;
  if ((left_child_index <= heap_size) && (left_child_index>0))
   {
    if (A[left_child_index] > A[largest])
	 {
      largest = left_child_index;
    }
  }
  if ((right_child_index <= heap_size && (right_child_index>0))) 
  {
    if (A[right_child_index] > A[largest]) 
	{
      largest = right_child_index;
    }
  }

  // largest is not the node, node is not a heap
  if (largest != index) {
    swap(&A[index], &A[largest]);
    max_heapify(A, largest);
  }
}

void build_max_heap(int A[]) 
{
  int i;
  for(i=heap_size/2; i>=1; i--) 
  {
    max_heapify(A, i);
  }
}
int extract_max(int A[]) 
{
  int max = A[1];
  A[1] = A[heap_size];
  heap_size--;
  max_heapify(A, 1);
  return max;
}

void insertion(int A[], int index, int key) 
{
  A[index] = key;
  while((index>1) && (A[get_parent(A, index)] < A[index])) 
  {
    swap(&A[index], &A[get_parent(A, index)]);
    index = get_parent(A, index);
  }
}
void insert(int A[], int key)
 {
  heap_size++;
  A[heap_size] = -1*INF;
  insertion(A, heap_size, key);
}

void print_heap(int A[])
 {
  int i;
  for(i=1; i<=heap_size; i++)
   {
    cout<<A[i]<<" ";
  }
  cout<<endl;
 }
 int main() 
 {
  int A[n];
  int m,v;
  cout<<"number of elements in queue: ";
  cin>>m;
  for(int i=0;i<m;i++)
  {
  	cin>>v;
  	insert(A,v);
  }
  cout<<" max heap is: ";
  print_heap(A);
  cout<<"\n maximum queue is: ";
for(int i=0;i<m;i++)
  cout<<extract_max(A)<<" ";
  return 0;
}
//  15 10 20 27 17 7 5 12 19
