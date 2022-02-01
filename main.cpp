#include <iostream>
#include <vector>
#include <list>
#include <type_traits>

template <typename T,
          typename std::enable_if<std::is_same<char, T>::value>::type* = nullptr>
void print_ip_addr(const T&)
{
    std::cout << "-1\n";
}

template <typename T,
          typename std::enable_if<std::is_same<short, T>::value>::type* = nullptr>
void print_ip_addr(const T&)
{
    std::cout << "0\n";
}

template <typename T,
          typename std::enable_if<std::is_same<int, T>::value>::type* = nullptr>
void print_ip_addr(const T& value)
{
    std::cout << value << '\n';
}

template <typename T,
          typename std::enable_if<std::is_same<long, T>::value>::type* = nullptr>
void print_ip_addr(const T& value)
{
    const std::string ip_addr_output = std::to_string(value);
    std::cout << ip_addr_output.substr(0,3) << "." << ip_addr_output.substr(3,3) << "." << ip_addr_output.substr(6,3) << "." << ip_addr_output.substr(9,3) << '\n';
}

template <typename T, 
          typename std::enable_if<std::is_same<std::string, T>::value>::type* = nullptr>
void print_ip_addr(const T& value)
{
    std::cout << value << '\n';
}

template <typename T, 
          typename std::enable_if<std::is_same<std::list<int>, T>::value || std::is_same<std::vector<int>, T>::value>::type* = nullptr>
void print_ip_addr(const T& value)
{
    auto it = value.cbegin();
    std::cout << *it;
    ++it;
    for (auto end = value.cend(); it != end; ++it) {
        std::cout << '.' << *it;        
    }
    std::cout << '\n';
}



int main(){
    print_ip_addr('1');
    print_ip_addr(static_cast<short>(2));
    print_ip_addr(2130706433);
    print_ip_addr(192168001002l);
    print_ip_addr(std::string("192.168.10.20"));
    print_ip_addr(std::list<int>{102, 168, 5, 10});
    print_ip_addr(std::vector<int>{10, 10, 0, 1});

    return 0;
}