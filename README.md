# MetroQuest Delhi

**MetroQuest Delhi** — a personal C++ implementation of the Delhi Metro route finder using Dijkstra's algorithm.

**Author:** shreya831-hub (Shreya Singh)

## Features
- Dijkstra's algorithm (priority-queue / adjacency list) for efficient shortest-path queries.
- Simple input format for quick testing and reproducible results.
- Well-documented and easy to extend for real station names or visualization.

## Input Format
```
n m
u1 v1 w1
u2 v2 w2
...
um vm wm
s t
```
- `n` = number of stations (nodes)
- `m` = number of edges (tracks)
- Each edge line: `u v w` (1-based node indices, weight w)
- Final line: `s t` (source and destination station indices)

### Example
```
5 6
1 2 7
1 3 9
1 5 14
2 3 10
2 4 15
3 4 11
1 4
```

## How to compile & run
**Linux / macOS / WSL**
```bash
g++ -std=c++17 -O2 main.cpp -o metro
./metro < input_examples/sample1.txt
```

**Windows (MinGW)**
```bash
g++ -std=c++17 -O2 main.cpp -o metro.exe
metro.exe < input_examples/sample1.txt
```

## Files
- `main.cpp` — implementation
- `README.md` — this file
- `input_examples/sample1.txt` — sample input
- `.gitignore` — recommended ignore rules
- `LICENSE` — MIT license (optional)

## Notes & Extensions
- Replace numeric station ids with real station names by adding a `stations.txt` mapping file.
- Add visualization (e.g., a small web app) to show routes on a map.
- Convert to weighted directed graph if needed for one-way tracks.

## License
MIT License — see `LICENSE` file for details.
