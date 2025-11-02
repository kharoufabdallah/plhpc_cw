#include "Container.hpp"
#include <cassert>
#include <cmath>

// source https://stackoverflow.com/questions/4548004/how-to-correctly-and-standardly-compare-floats 
bool is_float_equals(float x, float y) {
    float epsilon = 1e-6f; 
    return std::fabs(x - y) < epsilon;
}

int main () {
    
    // 1. instatnitate the float container with initial capacity of 10 
    Container<float> container(10);
    
    // 2. add one element to the conainter
    container.AddElements(22.22);
    
    //container.PrintContainer();
    assert(container.GetNumberStored() == 1); 
    
    // 3. add list of 3 elements to the container
    float* l = new float[3]{99.99,88.99,7.77}; 

    container.AddElements(3,l);
    delete[] l;
    //container.PrintContainer();
    assert(container.GetNumberStored() == 4);    

    // 4. add more elements above capacity
    float* ln = new float[8]{1,2,3,4,5,6,7,8};
    container.AddElements(8, ln);
    delete[] ln; 
    
    // container.PrintContainer();
    assert(container.GetNumberStored() == 12);
    assert(container.GetCapacity() == 20);
    assert(container.GetElementFreq(7.77) == 1);
    assert(is_float_equals(container.GetElement(1), 99.99));
 

    float *lnn = new float[100]; 
    for (int i = 0; i < 100; i++)
        lnn[i] = i + i % 4;

    container.AddElements(100, lnn);
    delete[] lnn; 
    //container.PrintContainer();

    assert(container.GetNumberStored() == 112);
    assert(container.GetCapacity() == 160);

    std::cout << " ******************************************** " << "\n";
    std::cout << " ******************************************** " << "\n";
    std::cout << "\tTEST\t\tPASSED\t\t:)  " << "\n";
    std::cout << " ******************************************** " << "\n";
    std::cout << " ******************************************** " << "\n";

    return 0;
};


