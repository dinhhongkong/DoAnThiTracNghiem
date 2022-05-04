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

void ghiFileRandom(int arr[])
{
    ofstream fileOut;
    fileOut.open("DATA\\Random.txt", ios_base::out);
   

    for (int i = 0; i < MAX_RANDOM; i++)
    {
        fileOut << arr[i] << " ";
    }

    fileOut.close();
}

void docFileRandom(int arr[])
{
    ifstream fileIn;
    fileIn.open("DATA\\Random.txt", ios_base::in);
    
    if ( !fileIn.is_open() ) {
        fileIn.close();
        RandomArrNumber(arr);
        ghiFileRandom(arr);
        return;
    }

    for (int i = 0; i < MAX_RANDOM ; i++)
    {
        fileIn >> arr[i] ;
    }
    fileIn.close();
}

