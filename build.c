#include "cbuild.h"
#include "Syncio/syncio.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        ASSERT(false, "Usage %s <filename> <number-of-files> <is_cpp>");
    }

    CBuildConfig config = cbuild_default_config(argv[1], argv[2], "Syncio.exe");
    cbuild_set_language_flags(&config, argv[3]);
    cbuild_run(&config);
}