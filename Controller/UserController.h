//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_USERCONTROLLER_H
#define KECHENGSHEJI_USERCONTROLLER_H

#include "../Model/DataModel.h"
#include "../Model/UserModel.h"
#include "../Model/StatusModel.h"

UserPtr newUser(const char, const wchar_t*, const wchar_t*);

StatusPtr initUserController();
UserPtr getRaw();
StatusPtr addUser();
StatusPtr deleteUser();
StatusPtr searchUser();
StatusPtr editUser();

#endif //KECHENGSHEJI_USERCONTROLLER_H
