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
    Obj->Uid = uid;
    wcscpy(Obj->Username, username);
    wcscpy(Obj->Password, password);
    return Obj;
}

StatusPtr initController() {
    loggedUser = NULL;
    Users = Init_LinkList();
    return newStatus(SUCCESS, L"");
}

bool login_callback(void* _data, void* _username){
    if(_data == NULL || _username == NULL)
        return false;
    UserPtr data = _data;
    wchar_t* username = _username;
    return wcscmp(data->Username, username) == 0;
}

StatusPtr login(wchar_t username[16], wchar_t password[16]){
    if(username == NULL || password == NULL)
        return newStatus(NULLPTR, L"");
    UserPtr res = Find_LinkList(Users, login_callback, username);
    if(res == NULL)
        return newStatus(FAILED, L"unknown user");
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
    u32 userNumber = Size_LinkList(Users);
    return Insert_LinkList(Users, userNumber, newUser(userNumber, username, password));
}

bool removeUser_callback(void* _data, void* _uid){
    if(_data == NULL || _uid == NULL)
        return false;
    UserPtr data = _data;
    u16* uid = _uid;
    return data->Uid == *uid;
}

StatusPtr removeUser(u16 uid){
    if(loggedUser == NULL || loggedUser->Uid != uid)
        return newStatus(NULLPTR, L"");
    return Remove_LinkList(Users, removeUser_callback, &uid);
}

bool searchUser_callback(void* _data, void* _username){
    if(_data == NULL || _username == NULL)
        return false;
    UserPtr data = _data;
    wchar_t* username = _username;
    return wcscmp(data->Username, username);
}

StatusPtr searchUser(wchar_t* username){
    if(username == NULL)
        return newStatus(NULLPTR, L"");
    return Find_LinkList(Users, searchUser_callback, username);
}

StatusPtr editUser(wchar_t* username, wchar_t* password){
    if(username == NULL || password == NULL)
        return newStatus(NULLPTR, L"");
    wcscpy(loggedUser->Username, username);
    wcscpy(loggedUser->Password, password);
    return newStatus(SUCCESS, L"");
}

UserPtr getUserRaw(){
    return Front_LinkList(Users);
}
