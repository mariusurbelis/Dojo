# Dojo
Dojo Engine. Scuffed rectangle and sprite rendering engine for **Windows** written in **C++**.

# Current Roadmap

- ~~Sprite rendering implementation~~ (Done)
- Shared textures
- ~~Entity class~~ (Done)

# Logging

Log macros defined:

- Core/Client
  - Trace
  - Info
  - Warn
  - Error
  - Critical

Usage example: DOJO_CORE_ERROR("Error message {0}", variable);

For client omit CORE_: DOJO_ERROR("Error message {0}", variable);
