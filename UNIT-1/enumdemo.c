#include <stdio.h>
enum week {mon, tue, wed, thurs, fri, sat, sun};

int main() {
    enum week w;
    w = sun;
    printf("Constant value of tue is: %d", w);
    return 0;
}
