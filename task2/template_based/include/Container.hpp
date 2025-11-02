#pragma once 
#include <iostream> 


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
        
private: 
    int capacity;
    bool first_fill;
    int number_of_elements_inserted;
    T* data;
    int GetCapacity(); 
    void CreateContainer();
    void IncrementSize(int how_many=1);
};
#include "../src/Container.tpp"
