#include <stdlib.h>
#include "Controller/FileController.h"

int main() {
    initItemController();
    initUserController();
    MetaPtr meta = malloc(sizeof(MetaModel));
    meta->userNumber = 1;
    writeDataFile(meta);
    return 0;
}