#include <iostream>
#include "security.h"

int main(){
    std::cout << "isInitialized returned: " << isInitialized() << "\n";
    std::cout << "Calling init()\n";
    init();
    std::cout << "isInitialized returned: " << isInitialized() << "\n";

    std::cout << "Calling is_safe()\n";
    bool result = is_safe();
    std::cout << "is_safe returned: " << result << "\n";

    return 0;
}
