#include <stdio.h>
#include <string.h>

static void quine(char *s) {
    int len = strlen(s);
    int i;
    
    printf("%s(\"\\\n", s);
    for (i = 0; i < len; ++i) {
        switch (s[i]) {
            case '"':
            case '\\':
                printf("\\");
                break;
            case '\n':
                printf("\\n\\");
                break;
        }
        printf("%c", s[i]);
    }
    printf("\"\n    );\n    return 0;\n}\n");
}

int main() {
    quine("\
#include <stdio.h>\n\
#include <string.h>\n\
\n\
static void quine(char *s) {\n\
    int len = strlen(s);\n\
    int i;\n\
    \n\
    printf(\"%s(\\\"\\\\\\n\", s);\n\
    for (i = 0; i < len; ++i) {\n\
        switch (s[i]) {\n\
            case '\"':\n\
            case '\\\\':\n\
                printf(\"\\\\\");\n\
                break;\n\
            case '\\n':\n\
                printf(\"\\\\n\\\\\");\n\
                break;\n\
        }\n\
        printf(\"%c\", s[i]);\n\
    }\n\
    printf(\"\\\"\\n    );\\n    return 0;\\n}\\n\");\n\
}\n\
\n\
int main() {\n\
    quine"
    );
    return 0;
}
