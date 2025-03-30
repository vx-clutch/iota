#ifndef TEMPLATE_H
#define TEMPLATE_H

// clang-format off
static char *__C_DEFAULT_SORCE_CODE = "#include <stdio.h>\n\nint\nmain(void)\n{\n\tprintf(\"Hello from Iota!\");\n\treturn 0;\n}";
static char *__CC_DEFAULT_SORCE_CODE = "#include <iostream>\n\nint\nmain(void)\n{\n\tstd::cout << \"Hello from Iota!\" << std::endl;\n\treturn 0;\n}";
static char *__PYTHON_DEFAULT_SORCE_CODE = "print(\"Hello from Iota!\")";
// clang-format on

#endif
