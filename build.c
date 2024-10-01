#include "cbuild.h"

int main() {
    const char* source_files[] = {"main.cpp"};
    CBuildConfig config = cbuild_default_config(source_files, 1, "Syncio.exe");
    cbuild_set_language_flags(&config, true);
    cbuild_run(&config);
    return 0;
}
