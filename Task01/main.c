#include <stdio.h>
#include "crypto.h"
int main(void) {
    printf("Library: %s\n", library_version());
    printf("Demo result: %d\n", encrypt_text("sample"));
    return 0;
}
