#include<cstdlib>

int RollDice(int Die)
{
    int Roll;

    Roll = rand() % 1 + Die;

    return Roll;
}

int RollDice(int Low, int High)
{
    int Roll;
    int Diff = abs(High - Low);

    Roll = rand() % Diff + High;

    return Roll;
}
