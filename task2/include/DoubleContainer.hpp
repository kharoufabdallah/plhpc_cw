#ifndef DOUBLE_CONTAINER 
#define DOUBLE_CONTAINER 

#ifndef LIBS_INC
#define LIBS_INC 

// Libraries 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#endif 

#ifndef BASE_CLASS_INC
#include "Container.hpp"
#endif 


class DoubleContainer: public CONTAINER::Container {
    private: 
        double* data;
        void DeallocateContainer() override;
        void CreateContainer(CONTAINER::ContainerType container_type, int capacity) override; 

    public: 
        DoubleContainer(const int capacity);
        ~DoubleContainer();
        int GetCapacity() const override; 
        CONTAINER::ContainerType GetContainerType() const override;
        void AddElements(int number_elements, double* elements); // this is an overloaded function not an overridden
        void AddElements(double element); // overloaded not overriden
        int GetNumberStored() override; 
        int GetElementFreq(double element); // this is an overloaded function not an overridden
        void Resize();
        void PrintContainer();
        

};

#endif 
