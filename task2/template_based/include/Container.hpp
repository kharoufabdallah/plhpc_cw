#pragma once 
#include <iostream> 

enum class CREATION_t {FIRST, REALLOC};

template <typename T> 
class Container {
public: 
    Container(int capacity);
    ~Container(); 
    void AddElements(int number, T* number_list); 
    void AddElements(T number);
    int GetNumberStored();
    
    // access element by its index
    T GetElement(int index);
    void Resize();
    int GetElementFreq(T element);
    int GetCapacity(); 
    void PrintContainer();        
private: 
    int capacity;
    bool first_fill;
    int number_of_elements_inserted;
    T* data;
    
    void CreateContainer(CREATION_t type);
    void IncrementSize(int how_many=1);
};
#include "../src/Container.tpp"
