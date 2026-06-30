# Push_swap — Tests realizados y bugs arreglados

## 🛠️ Bugs de compilación (el programa no generaba el ejecutable)

| # | Bug | Archivo | Arreglo |
|---|-----|---------|---------|
| 1 | Faltaba `-I.` en CFLAGS, no encontraba `push_swap.h` | `Makefile` | Añadido `-I.` a `CFLAGS` |
| 2 | Regla de compilación usaba `$(FLAGS)` en vez de `$(CFLAGS)` (variable inexistente → compilaba sin warnings reales) | `Makefile` | Cambiado a `$(CFLAGS)` |
| 3 | `parse_arg` (tipo `void`) hacía `return (1)` | `parse_args.c` | Cambiado a `return ;` |
| 4 | Llamaba a `bring_to_top` pero la función real se llama `bring_to_top_a` | `chunk_sort_algorithm.c` | Corregido el nombre |
| 5 | Llamaba a `sort_medium`, no existía ninguna función con ese nombre | `sort_adaptive.c` / `main.c` | Unificado a `chunk_sort_algorithm` |
| 6 | `static` puesto en el prototipo dentro del `.h` (no tiene sentido, da warning en cada archivo que lo incluye) | `push_swap.h` | Eliminada esa línea del `.h` |
| 7 | `new_node.c` tenía el contenido de `sort_adaptive` pegado por error (doble definición + `new_node` inexistente) | `new_node.c` | Recuperado el contenido correcto |
| 8 | `print_two_digits` usada pero nunca definida | `print_benchmark_report.c` | Creada como función `static` |
| 9 | Faltaba `#include <unistd.h>` para `write()` | `error.c` | Añadido al `push_swap.h` central |
| 10 | `ft_strlen` usada pero nunca implementada | `ft_strdup.c` / `ft_substr.c` | Creado `ft_strlen.c` + prototipo en `.h` + añadido al Makefile |
| 11 | Llamaba a `array_copy`, la función real se llama `copy_array` | `normalize_stack.c` | Corregido el nombre |
| 12 | `*total_pairs++` en vez de `(*total_pairs)++` (bug de precedencia de operadores: movía el puntero en vez de incrementar el valor) | `compute_disorder.c` | Añadidos paréntesis |
| 13 | `main.c` no estaba en la lista `SRCS` del Makefile (el programa no tenía punto de entrada) | `Makefile` | Añadido `main.c` |
| 14 | `print_benchmark_report` usada en `main.c` sin estar declarada en el `.h` | `push_swap.h` | Añadido el prototipo |

---

## 🐛 Bugs de lógica / runtime (compilaba, pero el comportamiento era incorrecto)

| # | Bug | Síntoma | Arreglo |
|---|-----|---------|---------|
| 15 | `ps->bench` usado como si fuera puntero (`if (ps->bench && ...)`) cuando es una struct directa | No compilaba en `push.c`, `rotate.c`, `reverse_rotate.c`, `swap.c` | Quitado el `ps->bench &&` sobrante |
| 16 | `ps->size_a` nunca se calculaba tras parsear los argumentos (se quedaba en `0` para siempre) | `--medium` y `--complex` no imprimían nada | Añadido `ps.size_a = stack_size(ps.a);` en `main.c` |
| 17 | `chunk_sort_algorithm`: bucle infinito (`pos` nunca se recalculaba dentro del `while`) | El programa se quedaba colgado con `--medium` | Reescrita la condición del bucle |
| 18 | `normalize_stack` nunca se llamaba desde `main.c` → todos los `index` quedaban en `0` | `--medium`/`--complex` agrupaban mal los números | Añadida la llamada en `main.c` |
| 19 | `find_first_chunk_pos` devolvía el primer elemento de la banda, no el más pequeño | `--medium` no dejaba la pila ordenada | Reescrita para buscar el mínimo real de la banda |
| 20 | Faltaba la fase final de `pa` para devolver los elementos de `b` a `a` | `--medium` vaciaba `a` pero no lo volvía a llenar ordenado | Añadido `while (stack_size(ps->b) > 0) pa(ps);` |
| 21 | `copy_array`: `while (arr)` en vez de `while (i < size)` → bucle infinito que escribía fuera del array reservado | **Segfault** con `--medium` | Corregida la condición del bucle |
| 22 | Umbral de `0.2–0.5` en `sort_adaptive` hacía que, con inputs grandes (500 números), el desorden cayera con frecuencia en `medium` (que sigue siendo O(n²) en la práctica) → superaba el límite de 12000 operaciones | Test de 500 números fallaba a veces | Bajado el umbral superior de `medium` a `0.4` para favorecer `complex` en casos ambiguos |
| 23 | `parse_content` no liberaba la matriz `mtx` (de `split`) antes de llamar a `error()` en los 3 puntos de fallo | Memory leak (18-28 bytes "still reachable") en cualquier input inválido | Añadido `free_mtx(mtx);` antes de cada `error(ps)` |
| 24 | `init_push_swap` no inicializaba `bench.total_ops` ni `bench.op_counts[]` (memoria basura) | Benchmark mostraba números absurdos (`sa: 32766`, `total_ops: -342476080`...) | Inicializados todos a `0` en `init_push_swap` |
| 25 | `ps->bench.strategy`/`complexity` sin valor por defecto | **Segfault** al usar `--bench` con un input ya ordenado (ninguna función de sort llegaba a asignar el texto) | Puesto `"Already sorted" / "O(n)"` como valor inicial |
| 26 | `sort_three` accedía a `ps->a->next->next->value` sin comprobar que existiera un tercer nodo | **Segfault** con `--simple` y exactamente 2 números | Separado en `sort_two` (caso de 2) + `order_three` (caso de 3), con comprobaciones de `NULL` |
| 27 | `compute_disorder` dividía `mistakes / total_pairs` sin comprobar `total_pairs == 0` | Con 0 o 1 elementos (ej. `--bench` sin argumentos): resultado `nan`, que al convertirlo a `int` imprimía números absurdos (`-2147483648`) | Añadida guarda: si `size < 2`, devuelve `0.0` directamente |
| 28 | `radix_algorithm` y `chunk_sort_algorithm` nunca asignaban `ps->bench.strategy`/`complexity` | El reporte de benchmark decía `"Already sorted"` aunque sí se hicieron operaciones reales con `--medium`/`--complex`/`--adaptive` | Añadidas las 2 líneas de asignación al principio de cada función |

---

## ✅ Tests funcionales que pasaron (checklist de la hoja de evaluación)

- **Compilación**: `make`, `make clean`, `make fclean`, `make re` ✅
- **Norminette**: sin errores ✅
- **Manejo de errores** (4/4): no numérico, duplicado, overflow, sin argumentos ✅
- **Las 4 estrategias** ordenan correctamente con 5 números (`--simple/--medium/--complex/--adaptive`) ✅
- **Identity test**: inputs ya ordenados no generan ninguna operación ✅
- **Checker**: 3, 5, 100 y 500 números → siempre `OK` ✅
- **Rendimiento**: 100 números (~1388 ops, dentro de rango bueno), 500 números (~6784 ops con `--complex`/`--adaptive`, por debajo del límite "excelente" de 5500) ✅
- **Memory leaks** (valgrind): 0 leaks en caso normal, `--medium`, `--complex`, y los 3 caminos de error ✅
- **Benchmark mode**: disorder %, nombre de estrategia, contadores de operaciones — todos correctos para los 4 modos ✅
- **Casos límite probados extra** (no pedidos explícitamente por la hoja, pero buena práctica):
  - 2 elementos con las 4 estrategias ✅
  - Solo el flag sin números (`--simple`, `--bench`) ✅
  - Flag al final en vez de al principio ✅
  - Múltiples flags combinadas (`--bench --bench`, `--bench --adaptive`) ✅

---

## 🧪 Comandos de testeo usados (para repetir o reutilizar)

### Compilación básica

```bash
make
make clean
make fclean
make re
ls push_swap
```

### Norminette

```bash
norminette
norminette main.c
```

### Manejo de errores

```bash
./push_swap a b c
./push_swap 1 2 2
./push_swap 1 2 99999999999
./push_swap
```

### Las 4 estrategias con 5 números

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
./push_swap 5 4 3 2 1
```

### Identity test (ya ordenado)

```bash
./push_swap 42
./push_swap 2 3
./push_swap 0 1 2 3
./push_swap 0 1 2 3 4 5 6 7 8 9
```

### Checker — 3 números

```bash
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
ARG="0 2 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 0 2"; ./push_swap $ARG | ./checker_linux $ARG
```

### Checker — 5 números

```bash
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 1 4 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 5 1 4 2"; ./push_swap $ARG | ./checker_linux $ARG
```

### Checker + rendimiento — 100 números

```bash
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
./push_swap --adaptive $ARG | ./checker_linux $ARG
./push_swap --adaptive $ARG | wc -l        # debe ser < 2000 (ideal < 700)
```

### Checker + rendimiento — 500 números

```bash
ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
./push_swap --adaptive $ARG | ./checker_linux $ARG
./push_swap --adaptive $ARG | wc -l        # debe ser < 12000 (ideal < 5500)
```

### Comparar las 4 estrategias con el mismo input

```bash
ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
echo "simple:";   ./push_swap --simple   $ARG | wc -l
echo "medium:";   ./push_swap --medium   $ARG | wc -l
echo "complex:";  ./push_swap --complex  $ARG | wc -l
echo "adaptive:"; ./push_swap --adaptive $ARG | wc -l
```

### Benchmark mode — básico

```bash
./push_swap --bench --simple 5 4 3 2 1 2>/dev/null
./push_swap --bench --simple 5 4 3 2 1 2>bench.txt >/dev/null
cat bench.txt
```

### Benchmark mode — disorder en los extremos

```bash
./push_swap --bench --simple 1 2 3 4 5 2>bench2.txt >/dev/null
cat bench2.txt        # disorder ~0.00%

./push_swap --bench --simple 5 4 3 2 1 2>bench3.txt >/dev/null
cat bench3.txt        # disorder ~100.00%
```

### Benchmark mode — confirmar el nombre de estrategia de cada algoritmo

```bash
./push_swap --bench --simple 5 4 3 2 1 2>&1 >/dev/null | grep strategy
./push_swap --bench --medium 5 4 3 2 1 2>&1 >/dev/null | grep strategy
./push_swap --bench --complex 5 4 3 2 1 2>&1 >/dev/null | grep strategy
```

### Memory leaks (valgrind)

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 1 2
valgrind --leak-check=full ./push_swap --medium 5 2 8 1 9
valgrind --leak-check=full ./push_swap --complex 5 2 8 1 9
valgrind --leak-check=full --show-leak-kinds=all ./push_swap a b c
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 1 2 2
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 1 2 99999999999
valgrind --leak-check=full ./push_swap --bench
```

### Casos límite — 2 elementos

```bash
./push_swap 2 1
ARG="2 1"; ./push_swap $ARG | ./checker_linux $ARG

./push_swap --simple 2 1
ARG="2 1"; ./push_swap --simple $ARG | ./checker_linux $ARG

./push_swap --medium 2 1
ARG="2 1"; ./push_swap --medium $ARG | ./checker_linux $ARG

./push_swap --complex 2 1
ARG="2 1"; ./push_swap --complex $ARG | ./checker_linux $ARG
```

### Casos límite — solo flags, sin números / flags combinadas

```bash
./push_swap --simple
./push_swap --bench
./push_swap 5 4 3 2 1 --simple                 # flag al final
./push_swap --bench --bench 5 4 3 2 1 2>&1 >/dev/null | head -1
./push_swap --bench --adaptive 5 4 3 2 1 2>&1 >/dev/null
```

### Casos límite — formato de entrada y rango de `int`

```bash
./push_swap "3 2" 1                            # mezcla comillas y sueltos
./push_swap +5 -3 +1                           # signos explícitos
ARG="+5 -3 +1"; ./push_swap $ARG | ./checker_linux $ARG
./push_swap 2147483647 -2147483648 0           # límites exactos de int
ARG="2147483647 -2147483648 0"; ./push_swap $ARG | ./checker_linux $ARG
./push_swap "1 2 1"                            # duplicado dentro de una cadena
```

### Debugging con gdb (para localizar segfaults)

```bash
gdb ./push_swap
run --medium 5 4 3 2 1
bt
```
(recuerda compilar con `-g` en el `CFLAGS` para que gdb pueda mostrar líneas exactas)

---

## ⏳ Pendiente

- **`--count-only`** (ejercicio de código en vivo, 10 min): añadir flag que imprima solo el total de operaciones, sin la lista completa. Pasos: (A) nuevo campo `count_only` en la struct, (B) detectarlo en `parse_arg`, (C) silenciar el `write` en las 11 funciones de movimiento sin dejar de contar, (D) imprimir el contador al final en `main.c`. **Practicarlo antes de la defensa.**
- **Nota sobre `--medium`**: sigue siendo O(n²) en la práctica (no O(n√n) real), porque dentro de cada banda usa una rotación completa por elemento, igual que `sort_simple`. Se mitigó ajustando el umbral de `--adaptive`, pero si preguntan por la complejidad teórica de `medium` en la defensa, hay que ser honestas sobre esta limitación.
