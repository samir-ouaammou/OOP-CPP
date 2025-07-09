#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data d;
    d.id = 1;
    d.name = "test";
    d.value = 42.0f;

    std::cout << "Before serialization:\n";
    std::cout << "  Address: " << &d << "\n";
    std::cout << "  id: " << d.id << ", name: " << d.name << ", value: " << d.value << "\n";

    unsigned long raw = Serializer::serialize(&d);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "\nAfter deserialization:\n";
    std::cout << "  Address: " << restored << "\n";
    std::cout << "  id: " << restored->id << ", name: " << restored->name << ", value: " << restored->value << "\n";

    std::cout << "\nPointer equality: " << (restored == &d ? "OK" : "FAIL") << std::endl;

    return 0;
}
