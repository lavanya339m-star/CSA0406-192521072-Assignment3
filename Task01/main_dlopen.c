#include <stdio.h>
#include <dlfcn.h>
typedef int (*encrypt_fn)(const char *);
typedef const char *(*version_fn)(void);
int main(void) {
    void *h = dlopen("./libcrypto_demo.so", RTLD_NOW);
    if (!h) { fprintf(stderr, "dlopen: %s\n", dlerror()); return 1; }
    dlerror();
    encrypt_fn enc = (encrypt_fn)dlsym(h, "encrypt_text");
    const char *e = dlerror();
    if (e || !enc) { fprintf(stderr, "dlsym: %s\n", e ? e : "missing symbol"); dlclose(h); return 1; }
    version_fn ver = (version_fn)dlsym(h, "library_version");
    e = dlerror();
    if (e || !ver) { fprintf(stderr, "dlsym: %s\n", e ? e : "missing symbol"); dlclose(h); return 1; }
    printf("Loaded %s; result=%d\n", ver(), enc("sample"));
    dlclose(h);
    return 0;
}
