#include "Container.hpp"

template <typename T> 
Container<T>::Container(int capacity) {
    this->capacity = capacity;
    this->first_fill = false;
    this->number_of_elements_inserted = 0;
    this->CreateContainer();
}
template <typename T> 
Container<T>::~Container() {
    delete[] this->data;
    this->data = nullptr;
}
template <typename T> 
void Container<T>::CreateContainer() {
    this->data = new T[this->capacity];
};
template <typename T> 
void Container<T>::IncrementSize(int how_many) {
    this->number_of_elements_inserted+=how_many; 
};
template <typename T> 
void Container<T>::AddElements(T number) {
    if (this->data != nullptr and this->GetNumberStored() + 1 < this->GetCapacity()) {
            this->data[this->GetNumberStored()] = number;
            first_fill = !first_fill? true : first_fill;
            this->IncrementSize(1);
        }
     else {
        this->Resize();
        this->AddElements(number);
     }

}
template <typename T> 
void Container<T>::AddElements(int number, T* number_list) {
    if (number + this->GetNumberStored() < capacity) {
        int last_cell_filled = this->GetNumberStored();
        for (int i = 0; i < number; i++) {
            this->data[last_cell_filled+i] = number_list[i];
            first_fill = !first_fill? true : first_fill;
            this->IncrementSize(number);
        }
    } else {
        this->Resize();
        this->AddElements(number, number_list);
    } 
}
template <typename T> 
int Container<T>::GetCapacity() {
    return this->capacity;
};
template <typename T> 
int Container<T>::GetNumberStored() {
    /* int count = 0;
    for (int i = 0 i < this->GetCapacity() and first_fill; i++) {
        if this->data[i] > 0 
            count++;
    } */

    return this->number_of_elements_inserted;
}
template <typename T> 
T Container<T>::GetElement(int index) {
    return this->data[index];
}
template <typename T> 
int Container<T>::GetElementFreq(T element){
    int count = 0;
    for (int i = 0; i < this->GetNumberStored(); i++) 
        count = this->data[i] == element ? count + 1: count;
    return count;
};
template <typename T> 
void Container<T>::Resize() {
    this->capacity*=2;
    delete[] this->data;
    this->CreateContainer();
}
