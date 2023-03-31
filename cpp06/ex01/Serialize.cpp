#include <iostream>
#include <cstdint>
#include "Serialize.hpp"


class Serializer {
public:
    static uintptr_t serialize(Data* ptr)
    {
        return reinterpret_cast<uintptr_t>(ptr);
    }
    static Data* deserialize(uintptr_t raw)
    {
        return reinterpret_cast<Data*>(raw);
    }
};

// int main() {
//     Data data;
//     data.number = 42;
//     data.name = "Test";

//     uintptr_t ptrValue = Serializer::serialize(&data);
//     Data* deserialized = Serializer::deserialize(ptrValue);

//     if (deserialized == &data) {
//         std::cout << "Pointer deserialization succeeded!" << std::endl;
//         std::cout << "Number: " << deserialized->number << std::endl;
//         std::cout << "Name: " << deserialized->name << std::endl;
//         std::cout << "Address: " << deserialized << std::endl;
//         std::cout << "Address: " << &data << std::endl;

//         std::cout << "ptrValue: "<<ptrValue << std::endl;
//         std::cout << "ptrValue: "<<reinterpret_cast<uintptr_t>(&data) << std::endl;

//     } else {
//         std::cout << "Pointer deserialization failed!" << std::endl;
//     }

//     return 0;
// }

int main(){
	Data data;
	data.name = "the name";

	std::cout << "first one " <<  data.name << std::endl;
	
	uintptr_t raw = Serializer::serialize(&data);

	Data	*data2 = Serializer::deserialize(raw);

	std::cout << "second one " << data2->name << std::endl;
	return 0;
}
