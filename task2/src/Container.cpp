#include "Container.hpp"

CONTAINER::Container::Container(const ContainerType type, int capacity){
    this->container_type = type;
    this->capacity = capacity;
    this->CreateContainer(this->container_type, this->capacity);
}

CONTAINER::Container::~Container() {
    this->DeallocateContainer();
}

int CONTAINER::Container::GetCapacity() const {
    return this->capacity;
};

CONTAINER::ContainerType CONTAINER::Container::GetContainerType() const {
    return this->container_type;
};

void CONTAINER::Container::CreateContainer(ContainerType container_type, int capacity) { 
    try {
        switch(container_type) {
    
            case CONTAINER::ContainerType::Int:
                std::cout << "HELLO BUDDY"; 
                break;
            case CONTAINER::ContainerType::Float:
            
                break;
            case CONTAINER::ContainerType::Double:
        
                break;
            default: 
                // log and end
                throw std::invalid_argument("Invalid ContainerType argument");
        }
    }    
    catch (const std::invalid_argument &err)  {
        std::cerr << "ERROR: Container.cpp Invalid Arguemnt"; // ERRORS::ErrorType::ArgErr;
    } 
}

void CONTAINER::Container::DeallocateContainer() {}

void CONTAINER::Container::AddElements(int number_elements, int* elements) {} // const = 0;
void CONTAINER::Container::AddElements(int element) {} 
int CONTAINER::Container::GetNumberStored() {return 0;}
int CONTAINER::Container::GetElementFreq(int element) {return 0;}
void CONTAINER::Container::Resize() {
    this->capacity*=2; 
}

