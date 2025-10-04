
#include <iostream>

int main()
{
    setlocale(0, "rus");
    srand(time(NULL));
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = rand()%10;
        std::cout << i + 1 << " число массива: " << arr[i];
        std::cout << "\n";
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] < 0)
        {
            sum += arr[i] * -1;
        }
        else {
            sum += arr[i];
        }
    }
    std::cout << "Сумма абсолютных значений всех элементво массива = "<<sum;
}
