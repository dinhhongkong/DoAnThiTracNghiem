#define MAX_RANDOM 5000

void RandomArrNumber(int arr[])
{
    for (int i = 0; i < MAX_RANDOM; i++)
    {
        arr[i] = i;
    }

    int temp;
    srand((int)time(0));
    for (int i = 0; i < MAX_RANDOM; i++)
    {
        temp = rand() % MAX_RANDOM ;
        swap(arr[i], arr[temp]);
    }
}
