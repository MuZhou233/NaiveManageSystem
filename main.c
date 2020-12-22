#include <stdio.h>
#include<wchar.h>
#include "Controller/UserController.h"

int main() {
    printf("Hello, World!\n%lu\n%lu",sizeof(wchar_t), sizeof(char));
    UserPtr a = newUser(1, L"233", L"233");
    printf("%ls\n", a->Username);
    for (int i=0;i<sizeof(UserModel);i++)
    printf("%x", a->raw[i]);
    return 0;
}