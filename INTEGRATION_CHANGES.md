# MFMS – Integration changes (Student 6)

The five modules were written separately and could not run together: each had
its own `main()`, used `scanf()` (which loops forever or skips input when the
user types a letter), and had mismatched header/function names. This pack
fixes that so the whole system builds and runs as **one program**.

## Build and run (from the repository root)

```
gcc -std=c99 -Wall -Wextra -pedantic -o mfms main.c validation.c employees/employees.c budget/budget.c supplier/suppliers.c assets/assets.c reports/reports.c
./mfms            (Windows: mfms.exe)
```

Tested end to end: add/display/search data in every module, all four reports,
invalid menu choices, negative and non-numeric numbers, bad e-mail addresses.
It compiles with `-std=c99 -Wall -Wextra -pedantic` with one harmless warning
(unused parameter `departments` in `reports.c`).

## Files changed, by owner

**Root (Student 6)**
- `main.c` – NEW. Main menu; calls `employeeMenu()`, `budgetMenu(budgets, &budgetCount)`, `supplierMenu()`, `assetmanagement()`, `displayReports()`.
- `common.h` – trimmed to the shared money limits and main-menu numbers (module sizes live in each module's own header, so nothing clashes).
- `Makefile` – NEW, builds all the files above.
- `validation.c` / `validation.h` – unchanged (already in the repo).

**Employees (Student 1)** – `employees/employees.c`, `employees/employees.h`
- Fixed `#include "employee.h"` → `"employees.h"` and a missing `;` after `validateNonEmptyString(...)` in the header.
- Added `employeeMenu()` (the menu logic that used to be in `employees/main.c`).
- Removed `static` from the six employee arrays and declared them `extern` in the header so Reports can read them.
- Every `scanf()` replaced by a validation function (`readId`, `readName`, `readText`, `readPositiveMoney`, `readMoney`). Names with spaces now work.
- **Delete `employees/main.c`** – the root `main.c` replaces it (two `main()` functions cannot exist).

**Budget (Student 2)** – `budget/budget.c`, `budget/budget.h`
- **Rename `budget .c` → `budget.c`** (the space in the file name breaks compiling).
- Removed the test `main()`; the budgets array and `budgetCount` are now global (declared `extern` in the header) so Reports can read them.
- Fixed a stray word `information` in `budget.h` that stopped it compiling.
- `scanf()` replaced with `readMenuChoice`, `readInt`, `readText`, `readMoney` (also removed the `getchar()` workaround).

**Suppliers (Student 3)** – `supplier/suppliers.c`, `supplier/suppliers.h`
- Added `supplierMenu()` (there was no menu).
- Telephone array enlarged from 10 to 20 characters (a 10-digit number such as 0612072052 overflowed the old array).
- `scanf()` replaced with `readInt`, `readText`, `readEmail`, `readPhone`.
- Data arrays declared `extern` in the header for Reports.

**Assets (Student 4)** – `assets/assets.c`, `assets/assets.h`
- Removed the test `main()`.
- Header now matches the real function names (`searchAsset`, `assetmanagement`).
- Fixed printf bug `N$.2f` → `N$%.2f` in search output.
- `scanf()` replaced with `readInt`, `readText`, `readMoney`, `readMenuChoice`.
- Data arrays declared `extern` in the header for Reports.

**Reports (Student 5)** – `reports/reports.c`, `reports/reports.h`
- Added the missing `#include <stdio.h>` and the other includes.
- Added `displayReports()` (the Reports menu) that feeds each module's data into `employeeReport`, `budgetReport`, `supplierReport` and `assetReport`.
- Header typo `diaplayReports` → `displayReports`; phone array size updated to 20 to match suppliers.

## Things each owner should still be able to explain / may want to improve
- **Student 2:** `budget.c` uses `struct` and pointers (`int *count`), which are not in the Week 1–8 notes. It works, but be ready to explain it.
- **Student 3:** only 5 suppliers can be stored (their original design).
- **Student 4:** duplicate asset IDs are not rejected; the ID is a number.
- **Student 5:** `employeeReport` does not use the `departments` parameter (compiler warning only).
- **Everyone:** read the diff of your own file so you can answer "what does this function do / what did you change?".
