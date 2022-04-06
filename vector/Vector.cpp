#include <iostream>
#include <vector>
class String
{
private:
    const char* m_Buffer;

public:
    String(const char* array)
        : m_Buffer(array)
    {}
    const char*& getString()
    {
        return m_Buffer;
    }
};

std::ostream& operator<<(std::ostream& stream, String& string)
{
    stream << string.getString();
    return stream;
}

int main() {
    std::vector<String> strings;

    strings.push_back("Serhat0");
    strings.push_back("Serhat1");
    strings.push_back("Serhat2");
    strings.push_back("Serhat3");
    strings.push_back("Serhat4");

    for (String s : strings)
    {
        std::cout << s << std::endl;
    }
}