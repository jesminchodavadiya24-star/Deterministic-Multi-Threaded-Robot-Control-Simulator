# Deterministic Multi-Threaded Robot Control Simulator

## Overview

This project simulates a deterministic real-time robot control pipeline using POSIX threads and real-time scheduling.

It demonstrates:

- Multi-threaded architecture (pthread)
- Real-time scheduling using SCHED_FIFO
- Circular buffer for sensor data pipeline
- Mutex-protected shared resources
- Worst Case Execution Time (WCET) measurement
- Zero memory leaks (Valgrind verified)
- No dynamic memory allocation inside control loop
- Clean modular architecture

---

## System Architecture

[ Sensor Thread ] 
        ↓
[ Circular Buffer ]
        ↓
[ Control Thread ]
        ↓
[ Logger / Actuator Output ]

Two deterministic threads:

1. Sensor Thread  
   - Periodic data generation  
   - Writes to circular buffer  

2. Control Thread  
   - Real-time scheduled (SCHED_FIFO)  
   - Reads sensor data  
   - Executes deterministic control logic  

---

## Deterministic Design Principles

- Fixed-size buffers
- No malloc/free inside real-time loop
- Mutex-protected shared memory
- Real-time scheduling policy
- Measured execution time per cycle

This ensures predictable execution behavior.

---

## Build Instructions

```bash
make     
