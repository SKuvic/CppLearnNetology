#include <iostream>

namespace sum {
   int calc (int x, int y) {
        x += y;
        std:: cout << "Сложение:" << x << std::endl;
        return x;
    }
}


namespace subtr {
    int calc (int x, int y) {
        x -= y;
        std:: cout << "Вычитание:" << x << std::endl;
        return x;
    }
}

namespace multi {
    int calc (int x, int y) {
        x *= y;
        std:: cout << "Умножение:" << x << std::endl;
        return x;
    }
}

namespace divaid {
    int calc (int x, int y) {
        x /= y;
        std:: cout << "Деление:" << x << std::endl;
        return x;
    }
}

int main (int argc, char** argv)
{
    int x = 6, y = 9;
    sum:: calc (x, y);
    subtr:: calc (x, y);
    multi:: calc (x, y);
    divaid:: calc (x, y);
    return 0;
}