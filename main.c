#include <stdio.h>
#include<wchar.h>
#include "Model/StatusModel.h"
#include "Controller/UserController.h"

int main() {
    StatusPtr a = newStatus(SUCCESS, L"haha");
    wprintf(L"%ls %d", a->msg, wcslen(a->msg));
    return 0;
}