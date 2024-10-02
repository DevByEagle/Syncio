#include "cbuild.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: CBuild <target>\n");
        return 1;
    }

    CBuildConfig config = load_config("project.json");
    int found = 0;
    
    for (int i = 0; i < config.target_count; i++) {
        if (strcmp(config.targets[i].name, argv[1]) == 0) {
            build_target(config.targets[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        fprintf(stderr, "Error: Target not found: %s\n", argv[1]);
        free_config(config);
        return 1;
    }

    printf("[INFO] Build successfully\n");
    free_config(config);
    return 0;
}