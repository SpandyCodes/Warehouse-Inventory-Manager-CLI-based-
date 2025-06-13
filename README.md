# 📦 Warehouse Inventory Manager (CLI-based)

A backend CLI application to manage warehouse inventory using advanced data structures:
- 🔍 **B-Tree** for efficient product indexing by ID
- 🧾 **Hashmap** for quick name-based lookup
- 📦 **Queue** for FIFO-based order processing

---

## ✅ Features
- Add/Search/Update products
- Place and process customer orders
- View order queue
- Load inventory from a text file

---

## 📁 Folder Structure
```
.
├── data/
│   └── products.txt        # Sample product dataset
├── Product.h / Product.cpp
├── BTree.h
├── OrderQueue.h / OrderQueue.cpp
├── InventoryManager.h / InventoryManager.cpp
├── main.cpp                # CLI interface
├── Makefile
└── README.md
```

---

## 🧪 Sample Data Format (data/products.txt)
```
1001 Apple, 150 0.5
1002 Banana, 120 0.3
```
Format: `ProductID Name, Quantity Price`

---

## ⚙️ Build Instructions
```bash
make            # Compiles all sources into `inventory_manager`
./inventory_manager
```

To clean compiled files:
```bash
make clean
```

---

## 🌐 Running in Browser
To run this in the browser, you can:
1. Use **replit.com** (C++ project, import all files)
2. Use **WebAssembly (Emscripten)** to compile to `.wasm` and embed in a web frontend *(advanced)*
3. Use **GitHub Codespaces** or **Gitpod** with browser-based Linux shell

---


## Created by **Spandan Jathar**
