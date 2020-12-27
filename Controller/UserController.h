//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_USERCONTROLLER_H
#define KECHENGSHEJI_USERCONTROLLER_H

#include "../Model/DataModel.h"
#include "../Model/UserModel.h"
#include "../Model/StatusModel.h"

//UserPtr newUser(const char, const wchar_t*, const wchar_t*);

StatusPtr initUserController();

StatusPtr login(wchar_t[16], wchar_t[16]);
bool logged();
StatusPtr logout();

StatusPtr addUser(wchar_t[16], wchar_t[16]);
StatusPtr removeUser();
UserPtr searchUser(wchar_t*);
StatusPtr editUser(wchar_t*, wchar_t*);
LinkListPtr getUserRaw();

#endif //KECHENGSHEJI_USERCONTROLLER_H
