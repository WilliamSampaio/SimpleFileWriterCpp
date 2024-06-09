#include <iostream>
#include <fstream>
#include "simplefilewriter.h"

void read_file(std::string filename, bool showLineNumbers = false)
{
    std::string line;
    std::ifstream arqui(filename);

    if (arqui.is_open())
    {
        int line_n = 1;
        while (getline(arqui, line))
        {
            if (showLineNumbers)
            {
                std::cout << line_n++ << " " << line << '\n';
            }
            else
            {
                std::cout << line << '\n';
            }
        }
        arqui.close();
    }
    else
    {
        std::cout << "Erro! Não foi possível abrir o arquivo.\n";
    }
}

void write_file(std::string filename, bool append = false, bool showLineNumbers = false)
{
    std::string content;
    std::ofstream arqui;

    if (append)
    {
        arqui.open(filename, std::ios_base::app);
    }
    else
    {
        arqui.open(filename);
    }

    std::cout << "** Type \"@!\" to exit.\n";
    while (true)
    {
        std::cout << ':';
        std::getline(std::cin, content);

        if (content == "@!")
        {
            break;
        }

        arqui << content << '\n';
        content = "";
    }

    arqui.close();
    read_file(filename, showLineNumbers);
}

void help()
{
    std::cout << "\n::::::::::::: Manipulador de Arquivos :::::::::::::\n\n";
    std::cout << "Syntax: arquipp [params]\n";
    std::cout << "Params:\n";
    std::cout << "\t-f --filename \"/my_filename.txt\" : The filename.\n";
    std::cout << "\t-r --read : Read a file.\n";
    std::cout << "\t-w --write : write a file.\n";
    std::cout << "\t-a --append : Append in a file.\n";
    std::cout << "\t-n --number : Show line numbers.\n";
    std::cout << "\n";
}