// get-opt.cpp
// 2022-01-29

#include <iostream>
#include <cstdlib>
#include <getopt.h>

const char* pragram_name;

void outputInfo(std::ostream& os, int exit_code)
{
    os << "Usage:" << pragram_name << " options [filename]" << std::endl;
    os << " -h --help: Display this usage information." << std::endl;
    os << " -o --output filename: Write output to file." << std::endl;
    os << " -v --verbose: Print verbose messages." << std::endl;
    exit(exit_code);
}

int main(int argc, char* argv[]) 
{
    const char* const short_opts = "ho:v";
    const struct option long_opts[] = {
        {"help", 0, NULL, 'h'},
        {"output", 1, NULL, 'o'},
        {"verbose", 0, NULL, 'v'},
        {NULL, 0, NULL, 0}
    };
    const char* output_filename = NULL;
    int verbose = 0;
    pragram_name = argv[0];
    
    if (argc < 2) {
        outputInfo(std::cout, 0);
    }
    
    int opt = getopt_long(argc, argv, short_opts, long_opts, NULL);
    while (opt != -1) {
        switch (opt) {
            case 'h':
                outputInfo(std::cout, 0);
            case 'o':
                output_filename = optarg;
                break;
            case 'v':
                verbose = 1;
                break;
            case '?':
                outputInfo(std::cerr, 1);
            case -1:
                break;
            default:
                abort();
        }
        opt = getopt_long(argc, argv, short_opts, long_opts, NULL);
    }

    return 0;
}