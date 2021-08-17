#include <iostream>
#include <string>
#include <vector>

#include "auto_complete.hpp"

int main() {
    std::cout << "AutoComplete for given string list using trie tree: " << std::endl;

    std::vector<std::string> sorted_auto_complete_strings = {
            {"why is the sky is blue"},
            {"hello world"},
            {"hey there"},
            {"how are things"},
            {"hey"},
            {"are you ready"},
            {"are you sober"},
            {"amazon did not want me"},
            {"my interview did not go as planned"},
            {"im sure i can do better"},
            {"you missed a hell of an employ"},
            {"are you sure"},
            {"give me a second chance"}
    };

    AutoComplete ap(sorted_auto_complete_strings);

    std::string str;
    std::cout << "search : "<<std::endl;
    std::cin >> str;

    std::vector<std::string> auto_complete_strings  = ap.getStringsForAutoComplete(str);
    std::cout << "sum of strings that go with given prefix: "<< auto_complete_strings.size()<< std::endl;
    for(int i = 0; i < auto_complete_strings.size(); i++)
    {
        std::cout << auto_complete_strings[i].c_str() << std::endl;
    }
    return 0;
}
