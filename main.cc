// #include "flatten-binary-tree-to-linked-list.h"
#include <iostream>
#include <string>
#include <variant>

using int_value_t   = long long;
using float_value_t = double;
using string_ref_t  = std::string*;
using variant_t     = std::variant<int_value_t, float_value_t, string_ref_t>;

using namespace std;

int main(int argc, char* argv[]) {
    variant_t v;
    cout << sizeof(variant_t) << endl;
    // test();
}
