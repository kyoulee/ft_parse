#include <stdio.h>
#include <stdlib.h>

/* Handlers */
void handle_help(const void *arg) {
    (void)arg;
    printf("Help requested.\n");
    exit(0);
}

void handle_verbose(const void *arg) {
    (void)arg;
    printf("Verbose mode enabled.\n");
}

void handle_count(const void *arg) {
    char *port_str = (char *)arg;
    if (port_str) {
        printf("count set to: %s\n", port_str);
    }
}
