#include "Container.hpp"
#include "IntContainer.hpp"
#include "FloatContainer.hpp"
#include "DoubleContainer.hpp"
int main () {
    // CONTAINER::Container cont(CONTAINER::ContainerType::Int, 40);
    
    IntContainer intcont(50); /// new IntContainer(50); 
    std::cout << intcont.GetCapacity() << "\n";
    int* ll = new int[3]{3,34,4};
    std::cout << intcont.GetNumberStored();
    intcont.AddElements(3, ll);
    intcont.PrintContainer();
//     delete intcont;
    delete[] ll;
    FloatContainer fltcon(100);
    
    //To use an abstract class to declare a derived class with polymorphism in C++, you define a base class with pure virtual functions,
    //then create derived classes that override those functions. You access them through base class pointers or references, enabling runtime polymorphism.
    CONTAINER::Container* poly_cont = new FloatContainer(200);
    poly_cont->Resize();
    int getcap = poly_cont->GetCapacity();
    std::cout << "cap of float" << getcap << "\n";
    delete poly_cont;

    CONTAINER::Container* dnnd= new DoubleContainer(20);
    dnnd->Resize();
    int getcap1 = dnnd->GetCapacity();
    std::cout << "cap of float" << getcap1 << "\n";
    delete dnnd;

    // create a derived class instance from base abstract class using reference 
    CONTAINER::DoubleContainer doublec; // concrete object 
    CONTAINER::Container &referencedoublec = doublec;
    // do whatever
    // Avoids manual memory management (new/delete)

    // Enables polymorphism without pointers

    // Works well with stack-allocated objects
return 0;
};
