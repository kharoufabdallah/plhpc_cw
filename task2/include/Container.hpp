#ifndef CONTAINER_HPP
#define CONTAINER_HPP

// Libraries 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define DEFAULT_CAPACITY 100

namespace ERRORS {
    enum class ErrorType {ArgErr = 1};
}
    
// legend: if a name is capitilized, it means either a env param or a namespace
//TODO: if there are default argements, decalre them from here
namespace CONTAINER {
    enum class ContainerType {Int, Float, Double};
    
    class Container { // Abstract class
        public:
            // Constuctor and destrcuctor
            Container(const ContainerType type, int capacity);
            // overloaded constructor
            // Container(); 
            virtual ~Container();


            // getters
            
            // PURE virtual function
            //// this method returns the current max capacity of a container
            virtual int GetCapacity() const = 0; 

            // this method return the container's data type
            virtual ContainerType GetContainerType() const; 
            
            virtual void AddElements(int num_elements, int* elements);
            
            // an overloaded function of Adding one element instead of adding size of 1 and then 1 element in a whole array
            virtual void AddElements(int element);

            // this method returns the number of stored elements in a container
            virtual int GetNumberStored();

            // this method return the frequency of an item (should declare its data type
            // in method implementation) in a container if existed
            virtual int GetElementFreq(int element);  

            // general methods
            virtual void Resize(); // this is used to resize the container 

        protected:
            ContainerType container_type;
            int capacity; 

            virtual void CreateContainer(ContainerType container_type, int capacity);
            virtual void DeallocateContainer();
    };
}

#endif
