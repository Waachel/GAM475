# GAM475 - Real-Time Software Development
## Description
For GAM475, I learned about runtime library construction, abstracting low-level systems, custom data containers, memory tracking, framework development, realt-time design patterns, low-level drivers, and graphic engine development.  real-time constrained multithreaded architecture. Topics covered include multithreaded handle development, inter-thread communication, creating systems for user-defined callbacks, asynchronous loading and streaming of resources, non-blocking threading synchronization, design patterns and data driven messaging with time delivery constraints. For the final project, I created an Audio Engine that integrated the existing single and multithreaded middleware libraries.

Topics include runtime library construction, abstracting low-level
systems, custom data containers, memory tracking, framework development, real-time design patterns,
low-level drivers, graphics engine development. Design and implementation of multi-heap memory
management system with aligned allocations with cross heap tracking. Exploration of real-time data
driven messaging to allowing the run-time object data to control the behavior an application. Interface
development to create a responsive optimized access to abstract data types. Students will design,
develop and implement a real-time application (i.e. Graphics engine) that integrates multiple userdeveloped libraries with real-time constraints.

## Final Project Description: Graphics Engine
The final project includes 
* Math Library
  * Vec3 and Vec4
  * Mat3 and Mat4
  * Wrapper for Trig Class
  * Proxies for Vector Length
* File Library
  * Open/Close File
  * Read/Write File
  * Flush
  * Seek
  * Handle Based
  * Wrap Win32 File System (CreateFile(), ReadFile(), WriteFile(), CloseHandle())
  * Debugging
* Parent-Child-Sibling Tree Library
  * Create/Destroy PCS Nodes
  * Create/Destroy PCS Tree
  * Insert/Remove Nodes
  * Get the Root Node
  * Get Tree Stats
  * Get Node Data (Name, Parent Node, Child Node, Number of Siblings, and Next Sibling)
  * Print Tree and Nodes
* Memory System
  * Create/Destroy Memory System
  * Support Multiple Heaps
  * Allocate from Specific heaps
  * Allocation and block tracking (File, Line Number, Number of used Blocks, Peak Number of Used Blocks, Total size of Heap, and Heap Name)
  * Wrap Win32 Memory System (HeapCreate(), HeapDestory(), HeapAllocate(), HeapFree(), HeapReAlloc(), HeapSize())
  * Alignment (4, 8, 16, 32, 64, 128, 256)
* Graphic Engine
  * Graphics Object
    * Create/Destroy Objects
    * Transform Complex Operations into one World Matrix
    * Object controls OpenGL States
  * Camera
    * Camera Controls (adjust/set attributes, move camera, frustum calculations)
    * Support Multiple Cameras
    * Switch between Cameras
  * Textures
    * Support text on graphics objects
    * Swap textures on one object
    * Min/Max Filters and Clamping/Wrapping Mode
  * Lighting
    * Different types of lighting
    * Different lighting parameters (color, direction, etc)

## Instructions To View the Final Project
* Open MS2
* Run Engine.sln
* The following scene is rendered:
  * Camera 1:
  * Camera 2:
  * Camera 3:
  * Camera 4: 
* Use 1, 2, 3, 4 to cycle through the cameras
* Use S, W, E, D to adjust the view
* Use I and O to zoom in and out
* Use the keyboard arrow keys to look around
* Special Notes:
  * Five Shapes - Cube, Sphere, Pyramid, Diamond, and Cross - WireFrame and Solid
  * Four Shaders - Solid Colors, Blended Colors, and Various Lighting
  * Four Textures - Rocks, Bricks, Duckweed, and Stone

* Click here to view a [full walkthrough](https://youtu.be/3o6tAZnavw8) of my final project
