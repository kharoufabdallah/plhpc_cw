#ifndef INTCONTAINER_HPP
#define INTCONTAINER_HPP

// Libraries 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef BASE_CLASS_INC
#include "Container.hpp"
#endif 

#define DEFAULT_CAPACITY 100

class IntContainer: public CONTAINER::Container{
private:
    int* data;
    
    void CreateContainer(CONTAINER::ContainerType type = CONTAINER::ContainerType::Int, int capacity = DEFAULT_CAPACITY) override;    
    void DeallocateContainer() override; 

public:
    IntContainer(const int capacity);
    ~IntContainer(); 
    int GetCapacity() const override;
    CONTAINER::ContainerType GetContainerType() const override;
    void AddElements(int number_elements, int* elements) override;
    void AddElements(int number) override; // this function is overloaded and overridden 
    int GetNumberStored() override;
    int GetElementFreq(int element) override;
    void Resize() override;
    void PrintContainer();
};

#endif
