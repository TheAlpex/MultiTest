#include <iostream>
#include <string>
#include <cstdlib>

void drawUnicodeBox()
{
// Set Windows terminal code page to UTF-8 so characters render correctly
#if defined(_WIN32)
    std::system("chcp 65001 > nul");
#endif

    // Unicode box-drawing characters using standard UTF-8 strings
    const std::string TOP_LEFT = "┌";
    const std::string TOP_RIGHT = "┐";
    const std::string BOTTOM_LEFT = "└";
    const std::string BOTTOM_RIGHT = "┘";
    const std::string HORIZONTAL = "─";
    const std::string VERTICAL = "│";

    std::cout << TOP_LEFT;
    for (int i = 0; i < 13; i++)
    {
        std::cout << HORIZONTAL;
    }
    std::cout << TOP_RIGHT << "\n";
    std::cout << VERTICAL;
    std::cout << TOP_LEFT;
    for (int i = 0; i < 11; i++)
    {
        std::cout << HORIZONTAL;
    }
    std::cout << TOP_RIGHT;
    std::cout << VERTICAL;
    std::cout << "\n";
    std::cout << VERTICAL;
    std::cout << VERTICAL;
    for (int i = 0; i < 3; i++)
    {
        std::cout << " ";
    }
    std::cout << "A";
    std::cout << " ";
    std::cout << "B";
    std::cout << " ";
    std::cout << "C";
    for (int i = 0; i < 3; i++)
    {
        std::cout << " ";
    }
    std::cout << VERTICAL;
    std::cout << VERTICAL;
    std::cout << "\n";
    std::cout << VERTICAL;
    std::cout << VERTICAL;
    for (int i = 0; i < 3; i++)
    {
        std::cout << " ";
    }
    std::cout << "D";
    std::cout << " ";
    std::cout << "E";
    std::cout << " ";
    std::cout << "F";
    for (int i = 0; i < 3; i++)
    {
        std::cout << " ";
    }
    std::cout << VERTICAL;
    std::cout << VERTICAL;
    std::cout << "\n";
    std::cout << VERTICAL;
    std::cout << VERTICAL;
    for (int i = 0; i < 3; i++)
    {
        std::cout << " ";
    }
    std::cout << "G";
    std::cout << " ";
    std::cout << "H";
    std::cout << " ";
    std::cout << "I";
    for (int i = 0; i < 3; i++)
    {
        std::cout << " ";
    }
    std::cout << VERTICAL;
    std::cout << VERTICAL;
    std::cout << "\n";
    std::cout << VERTICAL;
    std::cout << BOTTOM_LEFT;
    for (int i = 0; i < 11; i++)
    {
        std::cout << HORIZONTAL;
    }
    std::cout << BOTTOM_RIGHT;
    std::cout << VERTICAL;
    std::cout << "\n";
    std::cout << BOTTOM_LEFT;
    for (int i = 0; i < 13; i++)
    {
        std::cout << HORIZONTAL;
    }
    std::cout << BOTTOM_RIGHT;
}
int main()
{
    drawUnicodeBox();
    return 0;
}