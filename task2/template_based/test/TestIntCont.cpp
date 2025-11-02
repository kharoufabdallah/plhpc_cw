#include "Container.hpp"
#include <cassert>

int main () {
    
    // 1. instatnitate the int container with initial capacity of 10 
    Container<int> container(10);
    
    // 2. add one element to the conainter
    container.AddElements(22);
    
    //container.PrintContainer();
    assert(container.GetNumberStored() == 1); 
    
    // 3. add list of 3 elements to the container
    int* l = new int[3]{99,88,7}; 

    container.AddElements(3,l);
    delete[] l;
    //container.PrintContainer();
    assert(container.GetNumberStored() == 4);    

    // 4. add more elements above capacity
    int* ln = new int[8]{1,2,3,4,5,6,7,8};
    container.AddElements(8, ln);
    delete[] ln;
    
    // container.PrintContainer();
    assert(container.GetNumberStored() == 12);
    assert(container.GetCapacity() == 20);
    assert(container.GetElementFreq(7) == 2);
    assert(container.GetElement(2) == 88);
 

    int *lnn = new int[100]; 
    for (int i = 0; i < 100; i++)
        lnn[i] = i;

    container.AddElements(100, lnn);
    delete[] lnn; 
 
    assert(container.GetNumberStored() == 112);
    assert(container.GetCapacity() == 160);
    assert(container.GetElementFreq(7) == 3);
    assert(container.GetElement(2) == 88);
    assert(container.GetElement(12) == 0);

    std::cout << " ******************************************** " << "\n";
    std::cout << " ******************************************** " << "\n";
    std::cout << "\tTEST\t\tPASSED\t\t:)  " << "\n";
    std::cout << " ******************************************** " << "\n";
    std::cout << " ******************************************** " << "\n";

    return 0;
};
