#include <iostream>
#include "simplefilewriter.h"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        std::string _filename = "";
        std::string _action = "";
        bool _showLineNumbers = false;

        for (int i = 1; i < argc; i++)
        {
            std::string arg = argv[i];

            if (arg.compare("--filename") == 0 || arg.compare("-f") == 0)
            {
                std::string file = argv[i + 1];
                _filename = file;
            }
            else if (arg.compare("--read") == 0 || arg.compare("-r") == 0)
            {
                _action = (std::string) "read";
            }
            else if (arg.compare("--write") == 0 || arg.compare("-w") == 0)
            {
                _action = (std::string) "write";
            }
            else if (arg.compare("--append") == 0 || arg.compare("-a") == 0)
            {
                _action = (std::string) "append";
            }
            else if (arg.compare("--number") == 0 || arg.compare("-n") == 0)
            {
                _showLineNumbers = true;
            }
            else
            {
                continue;
            }
        }

        if (_filename.compare("") == 0)
        {
            std::cout << "Erro! Não foi possível abrir o arquivo.\n";
            help();
            return 1;
        }

        if (_action.compare("read") == 0)
        {
            read_file(_filename, _showLineNumbers);
        }
        else if (_action.compare("write") == 0)
        {
            write_file(_filename, false, _showLineNumbers);
        }
        else if (_action.compare("append") == 0)
        {
            write_file(_filename, true, _showLineNumbers);
        }
    }
    else
    {
        help();
    }
    return 0;
}
