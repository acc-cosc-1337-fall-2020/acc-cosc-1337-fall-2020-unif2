#include<memory>

void use_smart_pointer(std::unique_ptr<int>& num);

std::unique_ptr<int> get_smart_pointer();

//Create ref function w reference and pointer parameter 
void ref_ptr(int& num1, int* num2);//First parameter is an address (the reference knows how to get the address), but we pass a variable. Second parameter is a pointer to some number (num2 is a pointer), so we must pass an address.
//Create return pointer function