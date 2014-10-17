#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void quine(char *s) {
    int len = strlen(s);
    char *ss = malloc(len * 4);
    int i, j = 0;
    
    for (i = 0; i < len; ++i) {
        switch (s[i]) {
            case '"':
            case '\\':
                ss[j++] = '\\';
                break;
            case '\n':
                ss[j++] = '\\';
                ss[j++] = 'n';
                ss[j++] = '\\';
                break;
        }
        ss[j++] = s[i];
    }
    ss[j] = '\0';
    
    printf("%s(\"\\\n", s);
    printf("%s\"\n", ss);
    printf("    );\n    return 0;\n}\n");
    
    free(ss);
}

int main() {
    quine("\
#include <stdio.h>\n\
#include <stdlib.h>\n\
#include <string.h>\n\
\n\
static void quine(char *s) {\n\
    int len = strlen(s);\n\
    char *ss = malloc(len * 4);\n\
    int i, j = 0;\n\
    \n\
    for (i = 0; i < len; ++i) {\n\
        switch (s[i]) {\n\
            case '\"':\n\
            case '\\\\':\n\
                ss[j++] = '\\\\';\n\
                break;\n\
            case '\\n':\n\
                ss[j++] = '\\\\';\n\
                ss[j++] = 'n';\n\
                ss[j++] = '\\\\';\n\
                break;\n\
        }\n\
        ss[j++] = s[i];\n\
    }\n\
    ss[j] = '\\0';\n\
    \n\
    printf(\"%s(\\\"\\\\\\n\", s);\n\
    printf(\"%s\\\"\\n\", ss);\n\
    printf(\"    );\\n    return 0;\\n}\\n\");\n\
    \n\
    free(ss);\n\
}\n\
\n\
int main() {\n\
    quine"
    );
    return 0;
}
