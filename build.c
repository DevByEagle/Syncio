#include "cbuild.h"

int main() {
    const char* src_files[] = {"main.c"};
    CBuildConfig config = cbuild_default_config(src_files, 1, "Syncio.exe");
    cbuild_run(&config);
    return 0;
}