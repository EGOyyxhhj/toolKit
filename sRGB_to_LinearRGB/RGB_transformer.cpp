#include <iostream>
#include <cmath>
#include <iomanip>

double srgbToLinear(double c) {
    c /= 255.0; // 归一化
    if (c <= 0.04045)
        return c / 12.92;
    else
        return pow((c + 0.055) / 1.055, 2.4);
}

int main() {
    int r, g, b;
    std::cout << "Please input the value of R, G & B in sRGB space:" << std::endl;
    while(std::cin >> r >> g >> b){
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        std::cout << "The value in sRGB space is" << std::endl;
        std::cout << "R: " << r << std::endl;
        std::cout << "G: " << g << std::endl;
        std::cout << "B: " << b << std::endl;
    
        double linearR = srgbToLinear(r);
        double linearG = srgbToLinear(g);
        double linearB = srgbToLinear(b);
    
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "The value in LinearRGB space is" << std::endl;
        std::cout << "R: " << linearR << std::endl;
        std::cout << "G: " << linearG << std::endl;
        std::cout << "B: " << linearB << std::endl;
    }

    return 0;
}
