# 808s Text Editor

A minimalist C++ text editor built from scratch with a **Piece Table** data structure for efficient text editing.  
808s_Text_Editor is designed to explore low-level text buffer manipulation, file I/O, and GUI integration with Qt6.

---

## Features

- **Custom Piece Table Engine** – Efficient insert, delete, and replace operations using dual-buffer memory management.  
- **Qt6 GUI Integration** – Real-time text rendering, input handling, and buffer visualization.  
- **Persistent File I/O** – Save and load documents while preserving edit history and buffer integrity.  
- **Modular Architecture** – Decoupled core logic, file management, and GUI layers for scalability.  
- **CMake Build System** – Cross-platform setup supporting Clang, GCC, and MSVC.

## How It Works

The editor uses the **Piece Table** technique:
- The *original buffer* holds the initial file content.
- The *add buffer* stores newly inserted text.
- A list of *pieces* references spans of text from each buffer.
- Edits only modify the piece table, not the text itself which ensures efficient updates.

