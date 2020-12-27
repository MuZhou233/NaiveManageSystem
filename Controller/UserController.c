//
// Created by muzhou on 2020/12/20.
//
#include <stdlib.h>
#include <string.h>
#include "UserController.h"

LinkListPtr Users;
UserPtr loggedUser;

UserModel* newUser(u8 uid, const wchar_t* username, const wchar_t* password){
    UserModel* Obj = NULL;
    if(wcslen(username) > 16 || wcslen(password) > 16) return Obj;
    Obj = (UserModel*)malloc(sizeof(UserModel));
    Obj->uid = uid;
    wcscpy(Obj->username, username);
    wcscpy(Obj->password, password);
    return Obj;
}

StatusPtr initUserController() {
    loggedUser = NULL;
    Users = LinkList_Init();
    return newStatus(SUCCESS, L"");
}

bool login_callback(void* _data, void* _username){
    if(_data == NULL || _username == NULL)
        return false;
    UserPtr data = _data;
    wchar_t* username = _username;
    return wcscmp(data->username, username) == 0;
}

StatusPtr login(wchar_t username[16], wchar_t password[16]){
    if(username == NULL || password == NULL)
        return newStatus(NULLPTR, L"");
    UserPtr res = LinkList_Find(Users, login_callback, username);
    if(res == NULL)
        return newStatus(FAILED, L"unknown user");
    if(wcscmp(res->password, password) != 0)
        return newStatus(FAILED, L"wrong password");
    loggedUser = res;
    return newStatus(SUCCESS, L"");
}

bool logged() {
    return loggedUser != NULL;
}

StatusPtr logout(){
    loggedUser = NULL;
    return newStatus(SUCCESS, L"");
}

StatusPtr addUser(wchar_t username[16], wchar_t password[16]){
    if(logged())
        return newStatus(FAILED, L"user logged");
    if(searchUser(username) != NULL)
        return newStatus(FAILED, L"user exist");
    u32 userNumber = LinkList_Size(Users);
    return LinkList_Insert(Users, userNumber, newUser(userNumber, username, password));
}

bool removeUser_callback(void* _data, void* _uid){
    if(_data == NULL || _uid == NULL)
        return false;
    UserPtr data = _data;
    u16* uid = _uid;
    return data->uid == *uid;
}

StatusPtr removeUser(){
    if(loggedUser == NULL)
        return newStatus(NULLPTR, L"");
    return LinkList_Remove(Users, removeUser_callback, &loggedUser->uid);
}

bool searchUser_callback(void* _data, void* _username){
    if(_data == NULL || _username == NULL)
        return false;
    UserPtr data = _data;
    wchar_t* username = _username;
    return wcscmp(data->username, username);
}

UserPtr searchUser(wchar_t* username){
    if(username == NULL)
        return NULL;
    return LinkList_Find(Users, searchUser_callback, username);
}

StatusPtr editUser(wchar_t* username, wchar_t* password){
    if(username == NULL || password == NULL)
        return newStatus(NULLPTR, L"");
    wcscpy(loggedUser->username, username);
    wcscpy(loggedUser->password, password);
    return newStatus(SUCCESS, L"");
}

LinkListPtr getUserRaw(){
    return Users;
}
