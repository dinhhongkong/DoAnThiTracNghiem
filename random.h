
// random [a, b)
int randomNumber(int a, int b) {
    return rand() % (b-a) + a;
}

void RandomArrNumber(int arr[])
{
    for (int i = 0; i < MAX_RANDOM; i++)
    {
        arr[i] = i;
    }

    int temp;
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
    
    // neu doc that bai, hay ko có file random thì tạo file random
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

