#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3

struct Point {
    double x, y;
    int label;
};

double distance(struct Point a, struct Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    struct Point data[] = {
        {1.0, 2.0, 0},
        {2.0, 1.0, 0},
        {2.0, 3.0, 0},
        {3.0, 2.0, 0},
        {5.0, 4.0, 1},
        {6.0, 5.0, 1},
        {7.0, 7.0, 1},
        {8.0, 6.0, 1}
    };

    struct Point query = {6.0, 2.0};

    int n = sizeof(data) / sizeof(data[0]);

    double distances[n];

    for (int i = 0; i < n; i++) {
        distances[i] = distance(data[i], query);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (distances[i] > distances[j]) {
                double temp = distances[i];
                distances[i] = distances[j];
                distances[j] = temp;

                struct Point temp_point = data[i];
                data[i] = data[j];
                data[j] = temp_point;
            }
        }
    }

    int count_0 = 0;
    int count_1 = 0;

    for (int i = 0; i < K; i++) {
        if (data[i].label == 0) {
            count_0++;
        } else {
            count_1++;
        }
    }

    if (count_0 > count_1) {
        printf("Punctul de date (%.1f, %.1f) apartine clasei 0.\n", query.x, query.y);
    } else {
        printf("Punctul de date (%.1f, %.1f) apartine clasei 1.\n", query.x, query.y);
    }

    return 0;
}
