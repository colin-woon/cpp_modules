
// static casts
// ✅ The key technical advantage is compile - time safety.
// ❌ C - style casts can hide dangerous or unintended behavior, especially in large or old code.
// int *x = (int *)3.14; // will compile, even though it’s nonsense. It silently reinterprets a float as a pointer.
// int *x = static_cast<int *>(3.14); // ❌ Compile-time error
