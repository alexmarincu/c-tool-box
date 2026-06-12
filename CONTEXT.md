# C Tool Box (ctb) — Domain Glossary

## Memory Model

- **No heap allocation:** The library never calls malloc/free. All memory is provided by the caller.
- **User-provided storage:** Containers that need storage arrays (hash table buckets, heap entries, etc.) receive them from the caller at initialization, either via an `init` pointer argument or a helper macro.
- **Intrusive nodes:** Linked structures (SList, DList, Stack, Queue) use intrusive nodes (`ctb_SNode_t`, `ctb_DNode_t`) that the user embeds in their own structs.

## Naming Convention

- **Underlying storage primitives:** `ctb_Array`, `ctb_SList`, `ctb_DList`
- **ADTs built on storage:** `ctb_<ADT><Storage>` — e.g., `ctb_StackArray`, `ctb_StackList`, `ctb_QueueArray`, `ctb_QueueList`

### ADT × Storage Matrix

| ADT             | Array              | SList             | DList              |
|-----------------|:------------------:|:-----------------:|:------------------:|
| Stack           | `StackArray`       | `StackList`       | —                  |
| Queue           | `QueueArray`       | —                 | `QueueList`        |
| Deque           | `DequeArray` (ring)| —                 | `DequeList`        |
| Map (hash)      | `MapArray` (open)  | `MapList` (chain) | —                  |
| Heap / PQueue   | `HeapArray`        | —                 | —                  |
| BitArray        | `BitArray`         | —                 | —                  |

- `QueueList` is backed by DList for O(1) enqueue + dequeue.

## Standard Container Interface

All containers should expose these operations where applicable:

| Function        | Returns    | Meaning                                  |
|-----------------|------------|------------------------------------------|
| `init`          | `self*`    | Initialize the container                 |
| `isEmpty`       | `bool`     | True if container holds no elements      |
| `getLength`     | `size_t`   | Number of elements currently held        |
| `clear`         | `void`     | Remove all elements                      |
| `forEach`       | `void`     | Apply operation to each element          |
| `find`          | element*   | Find first element matching predicate    |
| `getCapacity`   | `size_t`   | Maximum number of slots available        |

- **`getLength`** = actual element count (how many items are stored).
- **`getCapacity`** = maximum available slots (total storage, not item count).
- **`getSize`** = byte size of a single element or the data structure itself (context-dependent).

### Init Macro Pattern

For array-backed ADTs, the init macro mirrors `ctb_Array(arr)`:
```c
#define ctb_StackArray(arr) \
    (&(ctb_StackArray_t){ .array = *(ctb_Array(arr)), .length = 0 })
```
The macro parameter is named `arr` to match `ctb_Array`.

## Configuration

- **`ctb_config.h`:** Optional user-provided header. Library ships a default stub. Users place their own `ctb_config.h` earlier in the include path to override settings.
- **Configurables:**
  - `ctb_config_assert(expr)` — assertion macro. Defaults to `assert(expr)`.
  - `ctb_config_staticAssert(expr, id)` — compile-time assertion. Defaults to the `typedef char` trick.
- **Public forwarding:** `ctb_assert(expr)` → `ctb_config_assert(expr)`, `ctb_staticAssert(expr, id)` → `ctb_config_staticAssert(expr, id)`.
- **Delivery:** Shipped as a real `ctb_config.h` in `src/`. Zero-config works out of the box; users override via include path.
- Every configurable has a safe default in the shipped `ctb_config.h`.

## Push/Pop Semantics

- **`push(self, value)`** — copies value into the container via `memcpy`. Takes `void const *`.
- **`pop(self)`** — returns `void *` pointer to the removed element. Caller can memcpy before the slot is invalidated.
- **`peek(self)`** — returns `void *` pointer to the top/next element without removing it.

## Error Handling

- **`ctb_assert` is user-configurable:** Defined as a macro that the user can override before including library headers. Defaults to `assert()`. Embedded users may redefine it to a no-op or a custom handler.
- **Out-of-bounds access** returns `NULL` (pointer types) or `SIZE_MAX` (index lookups).
