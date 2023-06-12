#include <stdio.h>
int main() {
    char buf[20];
    sscanf("asdf#sdjd@djfkd", "%*[^#]%*c%[^@]", buf);
    printf("%s\n", buf);
}