#include <iostream>
#include <vector>
#define LOG(x) std::cout << x << std::endl

class String
{
private:
    char* m_Buffer;
    size_t m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size + 1);
    }
    String(const String& string) //copy constructor
        :
        m_Size(string.m_Size)
    {
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string.m_Buffer, m_Size + 1);
        std::cout << "String copied" << std::endl;
    }
    char*& getString()
    {
        return m_Buffer;
    }
    char& operator[](int index)
    {
        return m_Buffer[index];
    }
};

struct Vector3
{
    float x, y, z;
    Vector3(int x, int y, int z)
        : x(x), y(y), z(z)
    {}
};

std::ostream& operator<<(std::ostream& stream, String& string)
{
    stream << string.getString();
    return stream;
}
std::ostream& operator<<(std::ostream& stream, Vector3& vector3)
{
    stream << vector3.x << ", " << vector3.y << ", " << vector3.z;
    return stream;
}

int main() {
    std::vector<String> strings;
    strings.reserve(5);
    strings.emplace_back("Serhat0");
    strings.emplace_back("Serhat1");
    strings.emplace_back("Serhat2");
    strings.emplace_back("Serhat3");
    strings.emplace_back("Serhat4");

    for (String s : strings)
    {
        LOG(s);
    }

    std::vector<Vector3> vector3d;

    vector3d.emplace_back( 1,2,3 );
    vector3d.emplace_back( 4,5,6 );
    vector3d.emplace_back( 7,8,9 );
    for (Vector3 vec : vector3d)
    {
        LOG(vec);
    }

    String s = "Serhat";
    String y = s;
    y[1] = 'a';
    LOG(s);
    LOG(y);
}