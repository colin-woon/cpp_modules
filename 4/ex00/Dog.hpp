#ifndef DOG_HPP
#define DOG_HPP

class Dog
{
public:
    Dog();                           
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();                         
};

#endif
