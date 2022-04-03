#include <vector>
#include <iostream>
#include <memory>

int main()
{
    std::vector<std::shared_ptr<int>> v;
    std::shared_ptr<int> s = std::make_shared<int>(1);
    v.push_back(s);
    std::shared_ptr<int> s2 = std::make_shared<int>(1);
    v.push_back(s2);

    auto it = v.begin();

    std::cout << **it << std::endl;

    return 0;
}
