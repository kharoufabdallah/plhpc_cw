#include "DoubleContainer.hpp"

// constructor and destructor 
DoubleContainer::DoubleContainer(const int capacity): CONTAINER::Container(CONTAINER::ContainerType::Double, capacity) {
    this->capacity = capacity;
    this->container_type = CONTAINER::ContainerType::Double;
    this->CreateContainer(CONTAINER::ContainerType::Double, capacity);
}

DoubleContainer::~DoubleContainer() {
    this->DeallocateContainer();
    CONTAINER::Container::~Container();
}

// private methods
void DoubleContainer::DeallocateContainer() {
    if (this->data != nullptr)  
        delete[] this->data;
   this->data = nullptr; 
}

void DoubleContainer::CreateContainer(CONTAINER::ContainerType type, int capacity) {
    this->data = (double*) malloc(capacity*sizeof(double));
}

// TODO: should invistigate how to globalize a function from the based class and to be used for all derived classes if the
// implementation is not different

int DoubleContainer::GetCapacity() const {
    return this->capacity;
}

CONTAINER::ContainerType DoubleContainer::GetContainerType() const {
    return CONTAINER::ContainerType::Double;
}

// TODO: replace to templates, as the only difference in functions implementations are the same except the type !!
void DoubleContainer::AddElements(int number_elements, double* elements) {

    if ( number_elements + this->GetNumberStored() >= this->GetCapacity()) { 
        this->Resize();
        // re-call the same function after the automatice resizing
        this->AddElements(number_elements, elements);
    }
    else {
        int last_occupied_cell = this->GetNumberStored();

        for (int i = 0; i < number_elements; i++) //{
            this->data[last_occupied_cell+i] = *(elements+i);
            //std::cout << "\n%%" <<this->data[last_occupied_cell+i]<< "\t";
        //}
    }
}

int DoubleContainer::GetNumberStored() {
    // The lambda [](int x) { return x > 0; } returns true for values above 0.
    
    // x is a placeholder 
    int count = std::count_if(this->data, this->data + this->GetCapacity(), [](int x) {
        return x > 0;
    });
    return count;
}

int DoubleContainer::GetElementFreq(double element) {
    int frequency = 0;
    for (int i = 0; i < this->GetNumberStored(); i++) 
        frequency = this->data[i] == element ? frequency + 1 : frequency; 
    
    return frequency;   
}

void DoubleContainer::Resize() {
    delete[] this->data;
    this->data = new double[this->GetCapacity()*2];
}

void DoubleContainer::PrintContainer() {
    for (int i = 0; i < this->GetNumberStored(); i++)
        std::cout << this->data[i] << "\t";
    std::cout << std::endl;
}
/*
--(*to);
i++; (*i)++;
*/
