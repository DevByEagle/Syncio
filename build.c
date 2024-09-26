#include "cbuild.h"

int main() {
    const char* source_files[] = {"main.c"};
    CBuildConfig config = cbuild_default_config(source_files, 1, "Syncio.exe");
    cbuild_add_flags(&config, "-Wall", "-Werror");
    cbuild_run(&config);
    return 0;
}