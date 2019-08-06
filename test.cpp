#include <iostream>
#include <dirent.h>

void muestra_contenido_de(const std::string &a_carpeta)
{
    if (DIR *dpdf = opendir(a_carpeta.c_str()))
    {
        dirent *epdf = nullptr;
        while (epdf = readdir(dpdf))
        {
            std::cout << epdf->d_name << '\n';
        }
    }
}

int main(int argc, const char **argv)
{

    if (argc > 1)
    {
        muestra_contenido_de(argv[1]);
    }

    return 0;
}