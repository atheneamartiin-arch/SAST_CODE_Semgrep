"""P12 Archivo temporal de diagnóstico. Variante b.
Se escribe un informe temporal de un dispositivo en un sistema multiusuario. El archivo se elimina al terminar de procesarlo.
Analiza el archivo con SAST; no es necesario ejecutarlo. Compara las dos variantes."""

import os
import tempfile
def procesar(texto):
    f = tempfile.NamedTemporaryFile(mode="w", delete=False, encoding="utf-8")
    nombre = f.name
    try:
        with f:
            f.write(texto)
        with open(nombre, encoding="utf-8") as f:
            return f.read()
    finally:
        os.unlink(nombre)
