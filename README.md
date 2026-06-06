# Algorithms Lab

Welcome to the **Algorithms Lab Implementations** repository. This workspace hosts a collection of performance-driven algorithmic paradigms implemented in modern, idiomatic C++. The catalog covers foundational data exploration frameworks up to complex optimization algorithms, focusing on clean software design, bounding heuristics, and clear execution flows.


---

## 🚀 Repository Blueprint & Paradigms

The codebase categorizes complex computational paradigms into accessible reference blueprints:

### 🧩 1. Dynamic Programming (DP)
Highly optimal workflows evaluating optimization states via memo tables or bottom-up tabulation matrix tracking:
* **0/1 Knapsack Optimization** (`knapsack.cpp`): Multidimensional decision tracking matrix mapping maximum weight-to-value yields under exact bounding structures.
* **Fibonacci Tabulation** (`fibonacci_tabulation.cpp`): Bottom-up sequence matrix population enforcing optimized space allocations.
* **Fibonacci Memoization** (`fibonacci_memoization.cpp`): Top-down recursive exploration utilizing structural state tracking layers to prune computational branches.

### 🔍 2. Advanced Graph Theory & Network Traversals
Comprehensive vertex scanning, connectivity validation, single-source route optimization, and minimum path discovery patterns:
* **Dijkstra's Algorithm** (`dijkstra.cpp`): Priority-queue optimized single-source shortest path implementation resolving non-negative edge constraints via continuous structural path relaxation steps.
* **Prim's Minimum Spanning Tree** (`prim.cpp`): Min-heap based structural exploration compiling minimum cost connection paths without introducing edge cycle hazards.
* **Graph Traversal (BFS)** (`graph_bfs.cpp`): Clean queue-driven layer discovery parsing structural adjacent nodes in precise tier sequence order.
* **Graph Traversal (DFS)** (`graph_dfs.cpp`): Classic object-oriented depth explorations leveraging stack recurrence mechanics to chart unique sub-components.
* **DFS Connectivity Check** (`graphvertex_dfs.cpp`): Target-driven connectivity scanner mapping valid interactive pathways between targeted source and endpoint indices.

### 🔄 3. Backtracking & Combinatorial Exploration
State-space systematic searches optimizing problem bounds via state pruning mechanics and strict logical rules:
* **Traveling Salesman Problem** (`tsp.cpp`): Hamiltonian cycle search algorithm embedding optimal branching heuristics to bypass unviable sub-paths early.
* **Sum of Subsets Solver** (`sumofsubsets.cpp`): Pruned solution-tree matrix tracking subsets conforming strictly to a target integer weight sum.

### ⚡ 4. Classic Divide-and-Conquer
Efficient large-scale data segmentation schemes minimizing computational runtime profiles:
* **Merge Sort Grid** (`mergesort.cpp`): Balanced array bifurcation sorting model utilizing deterministic logic constraints.
* **Iterative Binary Search** (`binarysearch.cpp`): Overflow-protected midpoint hunting schema tracking values across sorted index blocks.

---

## 🛠️ Compilation & Execution Controls

The implementations rely on native configurations inside standard standard-compliant environments. Compile any standalone executable using a modern `g++` compiler layout:

```bash
# General Compilation Template
g++ -O3 -std=c++17 <filename>.cpp -o <output_executable>

# Sample Compilation: Executing Dijkstra Path Optimization
g++ -O3 -std=c++17 dijkstra.cpp -o dijkstra_exe

# Run the Compiled Binary
./dijkstra_exe
## Getting Started

### Prerequisites
To run these implementations, you will need:
* **Compiler**: GCC/G++ (for C/C++) or Python 3.x
* **IDE/Editor**: VS Code, Code::Blocks, or PyCharm

---

## Author

Durjoy Barua / https://github.com/iamdurjoybarua

Feel free to use these examples as a foundation for your own projects and to experiment with the code! 
Happy coding!

