#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int frames[MAX_FRAMES];
int page_table[MAX_PAGES];
int page_faults = 0;

void lru(int page) {
    int i, j, min_index;


    for (i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] == page) {
            return;
        }
    }

    page_faults++;

    for (i = 0; i < MAX_FRAMES; i++) {
        for (j = 0; j < MAX_PAGES; j++) {
            if (frames[i] == page_table[j] ) {

                min_index = i;
                break;
            }
        }
    }

    frames[min_index] = page;
}

int main() {
    int pages[MAX_PAGES] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6};
    int i;

    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < MAX_PAGES; i++) {
        page_table[i] = -1;
    }

    for (i = 0; i < MAX_PAGES; i++) {
        lru(pages[i]);

        page_table[pages[i]] = i;
    }

    printf("LRU: %d page faults\n", page_faults);

    return 0;
}
