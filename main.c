#include <stdlib.h>
#include <stdio.h>
#include "Controller/FileController.h"

int main() {
    initItemController();
    initUserController();
    MetaPtr meta = malloc(sizeof(MetaModel));
    meta->userNumber = 1;
    StatusPtr res = addUser(L"1", L"1");
    if(res->stat == SUCCESS)
        puts("success");
    else puts("failed");
    res = login(L"1", L"1");
    if(res->stat == SUCCESS)
        puts("success");
    else puts("failed");

    writeDataFile(meta);
    return 0;
}