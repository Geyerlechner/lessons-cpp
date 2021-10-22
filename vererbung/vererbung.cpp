#include <iostream>
#include <cassert>

class Object
{
public:
    virtual void OnInit()
    {
        std::cout << "Object::OnInit()" << std::endl;
    }
    
};

class User : public Object
{
public:
    bool change_pwd = false;
    virtual void OnInit() override
    {   change_pwd = true;
         Object::OnInit();
        std::cout << "User::OnInit()" << std::endl;
    } 
};

class AlexUser : public User
{
public:
    virtual void OnInit() override
    {
        User::OnInit();
        std::cout << "AlexUser::OnInit()" << std::endl;
    }
};


int main()
{
    Object o;
    o.OnInit();
    std::cout << std::endl;

    User u;
    u.OnInit();
    std::cout << std::endl;
    assert( u.change_pwd == true );

    AlexUser au;
    au.OnInit();
    std::cout << std::endl;
}
