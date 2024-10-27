#include <iostream>
#include <fstream>
#include "zip/temporary_unzip_file.h"

int main()
{
    
    TemporaryUnzipFile tzf("zip.zip", "zip/helo.txt");

    std::ifstream MyFile(tzf.get_location());

    std::string myText;
    while (getline(MyFile, myText))
    {
        std::cout << myText;
    }
    MyFile.close();
    std::cout << std::endl;

    return 0;
}