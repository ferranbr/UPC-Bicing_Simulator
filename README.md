# 🚲 Bifurcated Bicing (OPRO2 Project - UPC)

This is a C++ university project for the OPRO2 (Object-Oriented Programming) course at UPC-FIB. The program simulates a "Bicing" (bike-sharing) management system with a unique core feature: the stations are organized in a hierarchical **binary tree structure**.

The system manages the complete lifecycle of bicycles, stations, and trips. It notably implements complex recursive algorithms to rebalance the bike network and efficiently assign new bikes to stations based on need.



[Image of a binary tree data structure]


## ⚙️ Core Features

The program accepts a series of commands via the console to manage the network:

* **Bike Management:**
    * `alta_bici (ab)`: Adds a new bike to a specific station.
    * `baja_bici (bb)`: Removes an existing bike from the system.
    * `mover_bici (mb)`: Moves a bike from one station to another, logging the trip.

* **Data Querying:**
    * `estacion_bici (eb)`: Queries the current station of a specific bike.
    * `viajes_bici (vb)`: Lists the entire travel history for a specific bike.
    * `bicis_estacion (be)`: Lists all bikes currently at a station, sorted by ID.
    * `plazas_libres (pl)`: Returns the total number of free spots in the entire system.

* **Station Management:**
    * `modificar_capacidad (mc)`: Changes the total capacity of a station.

## 🧠 Complex Logic & Algorithms

The core complexity of this project lies in two recursive operations that traverse the station tree:

### 1. Rebalance Stations (`subir_bicis` or `sb`)

This operation moves bikes "up" the tree (towards the "first_station" or root) to rebalance the network.

* **Objective:** The system attempts to fill a "parent" station using bikes from its two "child" stations.
* **Implementation:** The `Estaciones::reestructurar_ubis` method implements this logic recursively.
* **Prioritization Logic:**
    1.  The goal is to leave the two child stations with as balanced a number of bikes as possible.
    2.  Priority is given to moving a bike from the child station that currently has *more* bikes.
    3.  In case of a tie (both children have the same number of bikes), the bike with the **smallest bike ID** is moved.
    4.  These rebalancing moves are not logged as "trips".

### 2. Assign Station (`asignar_estacion` or `ae`)

This operation finds the optimal station in the entire network to place a new bike.

* **Objective:** To find the station with the highest **"general vacancy coefficient"**.
* **Calculation:** This coefficient is defined as:
  `(Total free spots in the station AND all its descendants) / (Total number of stations in that sub-tree)`
* **Implementation:** The `Estaciones::assig_est_aux` method calculates this recursively using an immersion strategy. It passes parameters by reference to track the total `ests` (stations) and `libres` (free spots) of each sub-tree.
* **Tie-Breaking:** If two stations have the same vacancy coefficient, the one with the alphabetically **smaller station ID** is chosen.

## 🛠️ Code Structure & Tech

* **Language:** C++
* **Key Data Structures:** `std::map` (for efficient, ID-based management of bikes and stations), `std::vector` (for travel history), and a provided `BinTree<T>` template class.

The project is modeled with 4 primary classes:

1.  **`Bicicleta`** (`.hh`, `.cc`): Represents a single bike. Stores its ID, current location (`ubi`), and a `vector<pair<string, string>>` for its travel history.
2.  **`Estacion`** (`.hh`, `.cc`): Represents a single station. Stores its `capacidad` and a `map<string, Bicicleta>` to hold its current bikes (allowing for fast, sorted access).
3.  **`Bicicletas`** (`.hh`, `.cc`): A global management class. Uses a `map<string, Bicicleta>` to keep a registry of *all* bikes in the system for quick lookup by ID.
4.  **`Estaciones`** (`.hh`, `.cc`): The main controller class. It holds the `BinTree<string>` (the station hierarchy) and a `map<string, Estacion>` to link the tree IDs to the corresponding `Estacion` objects. It implements all recursive logic.

## 🚀 Compilation & Execution

The project is compiled using the provided `Makefile`.

1.  **Compile:**
    ```bash
    make
    ```
2.  **Execute:**
    ```bash
    ./program.exe < sample.inp > sample.out
    ```
3.  **Verify Output:**
    ```bash
    diff sample.out sample.cor
    ```
