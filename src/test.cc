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

    perception_obstacle_ada test_obstacle = {
        1,
        true,
        {1, 2, 3},
        true,
        0.5,
        true,
        {1.0, 0.0, 0.0},
        true,
        5,
        true,
        2,
        true,
        1,
        true,
        4,
        true,
        Type::VEHICLE,
        true
    };

    std::cout << "Calling update_perception()\n";
    update_perception(test_obstacle);
    

    return 0;
}
