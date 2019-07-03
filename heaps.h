#include <iostream>
#include <algorithm>
#include <vector>

#define INFINITE 1000000

using namespace std;

template <typename Type>
class Heap {
    protected:
        int heapsize;
        int capacity;
        Type *array;
        void swap(int, int);
        virtual void percolate_up(int) = 0;
        virtual void percolate_down(int) = 0;
        int get_parent(int index) { return (index != 0) ? (index-1)/2 : 0; }
        int right_child(int index) { return 2*index + 2; } 
        int left_child(int index) { return 2*index + 1; } 
    public:
        Heap(int);
        virtual void insert_key(Type) = 0;
        virtual void delete_key(int) = 0;
        virtual void decrease_key(int, Type) = 0;
        ~Heap();
};

template <typename Type>
Heap<Type>::Heap(int size){
    this->capacity = size;
    this->heapsize = 0;
    this->array = new Type[size];
}

template <typename Type>
void Heap<Type>::swap(int a, int b) {
    Type temp = array[a];
    array[a] = array[b];
    array[b] = temp;
} 

template <typename Type>
Heap<Type>::~Heap(){
    delete array;
}


template <typename Type>
class MinHeap : public Heap<Type> {
    private:
        int get_min_child(int);
        void percolate_up(int);
        void percolate_down(int);
        void build_heap();
    public:
        MinHeap(int size) : Heap<Type>(size) {}
        MinHeap(int size, Type *arr) ;
        Type extract_min();
        void decrease_key(int, Type);
        void insert_key(Type);
        void delete_key(int);
};

template <typename Type>
MinHeap<Type>::MinHeap(int size, Type *arr) : Heap<Type> (size) { 
	this->array = arr; 
	this->heapsize = size; 
	build_heap();
}

template <typename Type>
int MinHeap<Type>::get_min_child(int pos){
    int right_index = this->right_child(pos);
    int left_index = this->left_child(pos);
    if(right_index < this->heapsize) {
        Type right = this->array[right_index];
        Type left = this->array[left_index];
        if (right < left)
            return right_index;
        else
            return left_index;
    } else if (left_index < this->heapsize){
        return left_index;
    } else {
        return -1;
    }
}

template <typename Type>
void MinHeap<Type>::build_heap() {
	for(int i=0;i<this->heapsize/2;i++){
		percolate_down(i);
	}
}

template <typename Type>
void MinHeap<Type>::percolate_down(int index){
    int min_child = get_min_child(index);
    Type parent = this->array[index];
    if (min_child != -1){
        if (parent > this->array[min_child]){
            this->swap(index, min_child);
            percolate_down(min_child);
        }
    }
}

template <typename Type>
void MinHeap<Type>::percolate_up(int index) {
    int parent = this->get_parent(index);
    if(this->array[parent] > this->array[index]) {
        this->swap(index, parent);
        percolate_up(parent);
    }
}

template <typename Type>
void MinHeap<Type>::insert_key(Type key) {
    if (this->heapsize > this->capacity) {
        cout << "Exceeded heap capacity" << endl;
        return;
    }
    this->array[this->heapsize] = key;
    percolate_up(this->heapsize);
    this->heapsize++;
}

template <typename Type>
Type MinHeap<Type>::extract_min() {
    if (this->heapsize <= 0) {
        cout << "Heap is empty" << endl;
        return -1;
    } else {
        Type hmin = this->array[0];
        this->heapsize--;
        this->swap(0, this->heapsize);
        percolate_down(0);
        return hmin;
    }
}

template <typename Type>
void MinHeap<Type>::decrease_key(int index, Type value) {
    this->array[index] = value;
    percolate_up(index);
}

template <typename Type>
void MinHeap<Type>::delete_key(int index) {
    decrease_key(index, -INFINITE);
    Type k = extract_min();
}



template <typename Type>
class MaxHeap : public Heap<Type> {
    private:
        int get_max_child(int);
        void percolate_up(int);
        void percolate_down(int);
        void build_heap();
    public:
        MaxHeap(int size) : Heap<Type>(size) {}
        MaxHeap(int size, Type *arr) ;
        Type extract_max();
        void decrease_key(int, Type);
        void insert_key(Type);
        void delete_key(int);
};

template <typename Type>
MaxHeap<Type>::MaxHeap(int size, Type *arr) : Heap<Type> (size) { 
	this->array = arr; 
	this->heapsize = size; 
	build_heap();
}

template <typename Type>
int MaxHeap<Type>::get_max_child(int pos){
    int right_index = this->right_child(pos);
    int left_index = this->left_child(pos);
    if(right_index < this->heapsize) {
        Type right = this->array[right_index];
        Type left = this->array[left_index];
        if (right > left)
            return right_index;
        else
            return left_index;
    } else if (left_index < this->heapsize){
        return left_index;
    } else {
        return -1;
    }
}

template <typename Type>
void MaxHeap<Type>::build_heap() {
	for(int i=0;i<this->heapsize/2;i++){
		percolate_down(i);
	}
}

template <typename Type>
void MaxHeap<Type>::percolate_down(int index){
    int max_child = get_max_child(index);
    Type parent = this->array[index];
    if (max_child != -1){
        if (parent < this->array[max_child]){
            this->swap(index, max_child);
            percolate_down(max_child);
        }
    }
}

template <typename Type>
void MaxHeap<Type>::percolate_up(int index) {
    int parent = this->get_parent(index);
    if(this->array[parent] < this->array[index]) {
        this->swap(index, parent);
        percolate_up(parent);
    }
}

template <typename Type>
void MaxHeap<Type>::insert_key(Type key) {
    if (this->heapsize > this->capacity) {
        cout << "Exceeded heap capacity" << endl;
        return;
    }
    this->array[this->heapsize] = key;
    percolate_up(this->heapsize);
    this->heapsize++;
}

template <typename Type>
Type MaxHeap<Type>::extract_max() {
    if (this->heapsize <= 0) {
        cout << "Heap is empty" << endl;
        return -1;
    } else {
        Type hmax = this->array[0];
        this->heapsize--;
        this->swap(0, this->heapsize);
        percolate_down(0);
        return hmax;
    }
}

template <typename Type>
void MaxHeap<Type>::decrease_key(int index, Type value) {
    this->array[index] = value;
    percolate_up(index);
}

template <typename Type>
void MaxHeap<Type>::delete_key(int index) {
    decrease_key(index, INFINITE);
    Type k = extract_max();
}
