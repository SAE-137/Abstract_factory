#ifndef LANGUAGESPECIFIC_H
#define LANGUAGESPECIFIC_H

#endif // LANGUAGESPECIFIC_H
#pragma once

namespace Cpp {
enum AccessModifier { PUBLIC, PROTECTED, PRIVATE };
enum MethodModifier { STATIC = 1, VIRTUAL = 1 << 1, CONST = 1 << 2 };
}

namespace Java {
enum AccessModifier { PUBLIC, PROTECTED, PRIVATE, DEFAULT };
enum MethodModifier { STATIC = 1, FINAL = 1 << 1, SYNCHRONIZED = 1 << 2 };
}

namespace CSharp {
enum AccessModifier { PUBLIC, PRIVATE, PROTECTED, INTERNAL, PROTECTED_INTERNAL };
enum MethodModifier { STATIC = 1, VIRTUAL = 1 << 1, ABSTRACT = 1 << 2, SEALED = 1 << 3 };
}
