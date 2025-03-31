#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
public:
    Animal();                           
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    ~Animal();                         
};

#endif
