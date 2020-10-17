#include <iostream>
#include <random>

// пользователь вводит координаты точки
void aim(int& x, int& y) {
    std::cout << "Aim on the x coordinate: ";
    std::cin >> x;
    std::cout << "Aim on the y coordinate: ";
    std::cin >> y;
}

// производит простейшую симуляцию броска, после которого изменяются координаты точки
void throwADart(int& x, int& y) {
    // более непредсказумый выбор случайного числа 
    std::random_device rd;
    std::mt19937 mersenne(rd());
    x += static_cast<int>(mersenne() % 11 - 6);
    y += static_cast<int>(mersenne() % 11 - 6);
}

// прицеливание, бросок и подсчет очков
int getThrowPoints() {
    int x, y, points;
    double R;

    aim(x, y);
    throwADart(x, y);

    R = sqrt(x * x + y * y);
    points = (R <= 5) ? abs(static_cast<int>(ceil(R)) - 5) : 0;

    std::cout << "You hit the point (" << x << ", " << y << ") and got " << points << " points" << std::endl;
    return points;
}


int main() {
    int points = 0;

    for (int i = 0; i < 5; i++) {
        points += getThrowPoints();
    }

    if (points < 10) {
        std::cout << "You got " << points << " points and you lost";
    }
    else {
        std::cout << "You got " << points << " points and you won";
    }

    return 0;
}
