//
// Created by muzhou on 2020/12/18.
//

#ifndef KECHENGSHEJI_FILECONTROLLER_H
#define KECHENGSHEJI_FILECONTROLLER_H

#include "../Model/MetaModel.h"
#include "../Model/DataModel.h"
#include "../Model/StatusModel.h"

StatusPtr readDataFile(MetaPtr);
StatusPtr writeDataFile(MetaPtr);

#endif //KECHENGSHEJI_FILECONTROLLER_H
