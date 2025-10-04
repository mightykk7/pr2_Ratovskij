#include <iostream>

int main()
{
    setlocale(0, "rus");
    srand(time(NULL));
    int arr[5][5];
    std::cout << "Элементы массива \n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = rand() % 10;
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 5; i++)
    {
        bool unik = true;
        for (int j = 0; j < 5; j++)
        {
            for (int k = j+1; k < 5; k++) {
                if (arr[i][k] == arr[i][j])
                {
                    unik = false;
                }
            }
        }
        if (unik == true)
        {
            std::cout << "Строка " << i + 1 << " Все элементы строки уникальны";
        }
        else
        {
            std::cout << "Строка " << i + 1 << " Есть повторения";
        }
        std::cout << std::endl;
    }
}
