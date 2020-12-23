//
// Created by muzhou on 2020/12/20.
//
#include <stdlib.h>
#include <string.h>
#include "UserController.h"

StatusPtr Users;

UserModel* newUser(const char uid, const wchar_t* username, const wchar_t* password){
    UserModel* Obj = NULL;
    if(wcslen(username) > 16 || wcslen(password) > 16) return Obj;
    Obj = malloc(sizeof(UserModel));
    Obj->Uid = uid;
    wcscpy(Obj->Username, username);
    wcscpy(Obj->Password, password);
    return Obj;
}

StatusPtr initController() {
    Users = Init_LinkList();
}