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
        {1, 2, 3},
        0.5,
        {1.0, 0.0, 0.0},
        5,
        2,
        1,
        4,
        Type::VEHICLE
    };

    std::cout << "Calling update_perception()\n";
    update_perception(test_obstacle);
    

    return 0;
}
