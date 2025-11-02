#ifndef FLOAT_CONTAINER 
#define FLOAT_CONTAINER 

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


class FloatContainer: public CONTAINER::Container {
    private: 
        float* data;
        void DeallocateContainer() override;
        void CreateContainer(CONTAINER::ContainerType container_type, int capacity) override; 

    public: 
        FloatContainer(const int capacity);
        ~FloatContainer();
        int GetCapacity() const override; 
        CONTAINER::ContainerType GetContainerType() const override;
        void AddElements(int number_elements, float* elements); // this is an overloaded function not an overridden
        void AddElements(float element); // overloaded not overriden
        int GetNumberStored() override; 
        int GetElementFreq(float element); // this is an overloaded function not an overridden
        void Resize();
        void PrintContainer();
        

};

#endif 
