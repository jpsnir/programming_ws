## Source : chatgpt

# What is ldconfig?
`ldconfig` is a Linux command-line tool used for configuring the dynamic linker runtime bindings. It is responsible for updating the shared library cache, which is used by the dynamic linker to find shared libraries when executing programs. The dynamic linker is a crucial component of the Linux operating system responsible for linking shared libraries at runtime.

When you compile and install shared libraries or create symbolic links to shared libraries manually, the changes might not be immediately reflected by the system. The `ldconfig` tool ensures that the system is aware of these changes, so that when a program runs, the dynamic linker can locate the required shared libraries without any issues.

The primary purpose of `ldconfig` is to update the shared library cache. The cache is a binary database that contains information about the shared libraries available on the system and their respective paths. It allows the dynamic linker to quickly locate shared libraries when an executable is launched, rather than searching the entire file system for each library.

`ldconfig` reads the configuration file `/etc/ld.so.conf` and the files in the `/etc/ld.so.conf.d/` directory to determine the directories where shared libraries are stored. It then updates the cached information stored in `/etc/ld.so.cache` based on the content of these files.

Here's the basic usage of `ldconfig`:

```bash
sudo ldconfig
```

By running this command with administrative privileges (using `sudo`), you force `ldconfig` to update the shared library cache, making it aware of any new or modified shared libraries.

`ldconfig` is typically used after installing new shared libraries or when you want to update the cache with the latest library changes. It is often executed as part of library installation scripts or package management systems to ensure proper functioning of dynamically linked programs on a Linux system.

# Can I use ldconfig to update libraries installed at custom locations?
No, the `ldconfig` tool will not update shared libraries in custom locations by default. By default, `ldconfig` reads the configuration file `/etc/ld.so.conf` and the files in the `/etc/ld.so.conf.d/` directory to determine the directories where shared libraries are stored. It then updates the cached information stored in `/etc/ld.so.cache` based on the content of these files.

If you have installed shared libraries in custom locations, you need to ensure that these custom locations are included in the configuration files read by `ldconfig`. There are two common ways to achieve this:

1. Modify the Configuration Files:
   You can manually add the paths of your custom library locations to the configuration files (`/etc/ld.so.conf` or files in `/etc/ld.so.conf.d/`). For example, if your custom libraries are in the directory `/usr/local/mylib`, you would add the following line to one of the configuration files:

   ```
   /usr/local/mylib
   ```

   After adding the custom location, you need to run `ldconfig` to update the cache:

   ```bash
   sudo ldconfig
   ```

   `ldconfig` will then read the updated configuration files and include the custom library location in the cache.

2. Use the LD_LIBRARY_PATH Environment Variable (Temporary Solution):
   Another way to handle custom library locations is to set the `LD_LIBRARY_PATH` environment variable to include the directories containing the shared libraries. This is a temporary solution and only affects the current session.

   For example, in the terminal, you can set the `LD_LIBRARY_PATH` variable like this:

   ```bash
   export LD_LIBRARY_PATH=/usr/local/mylib:$LD_LIBRARY_PATH
   ```

   After setting the environment variable, the dynamic linker will look for shared libraries in `/usr/local/mylib` in addition to the standard library locations during the current session.

   However, using `LD_LIBRARY_PATH` for managing shared libraries is generally not recommended for system-wide configurations, as it can lead to potential issues and conflicts. It's better to use the first approach and update the configuration files for a more consistent and permanent solution.

Remember that when modifying system configuration files or using `sudo`, exercise caution to avoid unintended changes that could affect the system's stability.
