
#include <iostream>
struct House
{
    char address[50];
    int bedrooms;
    double price;
};
int main()
{
    setlocale(0, "rus");
    srand(time(NULL));
    House houses[] = {
        {"ул. Ленина, д.15",3,65000},
        {"ул. Мира, д.7",2,50000},
        {"ул. Гагарина, д.18",1,35000},
        {"ул. Кирова, д.3",3,75000},
        {"ул. Восточная, д.9",4,100000},
        {"ул. Восточная, д.5",4,120000},
        {"ул. Восточная, д.5",2,45000},
        {"ул. Восточная, д.5",1,40000}
    };
    std::cout << "Введите количество спальн для поиска: ";
    int number;
    std::cin >> number;
    double total = 0.0;
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (houses[i].bedrooms == number)
        {
            total += houses[i].price;
            count++;
        }
    }
    if (count > 0)
    {
        std::cout << "Средняя цена: " << (total / count);
    }
    else {
        std::cout << "Домов не найдено";
    }
}
