#include "FloatContainer.hpp"

// constructor and destructor 
FloatContainer::FloatContainer(const int capacity): CONTAINER::Container(CONTAINER::ContainerType::Float, capacity) {
    this->capacity = capacity;
    this->container_type = CONTAINER::ContainerType::Float;
    this->CreateContainer(CONTAINER::ContainerType::Float, capacity);
}

FloatContainer::~FloatContainer() {
    this->DeallocateContainer();
    CONTAINER::Container::~Container();
}

// private methods
void FloatContainer::DeallocateContainer() {
    if (this->data != nullptr)  
        delete[] this->data;
   this->data = nullptr; 
}

void FloatContainer::CreateContainer(CONTAINER::ContainerType type, int capacity) {
    this->data = (float*) malloc(capacity*sizeof(float));
}

// TODO: should invistigate how to globalize a function from the based class and to be used for all derived classes if the
// implementation is not different

int FloatContainer::GetCapacity() const {
    return this->capacity;
}

CONTAINER::ContainerType FloatContainer::GetContainerType() const {
    return CONTAINER::ContainerType::Float;
}

// TODO: replace to templates, as the only difference in functions implementations are the same except the type !!
void FloatContainer::AddElements(int number_elements, float* elements) {

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

int FloatContainer::GetNumberStored() {
    // The lambda [](int x) { return x > 0; } returns true for values above 0.
    
    // x is a placeholder 
    int count = std::count_if(this->data, this->data + this->GetCapacity(), [](int x) {
        return x > 0;
    });
    return count;
}

int FloatContainer::GetElementFreq(float element) {
    int frequency = 0;
    for (int i = 0; i < this->GetNumberStored(); i++) 
        frequency = this->data[i] == element ? frequency + 1 : frequency; 
    
    return frequency;   
}

void FloatContainer::Resize() {
    delete[] this->data;
    this->data = new float[this->GetCapacity()*2];
    this->capacity = this->GetCapacity()*2;
}

void FloatContainer::PrintContainer() {
    for (int i = 0; i < this->GetNumberStored(); i++)
        std::cout << this->data[i] << "\t";
    std::cout << std::endl;
}
/*
--(*to);
i++; (*i)++;
*/
