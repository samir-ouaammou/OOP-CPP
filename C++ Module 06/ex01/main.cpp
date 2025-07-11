#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data d;
    d.id = 1;
    d.name = "Samir";
    d.value = 42.0f;

    std::cout << "Before serialization:\n";
    std::cout << "\tAddress: " << &d << "\n";
    std::cout << "\tid: " << d.id << "\n\tname: " << d.name << "\n\tvalue: " << d.value << "\n";

    unsigned long raw = Serializer::serialize(&d);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "\n\nAfter deserialization:\n";
    std::cout << "\tAddress: " << restored << "\n";
    std::cout << "\tid: " << restored->id << "\n\tname: " << restored->name << "\n\tvalue: " << restored->value << "\n";

    std::cout << "\n\nPointer equality: " << (restored == &d ? "OK" : "FAIL") << std::endl;

    return 0;
}
