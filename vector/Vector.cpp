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

int main() {

}