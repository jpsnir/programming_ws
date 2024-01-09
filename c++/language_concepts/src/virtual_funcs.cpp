#include <iostream>
#include <string>

class Entity{
    public:
        // not virtual
        void GetName1(){
            std::cout << "Entity Base" << std::endl;
        }

        virtual void GetName2(){
            std::cout << "Entity Base" << std::endl;
        }
};

class Player: public Entity{
public:
    std::string m_name;
    Player(std::string name){
        m_name = name;
    }

    void GetName1(){
        std::cout << " Player name : " << m_name << std::endl;
    }

    void GetName2() override{
        std::cout << " Player name : " << m_name << std::endl;
    }

};

void print_name(Entity* e){
    std::cout << " No virtual function support for GetName1 " <<
        "therefore no vtable in base class" << std::endl;
    e->GetName1();
    std::cout << "-----------------------------\n";
    std::cout << " Vtable support for GetName2" << std::endl;
    e->GetName2();
}

int main(){
    Entity e;
    Player p("jagat");
    print_name(&p);
    return 0;
}
