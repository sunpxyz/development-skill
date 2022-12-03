// get-env.cpp
// 2022-01-30

#include <iostream>
#include <cstdlib>

int main()
{
    char *server_name = getenv("SERVER_NAME");
    if (!server_name) {
        server_name = "server.yours.com";
        std::cout << "accessing server: " << server_name << std::endl;
    }

    return 0;
}