#include "IntContainer.hpp"

IntContainer::IntContainer(const int capacity): CONTAINER::Container(CONTAINER::ContainerType::Int, capacity) {
    // CONTAINER::Container(CONTAINER::ContainerType::Int, capacity);
    this->container_type = CONTAINER::ContainerType::Int;
    this->capacity = capacity;
    IntContainer::CreateContainer(CONTAINER::ContainerType::Int, capacity);
}

IntContainer::~IntContainer() {
    IntContainer::DeallocateContainer();
    CONTAINER::Container::~Container(); 
    std::cout << "Memory is FREE :)\n";
}

void IntContainer::CreateContainer(CONTAINER::ContainerType type, int capacity) {
         this->data = new int[capacity];
         std::cout << "i\nAPPROVED INT CONT CREATED\n";
} 

void IntContainer::DeallocateContainer() {
    if (this->data != nullptr) delete[] this->data; 
    this->data = nullptr;
}

int IntContainer::GetCapacity() const {
    return this->capacity;
}

CONTAINER::ContainerType IntContainer::GetContainerType() const {
    return CONTAINER::ContainerType::Int; 
}

void IntContainer::AddElements(int number_elements, int* elements) {
/*    
    try {
        if (number_elements != sizeof(elements)/sizeof(int) ) 
            throw std::length_error("Invalid Length");
    } 
    catch(const std::length_error& err) {
        std::cerr << "\nERROR: IntContainer.cpp Invalid Length\n";
    }
*/
    if ( number_elements + this->GetNumberStored() >= this->GetCapacity()) { 
        this->Resize();
        // re-call the same function after the automatice resizing
        this->AddElements(number_elements, elements);
    }
    else {
        // important to extract the last occupied cell at the beginning and not at every addition to the container
        // 1. to reduce number memory acecesses
        // 2. logically, GetNumberStored() will be increasing each time an element > 0 is added
        int last_occupied_cell = this->GetNumberStored();

        for (int i = 0; i < number_elements; i++) //{
            this->data[last_occupied_cell+i] = *(elements+i);
            //std::cout << "\n%%" <<this->data[last_occupied_cell+i]<< "\t";
        //}
    }
}

void IntContainer::AddElements(int element) { 
    if (this->GetNumberStored() + 1 < this->GetCapacity())
        this->data[this->GetNumberStored()] = element; 
    else {
        this->Resize();
        AddElements(element);
    }
}

// O(n)
int IntContainer::GetNumberStored() {
    int result = 0;
    for (int i = 0; i < capacity; i++) 
        result = this->data[i] > 0 ? result + 1 : result;
    
    //return sizeof(this->data)/sizeof(int);
    return result;
}

int IntContainer::GetElementFreq(int element) {
    int frequency = 0;
    for (int i = 0; i < this->GetNumberStored(); i++) 
        frequency = this->data[i] == element ? frequency + 1 : frequency; 
    
    return frequency;
}

void IntContainer::Resize() {
    delete[] this->data;
    this->data = new int[this->GetCapacity()*2];
}

void IntContainer::PrintContainer() {
    for (int i = 0; i < this->GetNumberStored(); i++)
        std::cout << this->data[i] << "\t";
    std::cout << std::endl;
}
