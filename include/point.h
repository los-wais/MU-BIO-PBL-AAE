#pragma once

typedef struct point_t {
    double t;      // Time value
    double theta;  // Angular position (radians)
    double radius; // Optional radius (not used here but kept for extensibility)
} point_t;

void freePoints(point_t** points);