/* C10 Presentación de una etiqueta. Variante b.
Una utilidad debe mostrar literalmente una etiqueta introducida por el operador. No necesita un intérprete de comandos.
Analiza el archivo con SAST; no es necesario ejecutarlo. Compara las dos variantes. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int mostrar(const char *etiqueta) {
    pid_t pid = fork();
    if (pid < 0) return 1;
    if (pid == 0) {
        execlp("echo", "echo", etiqueta, (char *)NULL);
        _exit(127);
    }
    int status;
    if (waitpid(pid, &status, 0) < 0) return 1;
    return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
}
