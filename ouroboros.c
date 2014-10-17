#include <stdio.h>
#include <string.h>

static void quine(char *s) {
    printf("%s(\"\\\n", s);
    while (*s != '\0') {
        switch (*s) {
            case '"':
            case '\\':
                printf("\\");
                break;
            case '\n':
                printf("\\n\\");
                break;
        }
        printf("%c", *s++);
    }
    printf("\"\n    );\n    return 0;\n}\n");
}

int main() {
    quine("\
#include <stdio.h>\n\
#include <string.h>\n\
\n\
static void quine(char *s) {\n\
    printf(\"%s(\\\"\\\\\\n\", s);\n\
    while (*s != '\\0') {\n\
        switch (*s) {\n\
            case '\"':\n\
            case '\\\\':\n\
                printf(\"\\\\\");\n\
                break;\n\
            case '\\n':\n\
                printf(\"\\\\n\\\\\");\n\
                break;\n\
        }\n\
        printf(\"%c\", *s++);\n\
    }\n\
    printf(\"\\\"\\n    );\\n    return 0;\\n}\\n\");\n\
}\n\
\n\
int main() {\n\
    quine"
    );
    return 0;
}
