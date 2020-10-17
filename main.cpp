#include <iostream>

void aim(int& x, int& y) 
{
    std::cout << "введите координаты х :";
    std::cin >> x;
    std::cout << "введите координаты у: ";
    std::cin >> y;
}
void randd(int& x, int& y) 
{
    // добавляет к введенному значении рандомное число чтобы было сложнее попасть
    
    x += rand ()%3;
    y += rand() %3;
}
int getranddPoints() // мишень  и выстрелы в нее
{
    int x, y, ball;
    double R;

    aim(x, y);
    randd(x, y);
    R = sqrt(x * x + y * y);
    ball = (R <= 5) ? abs(static_cast<int>(ceil(R)) - 5) : 0;
    std::cout << "You hit the point (" << x << ", " << y << ") and got " << ball << " points" << std::endl;
    return ball;
}

int main() // посчет баллов и вывод результата 
{
    int ball = 0;

    for (int i = 0; i < 5; i++) {
        ball += getranddPoints();
    }
    if (ball < 10) {
    std::cout << "Вы набрали " << ball << " баллов и вы проиграли";
    }
    else {
    std::cout << "Вы набрали " << ball << " баллов и вы выйиграли";
    }
    return 0;
}
