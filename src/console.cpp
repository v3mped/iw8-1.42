#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>

#include <cstdint>
#include <cstdarg>
#include <cstdio>
#include <cstring>

#include "common.hpp"
#include "postload.hpp"

void Cbuf_AddText(const char* fmt, ...) // method from pipes
{
    const uintptr_t xpartydisbandAdr = 0x142DF6A9B_g; // should be the right address
    const uintptr_t GScr_EndlobbyAdr = 0x142DF6ABA_g; // should be the right address

    char cmd[256]{};
    char post[256]{};

    va_list ap;
    va_start(ap, fmt);
    vsnprintf(cmd, sizeof(cmd), fmt, ap);
    va_end(ap);

    memcpy(post, reinterpret_cast<void*>(xpartydisbandAdr), sizeof(post));

    strcpy_s(
        reinterpret_cast<char*>(xpartydisbandAdr),
        sizeof(cmd),
        cmd
    );

    auto cbufFunc = reinterpret_cast<void(*)(void*)>(GScr_EndlobbyAdr);
    cbufFunc(nullptr);

    memcpy(
        reinterpret_cast<void*>(xpartydisbandAdr),
        post,
        sizeof(post)
    );
}




void IW8Console()
{
    AllocConsole();

    FILE* out;
    FILE* in;

    freopen_s(&out, "CONOUT$", "w", stdout);
    freopen_s(&in, "CONIN$", "r", stdin);

    SetConsoleTitleA("IW8-1.42 By T5DW");

    std::string command;

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, command);




        if (command == "menu")
        {
            mainmenuoffline();
        }


        else if (command == "exit")
        {
            break;
        }


        else if (!command.empty())
        {
            std::cout 
                << "Unknown command: "
                << command
                << "\n";
        }
    }

    FreeConsole();
}




void StartIW8Console()
{
    std::thread(IW8Console).detach();
}
