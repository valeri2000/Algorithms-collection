srand(time(NULL));
long long genLL()
{
    int lenLL=18, diggg=0;
    long long XX;
    while(diggg==0)
    {
        diggg=rand()%10;
    }
    XX=diggg;
    for(int jj=1; jj<lenLL; ++jj)
    {
        diggg=rand()%10;
        XX=10*XX+diggg;
    }
    return XX;
}

int genI32()
{
    int lenLL=9, diggg=0, XX;
    while(diggg==0)
    {
        diggg=rand()%10;
    }
    XX=diggg;
    for(int jj=1; jj<lenLL; ++jj)
    {
        diggg=rand()%10;
        XX=10*XX+diggg;
    }
    return XX;
}
