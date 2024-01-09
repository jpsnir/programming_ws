#include <iostream>

class Entity{
   public:
       float X, Y;
       void Move(float xa, float ya){
           X += xa;
           Y += ya;
       }
};

class Player: public Entity{
    public:
        const char* Name;
        void PrintName(){
            std::cout << " Name is " << Name << std::endl;
        }
};

int main(){
    Player p;
    // can access its methods and variables
    p.Name = "jagat";
    p.PrintName();

    // can also access public members from base class
    p.X = 4; p.Y = 4;
    p.Move(6, 6);
    std::cout <<"Player position = " << p.X << "," << p.Y << std::endl;
    // size of player object (sum of size of all variables)
    std::cout << "Size of player - " << sizeof(p) << std::endl;
}
