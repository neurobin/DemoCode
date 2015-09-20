#include <iostream> // std::cout
#include <string>
#include <algorithm> // std::sort, std::copy
#include <iterator> // std::ostream_iterator
#include <sstream> // std::istringstream
#include <vector>
#include <cctype> // std::isdigit

bool compareNat(const std::string& a, const std::string& b)
{
    if (a.empty())
        return true;
    if (b.empty())
        return false;
    if (std::isdigit(a[0]) && !std::isdigit(b[0]))
        return true;
    if (!std::isdigit(a[0]) && std::isdigit(b[0]))
        return false;
    if (!std::isdigit(a[0]) && !std::isdigit(b[0]))
    {
        if (a[0] == b[0])
            return compareNat(a.substr(1), b.substr(1));
        return (std::toupper(a[0]) < std::toupper(b[0]));
    }

    // Both strings begin with digit --> parse both numbers
    std::istringstream issa(a);
    std::istringstream issb(b);
    int ia, ib;
    issa >> ia;
    issb >> ib;
    if (ia != ib)
        return ia < ib;

    // Numbers are the same --> remove numbers and recurse
    std::string anew, bnew;
    std::getline(issa, anew);
    std::getline(issb, bnew);
    return (compareNat(anew, bnew));
}

int main()
{
    std::vector<std::string> str;
    str.push_back("100000000000045353454300000000000000000000000000000.txt");
    str.push_back("20.txt");
    str.push_back("10.txt");
    str.push_back("1.txt");
    str.push_back("z2.txt");
    str.push_back("z10.txt");
    str.push_back("100000000000000000000000000000000000000000.txt");
    
    str.push_back("1_t.txt");
    str.push_back("_t.txt");

    std::sort(str.begin(), str.end(), compareNat);
    std::copy(str.begin(), str.end(),
              std::ostream_iterator<std::string>(std::cout, "\n"));
}
