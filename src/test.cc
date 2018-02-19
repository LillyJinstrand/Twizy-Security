#include <iostream>
#include "security.h"

int main(){
    std::cout << "isInitialized returned: " << isInitialized() << "\n";
    std::cout << "Calling init()\n";
    init();
    std::cout << "isInitialized returned: " << isInitialized() << "\n";

    std::cout << "Calling update()\n";
    bool result = update();
    std::cout << "Update returned: " << result << "\n";

    return 0;
}
