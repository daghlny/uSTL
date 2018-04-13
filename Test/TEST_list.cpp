
#include "../stl_list.h"
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> nums{1,2,3,4,5,6};
    ustl::list<int> L(nums.begin(), nums.end());
    std::cout << L.size() << std::endl;

    ustl::list<int>::iterator pos = L.begin();
    while (pos != L.end()) {
        std::cout << *(pos++) << " ";
    }
    std::cout << std::endl;

    pos = L.begin();
    for (int i = 0; i < 10 && pos != L.end(); ++i) {
        if ( int(i & 0x01) == 0 ) {
            std::cout << "erase: " << *pos << std::endl;
            pos = L.erase(pos);
        }
        else
            pos++;

    }

    pos = L.begin();
    while (pos != L.end()) {
        std::cout << *(pos++) << " ";
    }
    std::cout << std::endl;
    // should be 2 2 2 2 2

    L.insert(L.begin(), 7);
    pos = L.begin();
    pos++;
    pos++;
    L.insert(pos, 2, 42);

    pos = L.begin();
    while (pos != L.end()) {
        std::cout << *(pos++) << " ";
    }
    std::cout << std::endl;
    // should be 7 2 42 42 2 2 2 2
    //
    ustl::list<int> L2(L);
    pos = L2.begin();
    while (pos != L2.end()) 
        std::cout << *(pos++) << " ";
    std::cout << std::endl;

    ustl::list<int>::const_iterator it = L2.cbegin();
    ++it;
    std::cout << *it << std::endl;

    return 0;
}
