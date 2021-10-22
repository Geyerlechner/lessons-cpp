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
    bool get_changepwd() const
    {
        return changepwd;
    }
private:
    bool changepwd = false;
};

class AlexUser : public User
{
public:
    virtual void OnInit() override
    {
        User::OnInit();
        std::cout << "AlexUser::OnInit()" << std::endl;
    }
private: 
    bool changepwd = true;
};


int main()
{
    Object o;
    o.OnInit();

    User u;
    u.OnInit();

    assert( u.get_changepwd() == true );

    AlexUser au;
    au.OnInit();
}
