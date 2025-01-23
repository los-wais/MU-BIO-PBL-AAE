#include "pointreader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readPoints(const char* file, point_t** points) {
    FILE* fp;
    if (fopen_s(&fp, file, "r") != 0) {
        return -1; // Error opening file
    }

    int capacity = 10;
    int size = 0;
    *points = (point_t*)malloc(capacity * sizeof(point_t));

    if (!*points) {
        fclose(fp);
        return -1; // Memory allocation failure
    }

    while (!feof(fp)) {
        if (size >= capacity) {
            capacity *= 2;
            *points = (point_t*)realloc(*points, capacity * sizeof(point_t));
            if (!*points) {
                fclose(fp);
                return -1; // Memory allocation failure
            }
        }

        point_t temp;
        if (fscanf_s(fp, "%lf,%lf,%lf", &temp.t, &temp.theta, &temp.radius) == 3) {
            (*points)[size++] = temp;
        }
    }

    fclose(fp);
    return size;
}


