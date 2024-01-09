#include <iostream>

class Entity{
public:
    Entity(){
        std::cout << "Entity created" << std::endl;
    }
    ~Entity(){
        std::cout << "Entity destroyed" << std::endl;
    }
};
int main(){
    Entity e;
}
