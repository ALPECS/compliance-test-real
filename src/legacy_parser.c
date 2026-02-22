// SPDX-License-Identifier: GPL-2.0
// Copyright 2019 Legacy Systems Inc.
//
// This parser handles the old data format used in v1.x releases.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[64];
    int  version;
    int  flags;
} legacy_record_t;

int parse_legacy_record(const char *buf, size_t len, legacy_record_t *out) {
    if (!buf || len < sizeof(legacy_record_t)) {
        return -1;
    }
    memcpy(out, buf, sizeof(legacy_record_t));
    return 0;
}

void print_legacy_record(const legacy_record_t *rec) {
    printf("Record: %s (v%d, flags=0x%x)\n",
           rec->name, rec->version, rec->flags);
}
